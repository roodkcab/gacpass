#include "EventBus.h"

EventBus::EventBus()
	: events(new Dictionary<EventName, Ptr<GEvent>>())
{
}

Ptr<EventBus> EventBus::Instance()
{
	static Ptr<EventBus> bus = MakePtr<EventBus>();
	return bus;
}

Ptr<Dictionary<EventBus::EventName, Ptr<GEvent>>> EventBus::GetEvents()
{
	return events;
}

Ptr<GEvent> EventBus::Get(EventName name)
{
	/*CS_LOCK(lock)
	{*/
		Ptr<EventBus> _bus = EventBus::Instance();
		
		if (!_bus->GetEvents()->Keys().Contains(name))
		{
			auto event = MakePtr<GEvent>();
			_bus->GetEvents()->Add(name, event);
			event->CreateAutoUnsignal(false);
			return event;
		}
		else 
		{
			auto event = _bus->GetEvents()->Get(name);;
			event->CreateAutoUnsignal(false);
			return event;
		}
	//}
}
