#include "CodeBookViewModel.h"
#include "EditCodeViewModel.h"
#include "EventBus.h"
#include "VlppRegex.h"

CodeBookViewModel::CodeBookViewModel(Ptr<gacpass::ILoginViewModel> _loginViewModel) 
	: loginViewModel(_loginViewModel)
{
}

void CodeBookViewModel::Load(decltype(DB())& _storage)
{
	storage = &_storage;
	auto codes = storage->get_all<Code>(order_by(&Code::GetTitle));
	for (auto &code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}

	GetApplication()->InvokeAsync([&] {
		while (true)
		{
			auto websiteOpened = EventBus::Get(EventBus::EventName::WebsiteOpened);
			if (websiteOpened->Wait()) 
			{
				WString search = vl::__vwsn::Unbox<WString>(websiteOpened->GetData());
				if (search.Length() > 0)
				{
					WString website = search.Sub(9, search.Length() - 11).Buffer();
					this->SetSearch(website);
					if (this->GetCodes()->GetCount() == 1 && loginViewModel->GetLoggedIn())
					{
						auto codeSelected = EventBus::Get(EventBus::EventName::OStream);
						codeSelected->SetData(vl::__vwsn::Box(this->codes[0]->GetPassword()));
						codeSelected->Signal();
					}
				}
			}
		}
	});
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
	return search;
}

void CodeBookViewModel::SetSearch(const WString& value)
{
	search = value;
	this->SearchChanged();
	codes.Clear();
	auto codes = storage->get_all<Code>(where(like(&Code::GetTitle, L"%" + value + L"%")), order_by(&Code::GetTitle));
	for (auto &code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}
}

Ptr<gacpass::IEditCodeViewModel> CodeBookViewModel::CreateEditCodeViewModel()
{
	return MakePtr<EditCodeViewModel>();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	Code *c = dynamic_cast<Code *>(code.Obj());
	int id = storage->insert<Code>(*c);
	c->SetId(id);
	codes.Add(Ptr<Code>(c));
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(selectedCode.Obj());
	if (index != -1)
	{
		Code *c = dynamic_cast<Code *>(code.Obj());
		storage->update<Code>(*c);
		codes.NotifyUpdate(index, 1);
	}
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	storage->remove<Code>(code->GetId());
}

void CodeBookViewModel::OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)
{
	auto code = codes.Get(arguments->itemIndex);
	if (code)
	{
		auto clipboard = GetCurrentController()->ClipboardService()->WriteClipboard();
		clipboard->SetText(code->GetPassword());
		clipboard->Submit();

		auto codeSelected = EventBus::Get(EventBus::EventName::OStream);
		codeSelected->SetData(vl::__vwsn::Box(code->GetPassword()));
		codeSelected->Signal();
		//close window
	}
}
