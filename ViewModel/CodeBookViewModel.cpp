#include "CodeBookViewModel.h"
#include "EditCodeViewModel.h"
#include "EventBus.h"
#include "VlppRegex.h"

using namespace vl::regex;

CodeBookViewModel::CodeBookViewModel(Ptr<gacpass::ILoginViewModel> _loginViewModel) 
	: loginViewModel(_loginViewModel)
	, editCodeViewModel(MakePtr<EditCodeViewModel>())
{
}

void CodeBookViewModel::Load()
{
	auto codes = DB.get_all<Code>(order_by(&Code::GetTitle));
	for (auto &code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}

	GetApplication()->InvokeAsync([this] {
		while (true)
		{
			auto websiteOpened = EventBus::Get(EventBus::EventName::WebsiteOpened);
			if (websiteOpened->Wait()) 
			{
				WString search = vl::__vwsn::Unbox<WString>(websiteOpened->GetData());
				if (search.Length() > 0)
				{
					GetApplication()->InvokeInMainThread(GetApplication()->GetMainWindow(), [search, this] {
						Regex regex(L"^\\{\"host\":\"(<host>\\.*?)\",\"username\":\"(<username>\\.*?)\"\\}");
						Ptr<RegexMatch> match = regex.Match(search);
						if (match)
						{
							this->host = match->Groups()[L"host"][0].Value().Buffer();
							this->username = match->Groups()[L"username"][0].Value().Buffer();
							this->search();
							if (this->GetCodes()->GetCount() == 1 && this->loginViewModel->GetLoggedIn())
							{
								auto codeSelected = EventBus::Get(EventBus::EventName::CodeSelected);
								codeSelected->SetData(vl::__vwsn::Box(this->codes[0]));
								codeSelected->Signal();
							}
						}
					});
				}
			}
		}
	});
}

Ptr<::gacpass::IEditCodeViewModel> CodeBookViewModel::GetEditCodeViewModel()
{
	return this->editCodeViewModel;
}

Ptr<IValueObservableList> CodeBookViewModel::GetCodes()
{
	return codes.GetWrapper();
}

Ptr<gacpass::ICode> CodeBookViewModel::GetSelectedCode()
{
	return selectedCode;
}

void CodeBookViewModel::SetSelectedCode(Ptr<gacpass::ICode> value)
{
	if (selectedCode != value)
	{
		selectedCode = value;
		SelectedCodeChanged();
	}
}

WString CodeBookViewModel::GetSearch()
{
	return host;
}

void CodeBookViewModel::SetSearch(const WString& value)
{
	this->host = value;
	this->username = L"";
	this->SearchChanged();
	this->search();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	Code *c = dynamic_cast<Code *>(code.Obj());
	int id = DB.insert<Code>(*c);
	c->SetId(id);
	this->updateReference(code);
	codes.Add(MakePtr<Code>(*c));
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(selectedCode.Obj());
	if (index != -1)
	{
		Code *c = dynamic_cast<Code *>(code.Obj());
		DB.update<Code>(*c);
		this->updateReference(code);
		codes.NotifyUpdate(index, 1);
	}
}

void CodeBookViewModel::updateReference(Ptr<gacpass::ICode> code)
{
	Ptr<IValueEnumerator> references = code->GetReferences()->CreateEnumerator();
	while (references->Next())
	{
		Ptr<Reference> r = (vl::__vwsn::Unbox<Ptr<Reference>>(references->GetCurrent()).Obj());
		if (r->GetCodeId() == 0)
		{
			DB.remove<Reference>(r->GetId());
			//code->GetReferences()->Remove(references->GetCurrent());
		}
		else
		{
			r->SetCodeId(code->GetId());
			if (r->GetId() == -1)
			{
				DB.insert<Reference>(*(r.Obj()));
			}
			else
			{
				DB.update<Reference>(*(r.Obj()));
			}
		}
	}
	code->GetReferences()->Clear();
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	DB.remove<Code>(code->GetId());
	DB.remove_all<Reference>(where(c(&Reference::GetCodeId) == code->GetId()));
}

void CodeBookViewModel::OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)
{
	auto code = codes.Get(arguments->itemIndex);
	if (code)
	{
		auto clipboard = GetCurrentController()->ClipboardService()->WriteClipboard();
		clipboard->SetText(code->GetPassword());
		clipboard->Submit();

		auto codeSelected = EventBus::Get(EventBus::EventName::CodeSelected);
		codeSelected->SetData(vl::__vwsn::Box(code));
		codeSelected->Signal();
	}
}

void CodeBookViewModel::search()
{
	this->codes.Clear();
	std::vector<Code> codes;
	if (this->host.Length() > 0)
	{
		auto codeIds = DB.select(&Code::GetId,
			inner_join<Reference>(on(c(&Reference::GetCodeId) == &Code::GetId)),
			where(like(&Reference::GetContent, L"%" + this->host + L"%") and like(&Code::GetUsername, this->username + L"%"))
		);
		codes = DB.get_all<Code>(where(in(&Code::GetId, codeIds)), order_by(&Code::GetTitle));
	}
	else
	{
		codes = DB.get_all<Code>(order_by(&Code::GetTitle));
	}
	for (auto& code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}
}
