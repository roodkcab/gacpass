#include "AsyncIO.h"

AsyncIO::AsyncIO(EnumerableCoroutine::IImpl* impl)
{
	this->impl = impl;
}

void AsyncIO::Resume(bool raiseException, Ptr<CoroutineResult> output)
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
					__vwsn_co2_i = "";
					unsigned int length = 0;

					//Neat way!
					for (int i = 0; i < 4; i++)
					{
						unsigned int read_char = getchar();
						length = length | (read_char << i * 8);
					}

					if (length == UINT32_MAX)
					{
						(state = static_cast<::vl::vint>(3));
						continue;
					}

					//read the json-message
					for (unsigned int i = 0; i < length; i++)
					{
						__vwsn_co2_i += getchar();
					}

					(state = static_cast<::vl::vint>(3));
					continue;

					/*std::string message = "{\"text\":\"This is a response message\"}";
					// Collect the length of the message
					unsigned int len = message.length();

					// Now we can output our message
					if (__vwsn_co2_i == "{\"text\":\"#STOP#\"}") {
						message = "{\"text\":\"EXITING...\"}";
						len = message.length();

						std::cout << char(len >> 0)
							<< char(len >> 8)
							<< char(len >> 16)
							<< char(len >> 24);

						std::cout << message;
						break;
					}*/
				}
				if ((state == static_cast<::vl::vint>(3)))
				{
					::vl::reflection::description::EnumerableCoroutine::YieldAndPause(this->impl, ::vl::__vwsn::Box(__vwsn_co2_i));
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

Ptr<IValueException> AsyncIO::GetFailure()
{
	return nullptr;
}

void AsyncIO::SetStatus(CoroutineStatus _status)
{
	status = _status;
}

CoroutineStatus	AsyncIO::GetStatus()
{
	return status;
}