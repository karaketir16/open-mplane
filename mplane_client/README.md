# mplane_client
mplane_client implements the client portion of the O-RAN M-Plane specification
(see O-RAN WG4 M-Plane).

mplane_client provides the software that encapsulates a NETCONF client and a RPC
server. Communication with radio units (RUs) occurs over NETCONF. mplane_client
can be used in hierarchical topologies where it is run on only an O-DU to manage
on O-RU as well as in hybrid topologies where it can run on other devices like
in a Network Management System (NMS).

Currently, users must implement a RPC client that can interface with the
mplane_client. A test RPC client is provided.

## Building
The build process follows these fundamental steps:
1. Start in `mplane_client/` directory
2. Source code dependencies (libssh, libyang, libnetconf2, gRPC and its
   dependencies, gflags, gtest, and glog) are downloaded to `deps/`
3. Source code dependencies are built and installed in `deps/install/`; this
   directory contains `bin`, `lib`, etc.
4. mplane_client itself is built in `build/`

See the "Build Script Guide" section in [IMPLEMENTATION.md](IMPLEMENTATION.md)
for more details on how this process works.

### Building with Docker
```bash
$ cd mplane_client/utils/
$ ./build_docker.sh
$ docker-compose up
```

**Option 1** (no image rebuild needed after modifications to `src/`):
```bash
$ docker exec -it mpclient_mpclient-tester_1 /bin/bash
$ ./build_mpclient.sh
```

**Option 2** (image rebuild needed after modifications to `src/`):
```bash
$ docker exec -it mpclient_mpclient-built-tests /bin/bash
```

### Building on CentOS 8
```bash
$ cd mplane_client/utils/
$ ./get_deps.sh
$ ./build_deps.sh
$ ./build_mpclient.sh
```

To build on an airgapped machine, run `./get_deps.sh --dnf-deps` on a host with
network connectivity and manually copy the entire `mplane_client` directory onto
the build host, which can then skip the dependency fetching step.

## Usage
First, start the server (`mpc_client`):
```bash
$ cd mplane_client/build
$ ./wrapper.sh ./mpc_client  # args
```

Separately, run a client (`mpc_tester` or `mpclient-demo`):
```bash
$ cd mplane_client/build
$ ./wrapper.sh ./mpc_tester  # args
$ ./wrapper.sh ./mpclient-demo  # args
```

Note that `wrapper.sh` is a brief script which loads variables, like the
locations of the library dependencies and libyang shared library objects, into
the environment.

### Configuration Options
`mpc_client` has flags called `--host` and `--port`, and `mpc_tester` has flags
called `--serverHost` and `--serverPort`, which define the channel through which
the server and client processes communicate over gRPC. By default, these are
`localhost` and 50051.

`mpc_tester` also has flags called `--netconfHost`, `--netconfPort`,
`--netconfCallhomeHost`, `--netconfCallhomePort`, `--netconfPassword`,
`--netconfPublicKeyPath`, and `--netconfPrivateKeyPath` which tell the
encapsulated NETCONF client in `mpc_client` how to connect to the NETCONF
server.

### gRPC TLS Encryption
It is extremely important to prevent attacks over the gRPC channel. To this end,
gRPC is encrypted with TLS. The `mpclient-built-tests` image supplies
certificates in the locations that match the default flags, but otherwise, these
must be generated by the user. Look in `test/docker/test.Dockerfile` for
guidance on how to do this.

Both keys must be kept secret. Otherwise, the encryption falls apart.

Use the `--certPath` flag to tell the gRPC client and gRPC server where the
public key is located, and use the `--privateKeyPath` flag to tell the gRPC
server where the private key is.

For testing, `mpc_client` can be run in an insecure mode where keys are omitted
by passing the `--insecure` flag.

### Running `mpc_tester`
`mpc_tester` is the unit testing program. The default NETCONF connection
parameters (e.g. `--netconfHost`, etc.) will work with the Docker environment.
All unit tests except for those exercising public key authentication should work
as-is. In order to verify public-key authentication, first set up
`~/.ssh/authorized_keys`:
```
$ cat /home/netconf/.ssh/melacon.server.key.pub > /home/netconf/.ssh/authorized_keys
```

### Running `mpclient-demo`
Refer to [example/README.md](example/README.md).

## RPCs and Data Structures
Data structures are codified in `src/if/mpclient.proto`. Each mplane_client RPC
named `<X>` has an input of `<X>Request` and an output of `<X>Response`.

**Session IDs**: mplane_client multiplexes over multiple NETCONF sessions (so it
can participate in multiple M-Planes). Therefore, to distinguish between target
M-Planes, each mpclient RPC is associated with a session ID. The `connect` and
`listen` commands produce session IDs, and all the other commands consume a
session ID.

**Authentication**: `connect` and `listen` both require authentication.
Authentication can be done with either public keys or passwords. A connection
will be established if at least one is supplied and correct. For a one-off
connection, a password may be easiest. However, public keys are almost required
in `listen` because there can be an arbitrary number of public keys, but only
one password.

Here are specific details on each command:
* `connect`: use this when the location (i.e. hostname and port) of the NETCONF
  server are known. This returns a single session ID if the connection was
  successful. If not, the connection or authentication parameters are incorrect.
* `listen`: use this when RUs are supposed to "call home". It listens on a
  location (where RUs must be configured to call home), and sends a response
  whenever a new call home connection is established. The timeout works the
  [same way as NETCONF](https://netopeer.liberouter.org/doc/libnetconf2/devel/html/group__client__ch.html#ga362a3d33b28333a01572cdde151e48b6)
  (>0 will cause the command to exit if the timeout has elapsed without a new
  connection, -1 is indefinite timeout), but 0 should never be used. Whenever a
  new connection is established, the timeout resets.
* `disconnect`: use this to destroy the session. This command stops notification
  streaming and any processes on mpclient (like the supervision loop) that rely
  on notifications.
* `netconfRpc`: use this to call an arbitrary, generic NETCONF RPC on the
  session. All M-Plane operations are done through NETCONF RPCs, so there is no
  need for further specialization or additional methods. The NETCONF RPC must be
  serialized in XML and follow a YANG schema. It adds the `<rpc>` wrapper, but
  nothing else. For example, doing the NETCONF `<get>` operation requires a
  `<get xmlns="urn:ietf:params:xml:ns:netconf:base:1.0">` wrapper containing the
  normal parameters. The timeout does not matter very much. This command can
  return in several ways:
    * `status == INVALID_SESSION`: the session ID was not associated with an
      active session, so nothing happened.
    * `status == TIMEOUT`: the timeout during which the NETCONF client and
      server were supposed to communicate elapsed, so the status of the NETCONF
      RPC is unknown.
    * `status == ERROR`: there was an error on the NETCONF client or server that
      prevented a result for the NETCONF RPC from being obtained.
    * `status == SUCCESS`: a result for the NETCONF RPC was obtained, and
      `returntype` has a value.
        * `returntype == OK`: the NETCONF RPC returned `<ok/>`. There is no data
          in `message`.
        * `returntype == DATA`: the NETCONF RPC was successful, returning data
          which follows a YANG schema and is serialized as XML. The data is
          contained in `message`.
        * `returntype == RPC_ERROR`: the NETCONF RPC completed with an error,
          returning data serialized as XML which complies with `<rpc-error>` in
          [RFC 6241](https://datatracker.ietf.org/doc/html/rfc6241#page-16). The
          data is contained in `message`.
* `streamNotifications`: use this to initiate a stream containing all NETCONF
  notifications generated by the session (this does not filter by namespace,
  channel, etc.). All M-Plane operations use NETCONF notifications to signal
  asynchronous events. **NOTE**: in order to actually initiate a notifications
  stream, a `<create-subscription>`  NETCONF RPC must be issued via
  `netconfRpc`.

## Implementation
Refer to [IMPLEMENTATION.md](IMPLEMENTATION.md).