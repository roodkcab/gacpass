#pragma once
#include "GacPass.h"
#include "GEvent.h"

using namespace vl;
using namespace vl::collections;
using namespace vl::reflection::description;

class EventBus
{
public:
	enum class EventName
	{
		IStream,
		OStream,
		WebsiteOpened,
	};

	EventBus();
	Ptr<Dictionary<EventName, Ptr<GEvent>>> GetEvents();
	static Ptr<GEvent> Get(EventName name);

private:
	Ptr<Dictionary<EventName, Ptr<GEvent>>> events;
	//static CriticalSection lock;

	static Ptr<EventBus> Instance();
};
