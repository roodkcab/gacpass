#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "util.hpp"
#include "AsyncIO.h"
#include "ChromeHandler.h"
#include "ViewModel/CodeBookViewModel.h"
#include "ViewModel/RegisterVIewModel.h"
#include "ViewModel/LoginViewModel.h"
#include "ViewModel/EditCodeViewModel.h"
#include "db/DB.h"
#include "EventBus.h"

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace vl::stream;

class ViewModel : public Object, public virtual gacpass::IViewModel
{
private:
	::vl::Ptr<gacpass::IRegisterViewModel> registerViewModel;
	::vl::Ptr<gacpass::ILoginViewModel> loginViewModel;
	::vl::Ptr<gacpass::ICodeBookViewModel> codeBookViewModel;
	::vl::Ptr<gacpass::IEditCodeViewModel> editCodeViewModel;

public:
	ViewModel()
		: registerViewModel(MakePtr<RegisterViewModel>())
		, loginViewModel(MakePtr<LoginViewModel>())
		, codeBookViewModel(MakePtr<CodeBookViewModel>(loginViewModel))
		, editCodeViewModel(MakePtr<EditCodeViewModel>())
	{
		auto folder = vl::MakePtr<vl::filesystem::Folder>(vl::filesystem::FilePath(WAppdata(L"")));
		if (!folder->Exists())
		{
			folder->Create(false);
		}
		DB.sync_schema();
		dynamic_cast<CodeBookViewModel *>(codeBookViewModel.Obj())->Load();
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

	Ptr<gacpass::IEditCodeViewModel> GetEditCodeViewModel()override
	{
		return this->editCodeViewModel;
	}
};

void initChromePlugin()
{
#ifdef _WIN32
		//_setmode(_fileno(stdout), _O_BINARY);
		_setmode(_fileno(stdin), _O_BINARY);
#endif
	GetApplication()->InvokeAsync([] {
		char cBuffer[1024] = { 0 };
		while (true)
		{
			unsigned int uiSize = 0;
			std::cin.read((char*)&uiSize, sizeof(unsigned int));
			if (uiSize != 0 && uiSize < 1024)
			{
				memset(cBuffer, 0, 1024);
				std::cin.read(cBuffer, uiSize);
				WString input(std::wstring(&cBuffer[0], &cBuffer[uiSize]).c_str());

				auto istream = EventBus::Get(EventBus::EventName::IStream);
				istream->SetData(vl::__vwsn::Box(input));
				istream->Signal();
			}
		}
	});

	GetApplication()->InvokeAsync([] {
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
	//one instance at most
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
	//window->SetShowInTaskBar(false);
	GetApplication()->Run(window);
	delete window;
}
