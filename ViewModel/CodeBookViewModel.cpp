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
}

void CodeBookViewModel::NotifyUpdate(gacpass::ICode* code)
{
	this->Store();
	vint index = codes.IndexOf(code);
	if (index != -1)
	{
		codes.NotifyUpdate(index, 1);
	}
}

void CodeBookViewModel::Load()
{
	//Deserialize
	/*std::ifstream os("out.cereal", std::ios::binary);
	cereal::BinaryInputArchive archive(os);
	std::vector<RawCode> v;
    archive((v));
	for (RawCode i : v)
	{
		codes.Add(MakePtr<Code>(i));
	}*/
}

void CodeBookViewModel::Store()
{
	//Serialize all codes to file
	std::ofstream os("out.cereal", std::ios::binary);
	cereal::BinaryOutputArchive archive(os);
	std::vector<int> v;
	auto ce = codes.CreateEnumerator();
	while (ce->Next()) 
	{
		auto c = ce->Current().Obj();
		//v.push_back();
		//std::string(c->GetWebsite().Buffer()), std::string(c->GetUsername().Buffer()), std::string(c->GetPassword().Buffer()) 
		//RawCode cc = RawCode{ std::string(), std::string(), std::string() };
		//archive(CEREAL_NVP(cc));
	}
	archive(CEREAL_NVP(v));
}
