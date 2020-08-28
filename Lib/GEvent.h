#pragma once

#include "GacPass.h"

using namespace vl;
using namespace vl::reflection::description;

class GEvent : public EventObject
{
private:
	Value data;

public:
	Value GetData();
	void SetData(const Value& data);
};
