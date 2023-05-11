/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      CommonModelImagesTestHandler.h
 * \brief     Test methods for common-model
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __COMMONMODELIMAGESTESTHANDLER__H_
#define __COMMONMODELIMAGESTESTHANDLER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "ImagesTestHelper.h"
#include "ITif.h"
#include "IRtiMsgParser.h"
#include "Nodes/EntryFunc.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class CommonModelImagesTestHandler: public virtual ITifEntry, public EntryFunc
{
public:

	CommonModelImagesTestHandler( const std::string& pathname, const std::string& comment,
    		const std::string& callFields, const std::string& returnFields,
    		IRtiMsgParser& msgParser, IRtiSettings& settings);

    virtual ~CommonModelImagesTestHandler();

    static void registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings) ;

	/**
	 * Special constructor - only to be used for calling the static registerMethods()
	 */
	CommonModelImagesTestHandler();

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
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void clean( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   STRING version
	 *   STRING build
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void install( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   STRING filename
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void installFile( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   BOOL done
	 *   BOOL fail
	 *   INT totalProgress (%)
	 *   STRING file
	 *   STRING op
	 *   INT fileProgress (%)
	 *   STRING error
	 *
	 */
	void installStatus( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT tcp
	 *   INT size
	 *   [INT timeout=60]
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void installTcp( DataVariantList *callList, DataVariantList *returnList );

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
	void show( DataVariantList *callList, DataVariantList *returnList );

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
	void showDetail( DataVariantList *callList, DataVariantList *returnList );


	/**
	 * Setter method for variable autoCleanThreshold
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param value DataVariant value
	 * @param returnList DataVariantList use to return variable value
	 * @return true if variable set; false if unable to set variable
	 *
	 */
	static bool autoCleanThresholdSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList ) ;

	/**
	 * Getter method for variable autoCleanThreshold
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param returnList DataVariantList use to return variable value
	 *
	 */
	static void autoCleanThresholdGet(  const std::string& pathname, DataVariantList *returnList ) ;

	/**
	 * Setter method for variable uboot
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param value DataVariant value
	 * @param returnList DataVariantList use to return variable value
	 * @return true if variable set; false if unable to set variable
	 *
	 */
	static bool ubootSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList ) ;

	/**
	 * Getter method for variable uboot
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param returnList DataVariantList use to return variable value
	 *
	 */
	static void ubootGet(  const std::string& pathname, DataVariantList *returnList ) ;

	/**
	 * Setter method for variable url
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param value DataVariant value
	 * @param returnList DataVariantList use to return variable value
	 * @return true if variable set; false if unable to set variable
	 *
	 */
	static bool urlSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList ) ;

	/**
	 * Getter method for variable url
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param returnList DataVariantList use to return variable value
	 *
	 */
	static void urlGet(  const std::string& pathname, DataVariantList *returnList ) ;


	/**
	 * Getter method for read-only variable bank
	 *
	 * @param pathname Variable path name used as the variable name in the returnList
	 * @param returnList DataVariantList use to return variable value
	 *
	 */
	static void bankGet(  const std::string& pathname, DataVariantList *returnList ) ;




// Add any extra methods %%-->

// <--%%

private:
	std::shared_ptr<ImagesTestHelper> mHelper ;
};



} // Mplane

#endif /* __COMMONMODELIMAGESTESTHANDLER__H_*/