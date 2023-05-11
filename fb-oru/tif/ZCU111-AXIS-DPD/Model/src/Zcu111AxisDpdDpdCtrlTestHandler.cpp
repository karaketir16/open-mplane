/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      Zcu111AxisDpdDpdCtrlTestHandler.cpp
 * \brief     Test methods for ZCU111-AXIS-DPD
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run)
 *
 * Add any file header comments here %%-->

 * <--%%
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include "Nodes/RtiDirEntry.h"
#include "Nodes/TestVar.h"
#include "Nodes/TestReadVar.h"
#include "Nodes/TestWriteVar.h"
#include "Nodes/DirClass.h"
#include "RtiKeyword.h"
#include "Zcu111AxisDpdDpdCtrlTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void Zcu111AxisDpdDpdCtrlTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/dpdctrl", "DPD control functions", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new Zcu111AxisDpdDpdCtrlTestHandler("/dpdctrl/reset",
			"INT{1..${NUM_TX_PORTS}} tx",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"this resets both the DPD filter to unity and the DPD control state machine for a particular TX path",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Zcu111AxisDpdDpdCtrlTestHandler("/dpdctrl/start",
			"INT{1..${NUM_TX_PORTS}} tx,[INT timeout=1000ms (ms)]",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"start running DPD iterations on a particular TX path",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Zcu111AxisDpdDpdCtrlTestHandler("/dpdctrl/stop",
			"INT{1..${NUM_TX_PORTS}} tx",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"stops the DPD iterations on a particular TX path",
			msgParser, settings))
	);





}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
Zcu111AxisDpdDpdCtrlTestHandler::Zcu111AxisDpdDpdCtrlTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(DpdCtrlTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
Zcu111AxisDpdDpdCtrlTestHandler::Zcu111AxisDpdDpdCtrlTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(DpdCtrlTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
Zcu111AxisDpdDpdCtrlTestHandler::~Zcu111AxisDpdDpdCtrlTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool Zcu111AxisDpdDpdCtrlTestHandler::registerEntry(ITif* tif)
{
	// Convert ITif object into it's expected subclasses
	IRtiMsgParser* msgParser(dynamic_cast<IRtiMsgParser*>(tif)) ;
	IRtiSettings* settings(dynamic_cast<IRtiSettings*>(tif)) ;
	if (!msgParser)
		return false ;
	if (!settings)
		return false ;

	// now call this object's registerMethods() method to do the actual work
	registerMethods(*msgParser, *settings) ;
	return true ;
}


//-------------------------------------------------------------------------------------------------------------
std::string Zcu111AxisDpdDpdCtrlTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "reset")
    {
        reset( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "start")
    {
        start( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "stop")
    {
        stop( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void Zcu111AxisDpdDpdCtrlTestHandler::reset(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->reset( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Zcu111AxisDpdDpdCtrlTestHandler::start(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// * [INT timeout=1000ms (ms)]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->start( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Zcu111AxisDpdDpdCtrlTestHandler::stop(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->stop( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%