#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "util.hpp"
#include "AsyncIO.h"
#include "ViewModel/CodeBookViewModel.h"
#include "ViewModel/RegisterVIewModel.h"
#include "ViewModel/LoginViewModel.h"
#include "ViewModel/DB.h"

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
		storage.sync_schema();
		dynamic_cast<RegisterViewModel *>(registerViewModel.Obj())->Load(storage);
		dynamic_cast<LoginViewModel *>(loginViewModel.Obj())->Load(storage);
		dynamic_cast<CodeBookViewModel *>(codeBookViewModel.Obj())->Load(storage);
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

void initStorage()
{
	auto folder = vl::MakePtr<vl::filesystem::Folder>(vl::filesystem::FilePath(WAppdata(L"")));
	if (!folder->Exists())
	{
		folder->Create(false);
	}
}

void initChromePlugin()
{
	GetApplication()->InvokeAsync([] {
		auto cmdCoroutine = EnumerableCoroutine::Create(LAMBDA([=](EnumerableCoroutine::IImpl* impl) -> Ptr<ICoroutine> {
			return MakePtr<AsyncIO>(impl);
		}))->CreateEnumerator();

		while (true) {
			cmdCoroutine->Next();
			auto cmd = UnboxValue<std::string>(cmdCoroutine->GetCurrent());
			auto len = cmd.length();
			if (len > 0)
			{
				std::cout << char(len >> 0) << char(len >> 8) << char(len >> 16) << char(len >> 24) << cmd << std::flush;
			}
		}
	});
}

void GuiMain()
{
	{
		FileStream fileStream(L"MVVM.bin", FileStream::ReadOnly);
		GetResourceManager()->LoadResourceOrPending(fileStream);
	}

	initStorage();
	initChromePlugin();

	auto viewModel = MakePtr<ViewModel>();
	auto window = new gacpass::MainWindow(viewModel);
	window->MoveToScreenCenter();
	GetApplication()->Run(window);
	delete window;
}
