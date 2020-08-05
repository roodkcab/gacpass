#include "Code.h"
#include "CodeBookViewModel.h"

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
		SelectedCodeChanged();
	}
}

Ptr<gacpass::ICode> CodeBookViewModel::CreateCode()
{
	return MakePtr<Code>();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	codes.Add(code);
	this->NotifyChanged(code);
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	this->NotifyChanged(code);
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	this->NotifyChanged(code);
}

void CodeBookViewModel::NotifyChanged(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(code.Obj());
	if (index != -1)
	{
		codes.NotifyUpdate(index, 1);
	} 
	else
	{
		codes.NotifyUpdate(0, codes.Count());
	}
	this->Store();
}

void CodeBookViewModel::Load()
{
	//Deserialize
	std::ifstream os("codebook.cereal", std::ios::binary);
	if (os.is_open())
	{
		cereal::BinaryInputArchive archive(os);
		std::vector<RawCode> v;
		archive(cereal::make_nvp("code", v));
		for (RawCode i : v)
		{
			codes.Add(MakePtr<Code>(i));
		}
		codes.NotifyUpdate(0, codes.Count());
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

	std::ofstream os("codebook.cereal", std::ios::binary);
	cereal::BinaryOutputArchive archive(os);
	if (os.is_open())
	{
		archive(cereal::make_nvp("code", v));
	}
	os.close();
}
