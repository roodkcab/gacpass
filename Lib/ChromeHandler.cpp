#include "ChromeHandler.h"
#include "EventBus.h"

ChromeHandler::ChromeHandler()
{
}

void ChromeHandler::Resume(bool raiseException, Ptr<CoroutineResult> output)
{
	if ((this->GetStatus() != ::vl::reflection::description::CoroutineStatus::Waiting))
	{
		throw ::vl::Exception(::vl::WString(L"Resume should be called only when the coroutine is in the waiting status.", false));
	}
	this->SetStatus(::vl::reflection::description::CoroutineStatus::Executing);
	try
	{
		{
			if ((state_before_pause != (-static_cast<::vl::vint>(1))))
			{
				if ((!static_cast<bool>(output)))
				{
					(state_before_pause = (-static_cast<::vl::vint>(1)));
				}
				else if ((!static_cast<bool>(::vl::__vwsn::This(output.Obj())->GetFailure())))
				{
					(state_before_pause = (-static_cast<::vl::vint>(1)));
				}
				else
				{
					{
						(state_before_pause = (-static_cast<::vl::vint>(1)));
						throw ::vl::Exception(::vl::__vwsn::This(::vl::__vwsn::This(output.Obj())->GetFailure().Obj())->GetMessage());
					}
				}
			}
			while (true)
			{
				if ((state == static_cast<::vl::vint>(1)))
				{
					this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
					return;
				}
				if ((state == static_cast<::vl::vint>(2)))
				{
					//before yield
					auto websiteOpened = EventBus::Get(EventBus::EventName::WebsiteOpened);
					websiteOpened->SetData(output->GetResult());
					websiteOpened->Signal();

					(state = static_cast<::vl::vint>(3));
					continue;
				}
				if ((state == static_cast<::vl::vint>(3)))
				{
					//yield & after yield
					auto code = EventBus::Get(EventBus::EventName::CodeSelected);
					if (code->WaitForTime(100))
					{
						Ptr<Code> res = vl::__vwsn::Unbox<Ptr<Code>>(code->GetData());
						auto ostream = EventBus::Get(EventBus::EventName::OStream);
						ostream->SetData(vl::__vwsn::Box(L"{\"username\":\"" + res->GetUsername() + L"\", \"password\":\"" + res->GetPassword() + L"\"}"));
						ostream->Signal();
					}

					(state = static_cast<::vl::vint>(4));
					continue;
				}
				if ((state == static_cast<::vl::vint>(4)))
				{
					this->SetStatus(::vl::reflection::description::CoroutineStatus::Waiting);
					(state_before_pause = state);
					(state = static_cast<::vl::vint>(2));
					return;
				}
			}
		}
	}
	catch (const ::vl::Exception& __vwsne_0)
	{
		/*auto __vwsn_co_ex_ = ::vl::reflection::description::IValueException::Create(__vwsne_0.Message());
		{
			this->SetFailure(__vwsn_co_ex_);
			this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
			if (__vwsn_raise_exception_)
			{
				throw;
			}
		}*/
	}
}

Ptr<IValueException> ChromeHandler::GetFailure()
{
	return nullptr;
}

void ChromeHandler::SetStatus(CoroutineStatus _status)
{
	status = _status;
}

CoroutineStatus	ChromeHandler::GetStatus()
{
	return status;
}