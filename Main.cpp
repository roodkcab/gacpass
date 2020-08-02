#define GAC_HEADER_USE_NAMESPACE
#include "UI/Source/GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;

class RegisterViewModel : public Object, public virtual gacpass::IRegisterViewModel
{
private:
	WString password;
	WString confirmPassword;
	Regex regexLcLetters;
	Regex regexUcLetters;
	Regex regexNumbers;

public:
	RegisterViewModel()
		:regexLcLetters(L"[a-z]")
		, regexUcLetters(L"[A-Z]")
		, regexNumbers(L"[0-9]")
	{}

	WString GetPassword()override
	{
		return password;
	}

	void SetPassword(const WString& value)override
	{
		password = value;
		PasswordErrorChanged();
	}

	WString GetPasswordError()override
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

	WString GetConfirmPassword()override
	{
		return confirmPassword;
	}

	void SetConfirmPassword(const WString& value)override
	{
		confirmPassword = value;
		ConfirmPasswordErrorChanged();
	}

	WString GetConfirmPasswordError()override
	{
		if (password != confirmPassword)
		{
			return L"Confirm Password should not be equal to Password.";
		}
		
		return L"";
	}
};

class ViewModel : public Object, public virtual gacpass::IViewModel
{
private:
	bool mainPasswordSet;
	bool loggedIn;
	::vl::Ptr<gacpass::IRegisterViewModel> registerViewModel;

public:
	ViewModel() 
		:mainPasswordSet(false)
		, loggedIn(false)
		, registerViewModel(MakePtr<RegisterViewModel>())
	{}

	bool GetMainPasswordSet()override
	{
		return false;
	}

	bool GetLoggedIn()override
	{
		return this->GetMainPasswordSet() && false;
	}

	Ptr<gacpass::IRegisterViewModel> GetRegisterViewModel()override
	{
		return this->registerViewModel;
	}
};

void GuiMain()
{
	{
		FileStream fileStream(L"MVVM.bin", FileStream::ReadOnly);
		GetResourceManager()->LoadResourceOrPending(fileStream);
	}

	auto viewModel = MakePtr<ViewModel>();
	auto window = new gacpass::MainWindow(viewModel);
	window->MoveToScreenCenter();
	GetApplication()->Run(window);
	delete window;
}
