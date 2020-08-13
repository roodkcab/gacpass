#include "CodeBookViewModel.h"

CodeBookViewModel::CodeBookViewModel() 
	:storage(DBCodes())
{
	storage.sync_schema();
	auto codes = storage.get_all<Code>();
	for (auto &code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}
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
	storage.sync_schema();
	auto codes = storage.get_all<Code>(where(like(&Code::GetWebsite, L"%" + value + L"%")));
	for (auto &code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}
}

Ptr<gacpass::ICode> CodeBookViewModel::CreateCode()
{
	return MakePtr<Code>();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	Code *c = dynamic_cast<Code *>(code.Obj());
	int id = storage.insert<Code>(*c);
	c->SetId(id);
	codes.Add(Ptr<Code>(c));
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(code.Obj());
	if (index != -1)
	{
		Code *c = dynamic_cast<Code *>(code.Obj());
		storage.update<Code>(*c);
		codes.NotifyUpdate(index, 1);
	}
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	storage.remove<Code>(code->GetId());
}

void CodeBookViewModel::OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)
{
	auto code = codes.Get(arguments->itemIndex);
	if (code)
	{
		auto clipboard = GetCurrentController()->ClipboardService()->WriteClipboard();
		clipboard->SetText(code->GetPassword());
		clipboard->Submit();
	}
}
