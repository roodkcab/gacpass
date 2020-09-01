#include "Code.h"
#include "DB.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

Code::Code()
	: id(-1)
	, title(L"")
	, username(L"")
	, password(L"")
{
}

/*Code::Code(const int _id, const WString& _title, const WString& _username, const WString& _password)
{
	id = _id;
	title = _title;
	username = _username;
	password = _password;
}*/

Code::Code(const Code& code)
{
	id = code.id;
	title = code.title;
	username = code.username;
	password = code.password;
}

int Code::GetId()const
{
	return id;
}

void Code::SetId(int _id)
{
	id = _id;
}

WString Code::GetTitle()const
{
	return title;
}

void Code::SetTitle(const WString& _title)
{
	title = _title;
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

WString Code::GetHidePassword()
{
	return L"***";
}

Ptr<vl::reflection::description::IValueObservableList> Code::GetReferences()
{
	if (references.Count() == 0)
	{ 
		auto results = DB.get_all<Reference>(where(c(&Reference::GetCodeId) == this->GetId()));
		for (auto& result : results)
		{
			references.Add(MakePtr<Reference>(result));
		}
	}
	return references.GetWrapper();
}

void Code::Update(Ptr<ICode> code)
{
	id = code->GetId();
	title = code->GetTitle();
	username = code->GetUsername();
	password = code->GetPassword();
	references.Clear();
	auto r = code->GetReferences()->CreateEnumerator();
	while (r->Next())
	{
		auto cr = MakePtr<Reference>();
		cr->Update(vl::__vwsn::Unbox<Ptr<Reference>>(r->GetCurrent()));
		references.Add(cr);
	}
}

void Code::AddReference()
{
	auto r = MakePtr<Reference>();
	r->SetCodeId(this->GetId());
	references.Add(r);
}
