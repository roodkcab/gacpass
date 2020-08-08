#include "LoginViewModel.h"

#include <string>
#include "cereal/archives/binary.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"
#include "util.hpp"
#include <fstream>

LoginViewModel::LoginViewModel() {}

WString LoginViewModel::GetPassword()
{
	return password;
}

void LoginViewModel::SetPassword(const WString& value)
{
	password = value;
}

bool LoginViewModel::GetLoggedIn()
{
	std::ifstream os(Appdata(L"\\password.cereal").Buffer(), std::ios::binary);
	if (os.is_open())
	{
		cereal::BinaryInputArchive archive(os);
		std::wstring v;
		archive(cereal::make_nvp("password", v));
		os.close();
		return v.c_str() == this->GetPassword();
	}
	os.close();
	return false;
}
