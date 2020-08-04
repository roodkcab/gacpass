#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "ViewModel/Code.h"
#include "ViewModel/CodeBookViewModel.h"
#include "ViewModel/RegisterVIewModel.h"
#include "ViewModel/LoginViewModel.h"

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
