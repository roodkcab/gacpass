#include "Code.h"
#include "CodeBookViewModel.h"
#include "util.hpp"

#include <fstream>

CodeBookViewModel::CodeBookViewModel() 
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
		if (value.Obj()) {
			auto clipboard = GetCurrentController()->ClipboardService()->WriteClipboard();
			clipboard->SetText(value.Obj()->GetPassword());
			clipboard->Submit();
		}
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
		codes.Clear();
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
	this->Store();
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(code.Obj());
	if (index != -1)
	{
		codes.NotifyUpdate(index, 1);
	}
	this->Store();
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	this->Store();
}

void CodeBookViewModel::Load()
{
	//Deserialize
	std::ifstream os(Appdata(L"\\codebook.cereal"), std::ios::binary);
	if (os.is_open())
	{
		cereal::BinaryInputArchive archive(os);
		std::vector<RawCode> v;
		archive(cereal::make_nvp("code", v));
		for (RawCode i : v)
		{
			codes.Add(MakePtr<Code>(i));
		}
	}
	os.close();
}

void CodeBookViewModel::Store()
{
	//Serialize all codes to file
	std::vector<RawCode> v;
	auto ce = codes.CreateEnumerator();
	while (ce->Next()) 
	{
		auto c = ce->Current().Obj();
		v.push_back(RawCode{ std::wstring(c->GetWebsite().Buffer()), std::wstring(c->GetUsername().Buffer()), std::wstring(c->GetPassword().Buffer()) });
	}

	std::ofstream os(Appdata(L"\\codebook.cereal"), std::ios::binary);
	cereal::BinaryOutputArchive archive(os);
	if (os.is_open())
	{
		archive(cereal::make_nvp("code", v));
	}
	os.close();
}
