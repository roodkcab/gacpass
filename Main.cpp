#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "util.hpp"
#include "AsyncIO.h"
#include "ChromeHandler.h"
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
		
		/*auto consumer = EnumerableCoroutine::Create(LAMBDA([=](EnumerableCoroutine::IImpl* impl) -> Ptr<ICoroutine> {
			return MakePtr<ChromeHandler>(impl);
		}))->CreateEnumerator();*/

		/*while (true) {
			producer->Next();
			auto cmd = UnboxValue<std::string>(producer->GetCurrent());
			consumer->Send(cmd);
			consumer->Next();
			auto ret = UnboxValue<std::string>(consumer->GetCurrent());
			producer->Send(ret);

			auto len = cmd.length();
			if (len > 0)
			{
				std::cout << char(len >> 0) << char(len >> 8) << char(len >> 16) << char(len >> 24) << cmd << std::flush;
			}
		}*/
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
