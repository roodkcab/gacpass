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
			DECL_TYPE_INFO(::gacpass::HostType)
			DECL_TYPE_INFO(::gacpass::HostTypeDisplayer)
			DECL_TYPE_INFO(::gacpass::HostTypeDisplayerConstructor)
			DECL_TYPE_INFO(::gacpass::HostTypeEditor)
			DECL_TYPE_INFO(::gacpass::HostTypeEditorConstructor)
			DECL_TYPE_INFO(::gacpass::HostTypeItemTemplate)
			DECL_TYPE_INFO(::gacpass::HostTypeItemTemplateConstructor)
			DECL_TYPE_INFO(::gacpass::HostTypeVisualizer)
			DECL_TYPE_INFO(::gacpass::HostTypeVisualizerConstructor)
			DECL_TYPE_INFO(::gacpass::ICode)
			DECL_TYPE_INFO(::gacpass::ICodeBookViewModel)
			DECL_TYPE_INFO(::gacpass::IEditCodeViewModel)
			DECL_TYPE_INFO(::gacpass::IKey)
			DECL_TYPE_INFO(::gacpass::ILoginViewModel)
			DECL_TYPE_INFO(::gacpass::IReference)
			DECL_TYPE_INFO(::gacpass::IRegisterViewModel)
			DECL_TYPE_INFO(::gacpass::IViewModel)
			DECL_TYPE_INFO(::gacpass::LoginWindow)
			DECL_TYPE_INFO(::gacpass::LoginWindowConstructor)
			DECL_TYPE_INFO(::gacpass::MainWindow)
			DECL_TYPE_INFO(::gacpass::MainWindowConstructor)
			DECL_TYPE_INFO(::gacpass::ReferenceFilter)
			DECL_TYPE_INFO(::gacpass::ReferenceFilterConstructor)
			DECL_TYPE_INFO(::gacpass::RegisterWindow)
			DECL_TYPE_INFO(::gacpass::RegisterWindowConstructor)
			DECL_TYPE_INFO(::gacpass::TextEditor)
			DECL_TYPE_INFO(::gacpass::TextEditorConstructor)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::ICode)
				void AddReference() override
				{
					INVOKE_INTERFACE_PROXY_NOPARAMS(AddReference);
				}
				::vl::WString GetHidePassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetHidePassword);
				}
				::vl::vint GetId() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetId);
				}
				::vl::WString GetPassword() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetPassword);
				}
				::vl::Ptr<::vl::reflection::description::IValueObservableList> GetReferences() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetReferences);
				}
				::vl::WString GetTitle() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetTitle);
				}
				::vl::WString GetUsername() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetUsername);
				}
				void SetId(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetId, __vwsn_value_);
				}
				void SetPassword(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetPassword, __vwsn_value_);
				}
				void SetTitle(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetTitle, __vwsn_value_);
				}
				void SetUsername(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetUsername, __vwsn_value_);
				}
				void Update(::vl::Ptr<::gacpass::ICode> code) override
				{
					INVOKE_INTERFACE_PROXY(Update, code);
				}
			END_INTERFACE_PROXY(::gacpass::ICode)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::ICodeBookViewModel)
				void AddCode(::vl::Ptr<::gacpass::ICode> code) override
				{
					INVOKE_INTERFACE_PROXY(AddCode, code);
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
				void OnItemLeftButtonDoubleClick(::vl::presentation::compositions::GuiItemMouseEventArgs* arguments) override
				{
					INVOKE_INTERFACE_PROXY(OnItemLeftButtonDoubleClick, arguments);
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

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::IEditCodeViewModel)
				void Clear() override
				{
					INVOKE_INTERFACE_PROXY_NOPARAMS(Clear);
				}
				::vl::Ptr<::gacpass::ICode> GetCode() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCode);
				}
				::vl::vint GetCodeLength() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCodeLength);
				}
				::vl::Ptr<::gacpass::IReference> GetSelectedReference() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetSelectedReference);
				}
				::vl::vint GetSpecialCharLength() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetSpecialCharLength);
				}
				void SetCodeLength(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetCodeLength, __vwsn_value_);
				}
				void SetSelectedReference(::vl::Ptr<::gacpass::IReference> __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetSelectedReference, __vwsn_value_);
				}
				void SetSpecialCharLength(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetSpecialCharLength, __vwsn_value_);
				}
			END_INTERFACE_PROXY(::gacpass::IEditCodeViewModel)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::IKey)
				::vl::vint GetId() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetId);
				}
				::vl::WString GetKey() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetKey);
				}
				void SetId(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetId, __vwsn_value_);
				}
				void SetKey(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetKey, __vwsn_value_);
				}
			END_INTERFACE_PROXY(::gacpass::IKey)

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

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gacpass::IReference)
				::vl::vint GetCodeId() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCodeId);
				}
				::vl::WString GetContent() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetContent);
				}
				::vl::vint GetId() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetId);
				}
				::gacpass::HostType GetType() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetType);
				}
				void SetCodeId(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetCodeId, __vwsn_value_);
				}
				void SetContent(const ::vl::WString& __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetContent, __vwsn_value_);
				}
				void SetId(::vl::vint __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetId, __vwsn_value_);
				}
				void SetType(::gacpass::HostType __vwsn_value_) override
				{
					INVOKE_INTERFACE_PROXY(SetType, __vwsn_value_);
				}
				void Update(::vl::Ptr<::gacpass::IReference> reference) override
				{
					INVOKE_INTERFACE_PROXY(Update, reference);
				}
			END_INTERFACE_PROXY(::gacpass::IReference)

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
				::vl::Ptr<::gacpass::IEditCodeViewModel> GetEditCodeViewModel() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetEditCodeViewModel);
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
