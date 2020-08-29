#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "util.hpp"
#include "AsyncIO.h"
#include "ChromeHandler.h"
#include "ViewModel/CodeBookViewModel.h"
#include "ViewModel/RegisterVIewModel.h"
#include "ViewModel/LoginViewModel.h"
#include "db/DB.h"
#include "EventBus.h"

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
	GetApplication()->InvokeAsync([] {
		while (true)
		{
			WString input = L"";
			unsigned int length = 0;

			//Neat way!
			for (int i = 0; i < 4; i++)
			{
				unsigned int read_char = getchar();
				length = length | (read_char << i * 8);
			}

			//read the json-message
			for (unsigned int i = 0; i < length; i++)
			{
				input += getwchar();
			}

			auto istream = EventBus::Get(EventBus::EventName::IStream);
			istream->SetData(vl::__vwsn::Box(input));
			istream->Signal();
		}
	});

	GetApplication()->InvokeAsync([&] {
		WString input = L"";
		auto producer = Ptr<ICoroutine>(new AsyncIO(input));
		auto consumer = Ptr<ICoroutine>(new ChromeHandler());
		auto cr = Ptr<CoroutineResult>(new CoroutineResult());
		while (producer->GetStatus() != CoroutineStatus::Stopped && consumer->GetStatus() != CoroutineStatus::Stopped)
		{
			producer->Resume(false, NULL);
			cr->SetResult(::vl::__vwsn::Box(input));
			consumer->Resume(false, cr);
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
	auto m = MakePtr<Mutex>();
	m->Create(true, L"GacPass");
	if (!m->WaitForTime(0))
	{
		return;
	}

	{
		FileStream fileStream(L"MVVM.bin", FileStream::ReadOnly);
		GetResourceManager()->LoadResourceOrPending(fileStream);
	}

	auto viewModel = MakePtr<ViewModel>();
	initChromePlugin();

	auto window = new gacpass::MainWindow(viewModel);
	window->MoveToScreenCenter();
	GetApplication()->Run(window);
	delete window;
}
