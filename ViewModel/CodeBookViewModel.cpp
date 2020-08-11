#include "Code.h"
#include "CodeBookViewModel.h"

using namespace sqlite_orm;

CodeBookViewModel::CodeBookViewModel() 
	:storage(DBCodes())
{
	this->Load();
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
	if (value.Length() < search.Length())
	{
		this->Load();
	}
	search = value;
	List<Ptr<gacpass::ICode>> filteredCodes;
	CopyFrom(filteredCodes, codes);
	auto l = From(filteredCodes).Where([=](Ptr<gacpass::ICode> x) { return std::wstring(x.Obj()->GetWebsite().Buffer()).find(search.Buffer()) != std::string::npos; });

	codes.Clear();
	FOREACH(Ptr<gacpass::ICode>, code, l) codes.Add(code);
	this->SearchChanged();
}

Ptr<gacpass::ICode> CodeBookViewModel::CreateCode()
{
	return MakePtr<Code>();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	codes.Add(code);
	storage.insert(code);
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	storage.update(code);
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

void CodeBookViewModel::Load()
{
	codes.Clear();
	auto allCodes = storage.get_all<Code>();
	for (auto &i : allCodes)
	{
		auto code = MakePtr<Code>();
		code->Update(i.GetId(), i.GetWebsite(), i.GetUsername(), i.GetPassword());
		codes.Add(code);
	}
}
