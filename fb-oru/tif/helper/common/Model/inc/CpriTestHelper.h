/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      CpriTestHelper.h
 * \brief     Test helper for common
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __CPRITESTHELPER__H_
#define __CPRITESTHELPER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "IRtiMsgParser.h"
#include "DataVariant.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class CpriTestHelper
// Add any extra inheritance %%-->

// <--%%
{
public:

	// Add any class settings %%-->

	// <--%%

	// singleton
	static std::shared_ptr<CpriTestHelper> getInstance() ;


	CpriTestHelper();

    virtual ~CpriTestHelper();

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   INT Index
	 *   INT sfpLineRate (Mbps)
	 *   BOOL(NO:YES) sfpFitted
	 *   STRING sfpVendor
	 *   STRING sfpPart
	 *   FLOAT sfpRxPower
	 *   FLOAT sfpTxPower
	 *   STRING lineRate
	 *   BOOL(NO:YES) los
	 *   BOOL(NO:YES) lof
	 *   ENUM(RESET:ATTEMPTING_L1_SYNCH:PROTOCOL_VERSION_SETUP:CM_PARAM_SETUP:PASSIVE_MODE:OPERATIONAL) state
	 *   INT prefEtherPtr
	 *   INT currEtherPtr
	 *   BOOL(NO:YES) active
	 *   BOOL(NO:YES) sapDefect
	 *   BOOL(NO:YES) remoteAlarm
	 *   BOOL(NO:YES) remoteLOS
	 *   BOOL(NO:YES) remoteLOF
	 *   BOOL(NO:YES) pllLock
	 *   BOOL(NO:YES) txClockLock
	 *   BOOL(NO:YES) rxClockLock
	 *   ENUM(SLAVE:MASTER) mode
	 *   BOOL(NO:YES) coreInReset
	 *
	 */
	void get( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   INT bitwidth
	 *
	 */
	void getRxBitWidth( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   INT bitwidth
	 *
	 */
	void getTxBitWidth( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   INT waitSamples
	 *
	 */
	void getWaitSamples( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void reset( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void restart( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *   ENUM(AUTO:614.4:1228.8:2457.6:3072.0:4915.2:6144.0:9830.4:10137.6) lineRate (Mbps)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void set( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *   ENUM(AUTO:1:2:3:4:5:6:7:8) rate
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setRate( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *   INT{12..16} bitwidth
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setRxBitWidth( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *   INT{12..16} bitwidth
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setTxBitWidth( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *   INT{0..15} waitSamples
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setWaitSamples( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void showAll( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void showCtl( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void showPort( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );



	/**
	 * Getter method for read-only variable NumPorts
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param returnList DataVariantList use to return variable value
	 *
	 */
	static void NumPortsGet( const std::string& pathname, DataVariantList *returnList ) ;




// Add any extra methods %%-->

// <--%%

};



// Add any Mplane namespace code here %%-->

// <--%%


} // Mplane

// Add any global namespace code here %%-->

// <--%%


#endif /* __CPRITESTHELPER__H_*/