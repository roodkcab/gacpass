#pragma once
#include "GacPass.h"
#include <string>
#include <iostream>

using namespace vl;
using namespace vl::reflection::description;

class ChromeHandler : public ICoroutine
{
private:
	WString input;

	::vl::vint state = 2;
	::vl::vint state_before_pause = 0;
	::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_prop_Failure;
	::vl::reflection::description::CoroutineStatus status = static_cast<::vl::reflection::description::CoroutineStatus>(0);

public:
	ChromeHandler(WString input);
	void Resume(bool raiseException, Ptr<CoroutineResult> output);
	Ptr<IValueException> GetFailure();
	void SetStatus(CoroutineStatus _status);
	CoroutineStatus	GetStatus();
};
