#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "util.hpp"
#include "AsyncIO.h"
#include "ChromeHandler.h"
#include "ViewModel/CodeBookViewModel.h"
#include "ViewModel/RegisterVIewModel.h"
#include "ViewModel/LoginViewModel.h"
#include "db/DB.h"

using namespace vl::stream;

class ViewModel : public Object, public virtual gacpass::IViewModel
{
private:
	::vl::Ptr<gacpass::IRegisterViewModel> registerViewModel;
	::vl::Ptr<gacpass::ILoginViewModel> loginViewModel;
	::vl::Ptr<gacpass::ICodeBookViewModel> codeBookViewModel;
	decltype(DB()) storage;

public:
	ViewModel() 
		: storage(DB())
		, registerViewModel(MakePtr<RegisterViewModel>())
		, loginViewModel(MakePtr<LoginViewModel>())
		, codeBookViewModel(MakePtr<CodeBookViewModel>())
	{
		auto folder = vl::MakePtr<vl::filesystem::Folder>(vl::filesystem::FilePath(WAppdata(L"")));
		if (!folder->Exists())
		{
			folder->Create(false);
		}
		storage.sync_schema();
		dynamic_cast<RegisterViewModel *>(registerViewModel.Obj())->Load(storage);
		dynamic_cast<LoginViewModel *>(loginViewModel.Obj())->Load(storage);
		dynamic_cast<CodeBookViewModel *>(codeBookViewModel.Obj())->Load(storage);
	}

	decltype(DB()) GetStorage()
	{
		return storage;
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

void initChromePlugin()
{
	GetApplication()->InvokeAsync([&] {
		WString input = L"";
		WString output = L"";
		auto producer = Ptr<ICoroutine>(new AsyncIO(input));
		auto consumer = Ptr<ICoroutine>(new ChromeHandler(output));
		auto cr = Ptr<CoroutineResult>(new CoroutineResult());
		while (producer->GetStatus() != CoroutineStatus::Stopped && consumer->GetStatus() != CoroutineStatus::Stopped)
		{
			producer->Resume(false, cr);
			if (input.Length() > 0)
			{
				cr->SetResult(::vl::__vwsn::Box(input));
				consumer->Resume(false, cr);
				cr->SetResult(::vl::__vwsn::Box(output));
			}
		}

		if (producer->GetFailure())
		{
		}

		if (consumer->GetFailure())
		{
		}
	});
}

void GuiMain()
{
	{
		FileStream fileStream(L"MVVM.bin", FileStream::ReadOnly);
		GetResourceManager()->LoadResourceOrPending(fileStream);
	}

	initChromePlugin();

	auto viewModel = MakePtr<ViewModel>();
	auto window = new gacpass::MainWindow(viewModel);
	window->MoveToScreenCenter();
	GetApplication()->Run(window);
	delete window;
}
