#include "EditCodeViewModel.h"
#include "db/Code.h"
#include <string>
#include <algorithm> 
#include <time.h> 
#include <chrono>

EditCodeViewModel::EditCodeViewModel()
	: codeLength(10)
	, code(MakePtr<Code>())
{
	code->SetPassword(this->genCode());
}

EditCodeViewModel::EditCodeViewModel(Ptr<gacpass::ICode> code)
{
	this->code = code;
}

Ptr<::gacpass::ICode> EditCodeViewModel::GetCode()
{
	return code;
}

vint EditCodeViewModel::GetCodeLength()
{
	return codeLength;
}

void EditCodeViewModel::SetCodeLength(vint codeLength)
{
	this->codeLength = codeLength;
	CodeLengthChanged();
	this->code->SetPassword(this->genCode());
	CodeChanged();
}

vint EditCodeViewModel::GetSpecialCharLength()
{
	return specialCharLength;
}

void EditCodeViewModel::SetSpecialCharLength(vint specialCharLength)
{
	this->specialCharLength = specialCharLength;
	SpecialCharLengthChanged();
	this->code->SetPassword(this->genCode());
	CodeChanged();
}

WString EditCodeViewModel::genCode() {
	int codeLength = this->codeLength; 
	int specialCharLength = this->specialCharLength;

	if (codeLength == 0) return L"";
	srand(long(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) % 10000);
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		return charset[rand() % (sizeof(charset) - 1)];
	};

	auto randSpecialChar = []() -> char
	{
		const char charset[] = "!@#$%^&*(){}_-:|~<>=";
		return charset[rand() % (sizeof(charset) - 1)];
	};

	std::wstring code(codeLength, 0);
	std::generate_n(code.begin(), codeLength - specialCharLength, randchar);
	for (int i = 0; i < specialCharLength; i++) {
		code.insert(rand() % code.length(), 1, randSpecialChar());
	}
	return WString(code.c_str());
}
