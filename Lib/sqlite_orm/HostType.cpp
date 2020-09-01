#include "sqlite_orm/HostType.h"

int HostTypeToInt(const gacpass::HostType& type)
{
	return (int)type;
}

gacpass::HostType HostTypeFromInt(const int s)
{
	return gacpass::HostType(s);
}
