/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      Zcu111FbcOranrrhOranFpgaTestHandler.h
 * \brief     Test methods for ZCU111-FBC-ORANRRH
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __ZCU111FBCORANRRHORANFPGATESTHANDLER__H_
#define __ZCU111FBCORANRRHORANFPGATESTHANDLER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "OranFpgaTestHelper.h"
#include "ITif.h"
#include "IRtiMsgParser.h"
#include "Nodes/EntryFunc.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class Zcu111FbcOranrrhOranFpgaTestHandler: public virtual ITifEntry, public EntryFunc
{
public:

	Zcu111FbcOranrrhOranFpgaTestHandler( const std::string& pathname, const std::string& comment,
    		const std::string& callFields, const std::string& returnFields,
    		IRtiMsgParser& msgParser, IRtiSettings& settings);

    virtual ~Zcu111FbcOranrrhOranFpgaTestHandler();

    static void registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings) ;

	/**
	 * Special constructor - only to be used for calling the static registerMethods()
	 */
	Zcu111FbcOranrrhOranFpgaTestHandler();

	/**
	 * Called by ITif::inject() to get this object to add it's entries
	 * @param tif
	 * @return true if ok
	 */
	virtual bool registerEntry(ITif* tif) override ;

protected:

    virtual std::string operator()(const std::string& functionName) ;

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *   STRING mac
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void dstMac( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   STRING mac
	 *
	 */
	void getDstMac( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT{0..1048575} id
	 *
	 */
	void getRtcId( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   STRING mac
	 *
	 */
	void getSrcMac( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT{0..65535} tag
	 *
	 */
	void getUplaneTag( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   BOOL enable
	 *
	 */
	void getVlanEnable( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *   UINT{0..1048575} id
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void rtcId( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *   STRING mac
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void srcMac( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *   UINT{0..65535} tag
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void uplaneTag( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{0..65535} index
	 *   BOOL enable
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void vlanEnable( DataVariantList *callList, DataVariantList *returnList );






// Add any extra methods %%-->

// <--%%

private:
	std::shared_ptr<OranFpgaTestHelper> mHelper ;
};



} // Mplane

#endif /* __ZCU111FBCORANRRHORANFPGATESTHANDLER__H_*/