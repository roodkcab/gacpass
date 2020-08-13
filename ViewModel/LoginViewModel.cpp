#include "LoginViewModel.h"

LoginViewModel::LoginViewModel() {}

void LoginViewModel::Load(decltype(DB())& _storage)
{
	storage = &_storage;
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
