#include "Key.h"
#include <iostream>

Key::Key()
	: id(-1)
	, key(L"")
{}

Key::Key(const int _id, const WString& _key)
{
	id = _id;
	key = _key;
}

Key::Key(const Key& key)
{
	id = key.id;
	this->key = key.key;
}

int Key::GetId()const
{
	return id;
}

void Key::SetId(const int _id)
{
	id = _id;
}

WString Key::GetKey()const
{
	return key;
}

void Key::SetKey(const WString& _key)
{
	key = _key;
}
