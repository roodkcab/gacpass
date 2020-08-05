#include "LoginViewModel.h"

LoginViewModel::LoginViewModel() {}

WString LoginViewModel::GetPassword()
{
	return password;
}

void LoginViewModel::SetPassword(const WString& value)
{
	password = value;
}
