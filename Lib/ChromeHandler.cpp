#include "ChromeHandler.h"

ChromeHandler::ChromeHandler(WString& input)
	:input(&input)
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
					//input->Insert(input->Length(), vl::__vwsn::Unbox<WString>(output->GetResult()));
					input->operator=(vl::__vwsn::Unbox<WString>(output->GetResult()));
					(state = static_cast<::vl::vint>(3));
					continue;
				}
				if ((state == static_cast<::vl::vint>(3)))
				{
					//yield & after yield
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