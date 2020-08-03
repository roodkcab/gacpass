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

WString Code::GetWebsite()
{
	return website;
}

WString Code::GetUsername()
{
	return username;
}

WString Code::GetPassword()
{
	return password;
}

void Code::Update(Ptr<gacpass::ICodeBookViewModel> _viewmodel, const WString& _website, const WString& _username, const WString& _password)
{
	website = _website;
	username = _username;
	password = _password;

	//save view model to file;
	_viewmodel->NotifyUpdate(this);
}
