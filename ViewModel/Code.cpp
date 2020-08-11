#include "Code.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

Code::Code()
	:website(L"https://")
	, username(L"")
	, password(L"")
{}

Code::Code(const int _id, const WString& _website, const WString& _username, const WString& _password)
{
	id = _id;
	website = _website;
	username = _username;
	password = _password;
}

int Code::GetId()
{
	return id;
}

void Code::SetId(const int _id)
{
	id = _id;
}

WString Code::GetWebsite()
{
	return website;
}

void Code::SetWebsite(const WString& _website)
{
	website = _website;
}

WString Code::GetUsername()
{
	return username;
}

void Code::SetUsername(const WString& _username)
{
	username = _username;
}

WString Code::GetPassword()
{
	return password;
}

void Code::SetPassword(const WString& _password)
{
	password = _password;
}

WString Code::GetHidePassword()
{
	return L"***";
}

void Code::Update(const int _id, const WString& _website, const WString& _username, const WString& _password)
{
	id = _id;
	website = _website;
	username = _username;
	password = _password;
}
