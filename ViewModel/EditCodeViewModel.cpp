#include "EditCodeViewModel.h"
#include "Code.h"
#include <string>
#include <algorithm> 

EditCodeViewModel::EditCodeViewModel()
	: code(MakePtr<Code>())
{}

EditCodeViewModel::EditCodeViewModel(Ptr<gacpass::ICode> code)
{
	this->code = code;
}

Ptr<::gacpass::ICode> EditCodeViewModel::GetCode()
{
	return code;
}

void EditCodeViewModel::SetCode(Ptr<gacpass::ICode> code)
{
	this->code = code;
}

vint EditCodeViewModel::GetCodeLength()
{
	return codeLength;
}

void EditCodeViewModel::SetCodeLength(vint codeLength)
{
	this->codeLength = codeLength;
	this->code->SetPassword(this->genCode(this->codeLength, this->specialCharLength));
	CodeChanged();
}

vint EditCodeViewModel::GetSpecialCharLength()
{
	return specialCharLength;
}

void EditCodeViewModel::SetSpecialCharLength(vint specialCharLength)
{
	this->specialCharLength = specialCharLength;
	this->code->SetPassword(this->genCode(this->codeLength, this->specialCharLength));
	CodeChanged();
}

WString EditCodeViewModel::genCode(const int length, const int spcialCharLength) {
	if (length == 0) return L"";
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		return charset[rand() % (sizeof(charset) - 1)];
	};
	std::wstring str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return WString(str.c_str());
}
