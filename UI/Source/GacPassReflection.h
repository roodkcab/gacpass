﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_GACPASSREFLECTION
#define VCZH_WORKFLOW_COMPILER_GENERATED_GACPASSREFLECTION

#include "GacPass.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			DECL_TYPE_INFO(::gacpass::CodeBookWindow)
			DECL_TYPE_INFO(::gacpass::CodeBookWindowConstructor)
			DECL_TYPE_INFO(::gacpass::ICode)
			DECL_TYPE_INFO(::gacpass::ICodeBookViewModel)
			DECL_TYPE_INFO(::gacpass::ILoginViewModel)
			DECL_TYPE_INFO(::gacpass::IRegisterViewModel)
			DECL_TYPE_INFO(::gacpass::IViewModel)
			DECL_TYPE_INFO(::gacpass::LoginWindow)
			DECL_TYPE_INFO(::gacpass::LoginWindowConstructor)
			DECL_TYPE_INFO(::gacpass::MainWindow)
			DECL_TYPE_INFO(::gacpass::MainWindowConstructor)
			DECL_TYPE_INFO(::gacpass::NewCodeWindow)
			DECL_TYPE_INFO(::gacpass::NewCodeWindowConstructor)
			DECL_TYPE_INFO(::gacpass::RegisterWindow)
			DECL_TYPE_INFO(::gacpass::RegisterWindowConstructor)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::ICode)
				::vl::WString GetHidePassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetHidePassword);
				}
				::vl::WString GetPassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetPassword);
				}
				::vl::WString GetUsername() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetUsername);
				}
				::vl::WString GetWebsite() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetWebsite);
				}
				void Update(const ::vl::WString& website, const ::vl::WString& username, const ::vl::WString& password) override
				{
					INVOKE_INTERFACE_PROXY(Update, website, username, password);
				}
			END_INTERFACE_PROXY(::gacpass::ICode)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::ICodeBookViewModel)
				void AddCode(::vl::Ptr<::gacpass::ICode> code) override
				{
					INVOKE_INTERFACE_PROXY(AddCode, code);
				}
				::vl::Ptr<::gacpass::ICode> CreateCode() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(CreateCode);
				}
				::vl::Ptr<::vl::reflection::description::IValueObservableList> GetCodes() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCodes);
				}
				::vl::WString GetSearch() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetSearch);
				}
				::vl::Ptr<::gacpass::ICode> GetSelectedCode() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetSelectedCode);
				}
				void RemoveCode(::vl::Ptr<::gacpass::ICode> code) override
				{
					INVOKE_INTERFACE_PROXY(RemoveCode, code);
				}
				void SetSearch(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetSearch, __vwsn_value_);
				}
				void SetSelectedCode(::vl::Ptr<::gacpass::ICode> __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetSelectedCode, __vwsn_value_);
				}
				void UpdateCode(::vl::Ptr<::gacpass::ICode> code) override
				{
					INVOKE_INTERFACE_PROXY(UpdateCode, code);
				}
			END_INTERFACE_PROXY(::gacpass::ICodeBookViewModel)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::ILoginViewModel)
				bool GetLoggedIn() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetLoggedIn);
				}
				::vl::WString GetPassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetPassword);
				}
				void SetPassword(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetPassword, __vwsn_value_);
				}
			END_INTERFACE_PROXY(::gacpass::ILoginViewModel)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::IRegisterViewModel)
				::vl::WString GetConfirmPassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetConfirmPassword);
				}
				::vl::WString GetConfirmPasswordError() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetConfirmPasswordError);
				}
				bool GetMainPasswordSet() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetMainPasswordSet);
				}
				::vl::WString GetPassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetPassword);
				}
				::vl::WString GetPasswordError() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetPasswordError);
				}
				void Register() override
				{
					INVOKE_INTERFACE_PROXY_NOPARAMS(Register);
				}
				void SetConfirmPassword(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetConfirmPassword, __vwsn_value_);
				}
				void SetPassword(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetPassword, __vwsn_value_);
				}
			END_INTERFACE_PROXY(::gacpass::IRegisterViewModel)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::IViewModel)
				::vl::Ptr<::gacpass::ICodeBookViewModel> GetCodeBookViewModel() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCodeBookViewModel);
				}
				::vl::Ptr<::gacpass::ILoginViewModel> GetLoginViewModel() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetLoginViewModel);
				}
				::vl::Ptr<::gacpass::IRegisterViewModel> GetRegisterViewModel() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetRegisterViewModel);
				}
			END_INTERFACE_PROXY(::gacpass::IViewModel)
#endif

			extern bool LoadGacPassTypes();
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
