/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      AtlasMplaneOranrrhFibreTestHandler.cpp
 * \brief     Test methods for Atlas-MPLANE-ORANRRH
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
#include "AtlasMplaneOranrrhFibreTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhFibreTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/fibre", "Fibre interface functions", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhFibreTestHandler("/fibre/getTemp",
			"INT{0..${MAX_FIBRE}} Index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT temp (DegC)",
			"Get SFP temperature",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhFibreTestHandler("/fibre/sfpDump",
			"INT{0..${MAX_FIBRE}} Index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],BOOL(NO:YES) sfpFitted,BOOL(NO:YES) a0Present,BOOL(NO:YES) a2Present,HEXINT[] A0,HEXINT[] A2",
			"Get raw sfp data",
			msgParser, settings))
	);





}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhFibreTestHandler::AtlasMplaneOranrrhFibreTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(FibreTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhFibreTestHandler::AtlasMplaneOranrrhFibreTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(FibreTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhFibreTestHandler::~AtlasMplaneOranrrhFibreTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhFibreTestHandler::registerEntry(ITif* tif)
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
std::string AtlasMplaneOranrrhFibreTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getTemp")
    {
        getTemp( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "sfpDump")
    {
        sfpDump( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhFibreTestHandler::getTemp(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{0..${MAX_FIBRE}} Index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT temp (DegC)
	//
	mHelper->getTemp( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhFibreTestHandler::sfpDump(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{0..${MAX_FIBRE}} Index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * BOOL(NO:YES) sfpFitted
	// * BOOL(NO:YES) a0Present
	// * BOOL(NO:YES) a2Present
	// * HEXINT[] A0
	// * HEXINT[] A2
	//
	mHelper->sfpDump( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%