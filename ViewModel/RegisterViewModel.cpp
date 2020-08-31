#include "RegisterViewModel.h"

RegisterViewModel::RegisterViewModel()
	:regexLcLetters(L"[a-z]")
	, regexUcLetters(L"[A-Z]")
	, regexNumbers(L"[0-9]")
{}

WString RegisterViewModel::GetPassword()
{
	return password;
}

void RegisterViewModel::SetPassword(const WString& value)
{
	password = value;
	PasswordErrorChanged();
	ConfirmPasswordErrorChanged();
}

WString RegisterViewModel::GetPasswordError()
{
	if (password == L"")
	{
		return L"Password should not be empty.";
	}
	bool containsLowerCases = regexLcLetters.Match(password);
	bool containsUpperCases = regexUcLetters.Match(password);
	bool containsNumbers = regexNumbers.Match(password);
	if (!containsLowerCases || !containsUpperCases || !containsNumbers)
	{
		return L"Password should contains at least one lower case letter, one upper case letter and one digit.";
	}
	return L"";
}

WString RegisterViewModel::GetConfirmPassword()
{
	return confirmPassword;
}

void RegisterViewModel::SetConfirmPassword(const WString& value)
{
	confirmPassword = value;
	ConfirmPasswordErrorChanged();
}

WString RegisterViewModel::GetConfirmPasswordError()
{
	if (confirmPassword == L"")
	{
		return L"Confirm Password should not be empty.";
	}
	if (password != confirmPassword)
	{
		return L"Confirm Password should be equal to Password.";
	}

	return L"";
}

void RegisterViewModel::Register()
{
	DB.insert<Key>(Key(-1, this->GetPassword()));
	this->MainPasswordSetChanged();
}

bool RegisterViewModel::GetMainPasswordSet()
{
	return DB.count<Key>() > 0;
}
