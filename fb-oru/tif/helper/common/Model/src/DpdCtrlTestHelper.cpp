/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      DpdCtrlTestHelper.cpp
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
#include "DpdCtrlTestHelper.h"

// Add any specific includes here %%-->
#include <IDpdControl.h>
// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%



//=============================================================================================================
// SINGLETON
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<DpdCtrlTestHelper> DpdCtrlTestHelper::getInstance()
{
	static std::shared_ptr<DpdCtrlTestHelper> instance(std::make_shared<DpdCtrlTestHelper>()) ;
	return instance ;
}

//=============================================================================================================
// PUBLIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
DpdCtrlTestHelper::DpdCtrlTestHelper()
// Insert additional inheritance constructors here : %%-->

// <--%%
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
DpdCtrlTestHelper::~DpdCtrlTestHelper()
{
	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void DpdCtrlTestHelper::reset( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<IDpdControl> dpdCtrl(IDpdControl::getInterface());
	unsigned tx(static_cast<unsigned>(callList->find("tx")->toInt()));
	if (!dpdCtrl->resetDpd(tx-1))
	{
		// set an error
		returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );
		returnList->find(RtiKeyword::MESSAGE_VAR)->set("failed to reset DPD on TX" + std::to_string(tx)) ;
		return ;
	}
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void DpdCtrlTestHelper::start( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// * [INT timeout=1000ms (ms)]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<IDpdControl> dpdCtrl(IDpdControl::getInterface());
	unsigned tx(static_cast<unsigned>(callList->find("tx")->toInt()));
	unsigned timeout(static_cast<unsigned>(callList->find("timeout")->toInt()));
	if (!dpdCtrl->startDpd(tx-1, timeout))
	{
		// set an error
		returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );
		returnList->find(RtiKeyword::MESSAGE_VAR)->set("failed to start DPD on TX" + std::to_string(tx)) ;
		return ;
	}
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void DpdCtrlTestHelper::stop( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} tx
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<IDpdControl> dpdCtrl(IDpdControl::getInterface());
	unsigned tx(static_cast<unsigned>(callList->find("tx")->toInt()));
	if (!dpdCtrl->stopDpd(tx-1))
	{
		// set an error
		returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );
		returnList->find(RtiKeyword::MESSAGE_VAR)->set("failed to stop DPD on TX" + std::to_string(tx)) ;
		return ;
	}
	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%