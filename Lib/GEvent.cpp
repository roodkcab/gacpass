#include "GEvent.h"

Value GEvent::GetData()
{
	return data;
}

void GEvent::SetData(const Value& _data)
{
	data = _data;
}
