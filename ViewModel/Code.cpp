#include "Code.h"
#include <iostream>

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

Code::Code()
	: id(-1)
	, website(L"https://")
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

Code::Code(const Code& code)
{
	id = code.id;
	website = code.website;
	username = code.username;
	password = code.password;
}

vint Code::GetId()const
{
	return id;
}

void Code::SetId(const vint _id)
{
	id = _id;
}

WString Code::GetWebsite()const
{
	return website;
}

void Code::SetWebsite(const WString& _website)
{
	website = _website;
}

WString Code::GetUsername()const
{
	return username;
}

void Code::SetUsername(const WString& _username)
{
	username = _username;
}

WString Code::GetPassword()const
{
	return password;
}

void Code::SetPassword(const WString& _password)
{
	password = _password;
}

WString Code::GetHidePassword()const
{
	return L"***";
}

void Code::Update(const vint _id, const WString& _website, const WString& _username, const WString& _password)
{
	id = _id;
	website = _website;
	username = _username;
	password = _password;
}
