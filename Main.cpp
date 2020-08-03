#define GAC_HEADER_USE_NAMESPACE
#include "UI/Source/GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

class Code : public Object, public virtual gacpass::ICode
{
private:
	WString	website;
	WString	username;
	WString	password;

public:
	Code()
		:website(L"https://")
		, username(L"")
		, password(L"")
	{}

	WString GetWebsite()override
	{
		return website;
	}

	WString GetUsername()override
	{
		return username;
	}

	WString GetPassword()override
	{
		return password;
	}

	void Update(Ptr<gacpass::ICodeBookViewModel> _viewmodel, const WString& _website, const WString& _username, const WString& _password)override
	{
		website = _website;
		username = _username;
		password = _password;

		_viewmodel->NotifyUpdate(this);
	}

};

class CodeBookViewModel : public Object, public virtual gacpass::ICodeBookViewModel
{
private:
	ObservableList<Ptr<gacpass::ICode>> codes;
	Ptr<gacpass::ICode> selectedCode;

public:
	CodeBookViewModel() {}

	Ptr<IValueObservableList> GetCodes()override
	{
		return codes.GetWrapper();
	}
	Ptr<gacpass::ICode> GetSelectedCode()override
	{
		return selectedCode;
	}

	void SetSelectedCode(Ptr<gacpass::ICode> value)override
	{
		if (selectedCode != value)
		{
			selectedCode = value;
			SelectedCodeChanged();
		}
	}

	Ptr<gacpass::ICode> CreateCode()override
	{
		return new Code();
	}

	void AddCode(Ptr<gacpass::ICode> code)override
	{
		codes.Add(code);
	}

	void NotifyUpdate(gacpass::ICode* code)override
	{
		vint index = codes.IndexOf(code);
		if (index != -1)
		{
			codes.NotifyUpdate(index, 1);
		}

	}
};

class LoginViewModel : public Object, public virtual gacpass::ILoginViewModel 
{
private:
	WString password;

public:
	LoginViewModel() {}

	WString GetPassword()override
	{
		return password;
	}

	void SetPassword(const WString& value)override
	{
		password = value;
	}
};

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
};

class ViewModel : public Object, public virtual gacpass::IViewModel
{
private:
	bool mainPasswordSet;
	bool loggedIn;
	::vl::Ptr<gacpass::IRegisterViewModel> registerViewModel;
	::vl::Ptr<gacpass::ILoginViewModel> loginViewModel;
	::vl::Ptr<gacpass::ICodeBookViewModel> codeBookViewModel;

public:
	ViewModel() 
		:mainPasswordSet(false)
		, loggedIn(false)
		, registerViewModel(MakePtr<RegisterViewModel>())
		, loginViewModel(MakePtr<LoginViewModel>())
		, codeBookViewModel(MakePtr<CodeBookViewModel>())
	{}

	bool GetMainPasswordSet()override
	{
		return this->registerViewModel->GetPasswordError() == L"" && this->registerViewModel->GetConfirmPasswordError() == L"";
	}

	bool GetLoggedIn()override
	{
		return this->GetMainPasswordSet() && this->registerViewModel->GetPassword() == this->loginViewModel->GetPassword();
	}

	Ptr<gacpass::IRegisterViewModel> GetRegisterViewModel()override
	{
		return this->registerViewModel;
	}

	Ptr<gacpass::ILoginViewModel> GetLoginViewModel()override
	{
		return this->loginViewModel;
	}

	Ptr<gacpass::ICodeBookViewModel> GetCodeBookViewModel()override
	{
		return this->codeBookViewModel;
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
