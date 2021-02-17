#pragma once

#include "GacPass.h"

using namespace vl;

class Google2FA
{
public:
	static int getKey(const WString& key);
};
