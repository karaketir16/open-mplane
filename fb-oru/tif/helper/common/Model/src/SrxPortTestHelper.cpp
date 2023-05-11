/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      SrxPortTestHelper.cpp
 * \brief     Test helper for common
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run)
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include "RtiKeyword.h"
#include "SrxPortTestHelper.h"

// Add any specific includes here %%-->
#include <string>
#include <sstream>
#include <typeinfo>
#include "ITifIoctl.h"
#include "IRadio.h"
#include "ISRxPort.h"

#include "GlobalTypeDefs.h"

#include "ISRxPort.h"

#include "IFpgaMgr.h"

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->
using namespace std;



// <--%%



//=============================================================================================================
// SINGLETON
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<SrxPortTestHelper> SrxPortTestHelper::getInstance()
{
	static std::shared_ptr<SrxPortTestHelper> instance(std::make_shared<SrxPortTestHelper>()) ;
	return instance ;
}

//=============================================================================================================
// PUBLIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
SrxPortTestHelper::SrxPortTestHelper()
// Insert additional inheritance constructors here : %%-->

// <--%%
{
	// Insert your code here : %%-->


	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
SrxPortTestHelper::~SrxPortTestHelper()
{
	// Insert your code here : %%-->


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getAdcRms( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    Power power(0.0);

    if( srxPort.get() )
    {
        power = srxPort->getRawAdcRms();
    }

    returnList->find("value")->set(power.get());


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getAtten( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dB)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    Power attenuation(0.0f);

    if( srxPort.get() )
    {
        attenuation = srxPort->getAttenuation();
    }

    returnList->find("value")->set( attenuation.get());

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getCorrection( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    // Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    Power power(0.0);

    if( srxPort.get() )
    {
        power = srxPort->getCorrection();
    }

    returnList->find("value")->set(power.get());

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getFreq( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (kHz)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if( srxPort.get() )
    {
        Frequency freq = srxPort->getFrequency();
        DataVariant* value(returnList->find("value")) ;
        value->set( (float)freq.getDbl( Frequency::str2unit(value->getUnits()) ) ) ;
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getFwdPathAdcRms( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_FORWARD );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getRawAdcRms();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getFwdPathCorrection( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_FORWARD );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getCorrection();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getFwdPathPower( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_FORWARD );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getPower();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getFwdTssi( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT tssiResult (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(callList, returnList);

    if(!srxPort)
    	return ;

    Power rf(0.0);
    Power tssi(0.0);

    int path(callList->find("path")->toInt() -1);
    ReturnType::State result = srxPort->getFwdPower(path, rf, tssi);
    returnList->find("tssiResult")->set(tssi.get());
    checkState(result, "tssiResult", returnList);
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getPath( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if( srxPort.get() )
    {
        int channel = srxPort->getPath();
        DataVariant* value(returnList->find("channel")) ;
        value->set( channel+1 ) ;
    }


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getPower( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    Power power(0.0);

    if( srxPort.get() )
    {
        power = srxPort->getPower();
    }

    returnList->find("value")->set(power.get());


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getRevPathAdcRms( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_REVERSE );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getRawAdcRms();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getRevPathCorrection( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_REVERSE );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getCorrection();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getRevPathPower( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if(!srxPort)
    	return ;

    int path(callList->find("path")->toInt() -1);

    Power power(0.0);
    ReturnType::State ret = srxPort->setPath( path );

    if (ret == ReturnType::RT_OK)
    {
    	ret = srxPort->setDirection( ISRxPort::Direction::SRX_DIR_REVERSE );

		if( ret == ReturnType::RT_OK )
		{
			power = srxPort->getPower();
			returnList->find("value")->set(power.get());
		}
		else
		{
			checkState(ret, "direction", returnList);
		}
    }
    else
    {
    	checkState(ret, "path", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getRevTssi( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT tssiResult (dBm)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(callList, returnList);

    if(!srxPort)
    	return ;

    Power rf(0.0);
    Power tssi(0.0);

    int path(callList->find("path")->toInt() -1) ;
    ReturnType::State result = srxPort->getRevPower(path, rf, tssi);
    returnList->find("tssiResult")->set(tssi.get());
    checkState(result, "tssiResult", returnList);
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::getTemp( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT result (DegC)
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    float temperature = 0.0;

    if( srxPort.get() )
    {
        temperature = srxPort->getTemperature();
    }

    returnList->find("result")->set(temperature);


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::setAtten( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * FLOAT value (dB)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(callList, returnList);

    ReturnType::State result = ReturnType::RT_ERROR ;

    if( srxPort.get() )
    {
        Power attenuation(callList->find("value")->toFloat()  );

        result = srxPort->setAttenuation( attenuation );
    }

    checkState(result, "value", returnList);

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::setDirection( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * ENUM(forward:reverse) direction
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    ReturnType::State ret = ReturnType::RT_ERROR;

    // To support more than 1 DPD we also need to be looking for the index.
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if( srxPort.get() )
    {

        // Retrieve the direction
        std::string dir = callList->find("direction")->toString() ;

        ret = srxPort->setDirection( (dir == "forward" ? ISRxPort::Direction::SRX_DIR_FORWARD : ISRxPort::Direction::SRX_DIR_REVERSE) );


        // Check to see if the return value is anything other than RT_OK. This will
        // provide error feedback or just return a value result of 0 if everything is
        // ok.
        checkState(ret, "direction", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::setFreq( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * FLOAT value (kHz)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if( srxPort.get() )
    {
        ReturnType::State ret = ReturnType::RT_OK ;

        // * [FLOAT NCOFreq]
        DataVariant* value(callList->find("value")) ;
        if (value->isSet())
        {
            ret = srxPort->setFrequency(Frequency(value->toFloat(), Frequency::str2unit(value->getUnits()))) ;

            if (!checkState(ret, "value", returnList))
                return ;
        }

    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::setPath( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    // This TIF command is specific to the test instrumentation and does not
    // need to be implemented in the main radio code.
    ReturnType::State ret = ReturnType::RT_ERROR;

    // To support more than 1 DPD we also need to be looking for the index.
    std::shared_ptr<ISRxPort> srxPort = getPort(   callList, returnList );

    if( srxPort.get() )
    {

        // Retrieve the channel value and change to a zero based index
        UINT16 rxChannel = callList->find("channel")->toInt() ;

        rxChannel--; // Change to zero based channel

        ret = srxPort->setPath( rxChannel );


        // Check to see if the return value is anything other than RT_OK. This will
        // provide error feedback or just return a value result of 0 if everything is
        // ok.
        checkState(ret, "channel", returnList);
    }

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::showSynth( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->

	int srxIndex = callList->find("index")->toInt() ;
	srxIndex--; // called by port number, change to zero based index

    std::shared_ptr<IRadio>radio( IRadioFactory::getInterface() );
    IDevices& devices( radio->getDevices() ) ;
    std::shared_ptr<ISynth> srxSynth( devices.getDpdSynth( srxIndex ) ) ;

	std::stringstream ss ;
	ss << std::endl ;
	srxSynth->show(ss) ;
	returnList->find(RtiKeyword::INFO_VAR)->set(ss.str()) ;

	// <--%%
}




//-------------------------------------------------------------------------------------------------------------
void SrxPortTestHelper::PortsGet( const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/srx/Ports"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//


	// Insert your code here : %%-->
    std::vector< std::shared_ptr<ISRxPort> > srxPorts = ISRxPortFactory::getPorts( ) ;
    returnList->find(pathname)->set( static_cast<int>(srxPorts.size()) ) ;

	// <--%%
}








// Add any statics, private methods etc here %%-->

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<ISRxPort> SrxPortTestHelper::getPort(DataVariantList *callList, DataVariantList *returnList) const
{
    std::vector< std::shared_ptr<ISRxPort> > srxPorts = ISRxPortFactory::getPorts( ) ;
    int index( callList->find("index")->toInt() ) ;
    index--;  // change 1 based port to zero based index

    if( index < 0 || index >= (int)srxPorts.size() )
    {
        returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );

        std::stringstream ss ;
        ss << "index " << index+1 << " outside valid range (Number of ports "
                << srxPorts.size() << ")" ;
        returnList->find(RtiKeyword::MESSAGE_VAR)->set(ss.str()) ;

        return std::shared_ptr<ISRxPort>();
    }
    return srxPorts[index] ;
}

//-------------------------------------------------------------------------------------------------------------
bool SrxPortTestHelper::checkState(ReturnType::State ret, const std::string& param, DataVariantList *returnList) const
{
    if (ret != ReturnType::RT_OK)
    {
        // set an error
        returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );

        std::stringstream ss ;
        ss << "Unable to set " << param << " : ERROR" << ReturnType::getState(ret) ;
        returnList->find(RtiKeyword::MESSAGE_VAR)->set(ss.str()) ;

        return false ;
    }

    return true ;
}

// <--%%