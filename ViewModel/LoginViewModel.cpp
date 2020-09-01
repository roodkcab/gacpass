#include "LoginViewModel.h"
#include "EventBus.h"

LoginViewModel::LoginViewModel() {}

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
	int match = DB.count<Key>(where(c(&Key::GetKey) == this->GetPassword().Buffer()));
	if (match > 0)
	{
		LoggedInChanged();
		return true;
	}
	return false;
}
