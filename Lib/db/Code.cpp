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
	this->IdChanged();
}

WString Code::GetTitle()const
{
	return title;
}

void Code::SetTitle(const WString& _title)
{
	title = _title;
	this->TitleChanged();
}

WString Code::GetUsername()const
{
	return username;
}

void Code::SetUsername(const WString& _username)
{
	username = _username;
	this->UsernameChanged();
}

WString Code::GetPassword()const
{
	return password;
}

void Code::SetPassword(const WString& _password)
{
	password = _password;
	this->PasswordChanged();
}

WString Code::GetHidePassword()
{
	return L"***";
}

Ptr<vl::reflection::description::IValueObservableList> Code::GetReferences()
{
	auto list = references.GetWrapper();
	if (references.Count() == 0)
	{ 
		auto results = DB.get_all<Reference>(where(c(&Reference::GetCodeId) == this->GetId()));
		for (auto& result : results)
		{
			references.Add(MakePtr<Reference>(result));
		}
	}
	return list;
}

void Code::Update(Ptr<ICode> code)
{
	if (code)
	{
		this->SetId(code->GetId());
		this->SetTitle(code->GetTitle());
		this->SetUsername(code->GetUsername());
		this->SetPassword(code->GetPassword());

		references.Clear();
		auto l = GetLazyList<Ptr<Reference>>(code->GetReferences()).CreateEnumerator();
		while (l->Next())
		{
			references.Add(MakePtr<Reference>(*(l->Current().Obj())));
		}
	}
}

void Code::AddReference()
{
	references.Add(MakePtr<Reference>());
}
