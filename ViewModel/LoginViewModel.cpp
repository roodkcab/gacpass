#include "LoginViewModel.h"

#include <string>
#include "cereal/archives/binary.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"
#include "util.hpp"
#include <fstream>

LoginViewModel::LoginViewModel() {}

void LoginViewModel::Load(Ptr<decltype(DB())> _storage)
{
	storage = _storage;
}

WString LoginViewModel::GetPassword()
{
	return password;
}

void LoginViewModel::SetPassword(const WString& value)
{
	password = value;
	GetLoggedIn();
}

bool LoginViewModel::GetLoggedIn()
{
	int match = storage->count<Key>(where(c(&Key::GetKey) == this->GetPassword().Buffer()));
	if (match > 0)
	{
		LoggedInChanged();
		return true;
	}
	return false;
}
