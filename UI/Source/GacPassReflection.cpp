﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "GacPassReflection.h"

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
			IMPL_CPP_TYPE_INFO(gacpass::CodeBookWindow)
			IMPL_CPP_TYPE_INFO(gacpass::CodeBookWindowConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::HostType)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeDisplayer)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeDisplayerConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeEditor)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeEditorConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeItemTemplate)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeItemTemplateConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeVisualizer)
			IMPL_CPP_TYPE_INFO(gacpass::HostTypeVisualizerConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::ICode)
			IMPL_CPP_TYPE_INFO(gacpass::ICodeBookViewModel)
			IMPL_CPP_TYPE_INFO(gacpass::IEditCodeViewModel)
			IMPL_CPP_TYPE_INFO(gacpass::IKey)
			IMPL_CPP_TYPE_INFO(gacpass::ILoginViewModel)
			IMPL_CPP_TYPE_INFO(gacpass::IReference)
			IMPL_CPP_TYPE_INFO(gacpass::IRegisterViewModel)
			IMPL_CPP_TYPE_INFO(gacpass::IViewModel)
			IMPL_CPP_TYPE_INFO(gacpass::LoginWindow)
			IMPL_CPP_TYPE_INFO(gacpass::LoginWindowConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::MainWindow)
			IMPL_CPP_TYPE_INFO(gacpass::MainWindowConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::ReferenceFilter)
			IMPL_CPP_TYPE_INFO(gacpass::ReferenceFilterConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::RegisterWindow)
			IMPL_CPP_TYPE_INFO(gacpass::RegisterWindowConstructor)
			IMPL_CPP_TYPE_INFO(gacpass::TextEditor)
			IMPL_CPP_TYPE_INFO(gacpass::TextEditorConstructor)

#define _ ,
			BEGIN_CLASS_MEMBER(::gacpass::CodeBookWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiCustomControl)
				CLASS_MEMBER_BASE(::gacpass::CodeBookWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::CodeBookWindow*(::vl::Ptr<::gacpass::ICodeBookViewModel>, ::vl::Ptr<::gacpass::IEditCodeViewModel>, ::vl::presentation::controls::GuiWindow*), { L"__vwsn_ctor_parameter_CodeBookViewModel" _ L"__vwsn_ctor_parameter_EditCodeViewModel" _ L"__vwsn_ctor_parameter_MainWindow" })
				CLASS_MEMBER_METHOD(GetCodeBookViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetEditCodeViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetMainWindow, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_parameter_CodeBookViewModel)
				CLASS_MEMBER_FIELD(__vwsn_parameter_EditCodeViewModel)
				CLASS_MEMBER_FIELD(__vwsn_parameter_MainWindow)
				CLASS_MEMBER_PROPERTY_READONLY(CodeBookViewModel, GetCodeBookViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(EditCodeViewModel, GetEditCodeViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(MainWindow, GetMainWindow)
			END_CLASS_MEMBER(::gacpass::CodeBookWindow)

			BEGIN_CLASS_MEMBER(::gacpass::CodeBookWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::CodeBookWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_CodeBookWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_22)
				CLASS_MEMBER_FIELD(__vwsn_precompile_23)
				CLASS_MEMBER_FIELD(__vwsn_precompile_24)
				CLASS_MEMBER_FIELD(__vwsn_precompile_25)
				CLASS_MEMBER_FIELD(__vwsn_precompile_26)
				CLASS_MEMBER_FIELD(__vwsn_precompile_27)
				CLASS_MEMBER_FIELD(__vwsn_precompile_28)
				CLASS_MEMBER_FIELD(__vwsn_precompile_29)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_30)
				CLASS_MEMBER_FIELD(__vwsn_precompile_31)
				CLASS_MEMBER_FIELD(__vwsn_precompile_32)
				CLASS_MEMBER_FIELD(__vwsn_precompile_33)
				CLASS_MEMBER_FIELD(__vwsn_precompile_34)
				CLASS_MEMBER_FIELD(__vwsn_precompile_35)
				CLASS_MEMBER_FIELD(__vwsn_precompile_36)
				CLASS_MEMBER_FIELD(__vwsn_precompile_37)
				CLASS_MEMBER_FIELD(__vwsn_precompile_38)
				CLASS_MEMBER_FIELD(__vwsn_precompile_39)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_40)
				CLASS_MEMBER_FIELD(__vwsn_precompile_41)
				CLASS_MEMBER_FIELD(__vwsn_precompile_42)
				CLASS_MEMBER_FIELD(__vwsn_precompile_43)
				CLASS_MEMBER_FIELD(__vwsn_precompile_44)
				CLASS_MEMBER_FIELD(__vwsn_precompile_45)
				CLASS_MEMBER_FIELD(__vwsn_precompile_46)
				CLASS_MEMBER_FIELD(__vwsn_precompile_47)
				CLASS_MEMBER_FIELD(__vwsn_precompile_48)
				CLASS_MEMBER_FIELD(__vwsn_precompile_49)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_50)
				CLASS_MEMBER_FIELD(__vwsn_precompile_51)
				CLASS_MEMBER_FIELD(__vwsn_precompile_52)
				CLASS_MEMBER_FIELD(__vwsn_precompile_53)
				CLASS_MEMBER_FIELD(__vwsn_precompile_54)
				CLASS_MEMBER_FIELD(__vwsn_precompile_55)
				CLASS_MEMBER_FIELD(__vwsn_precompile_56)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(CodeBookViewModel)
				CLASS_MEMBER_FIELD(EditCodeViewModel)
				CLASS_MEMBER_FIELD(Filter)
				CLASS_MEMBER_FIELD(MainWindow)
				CLASS_MEMBER_FIELD(commandEditCode)
				CLASS_MEMBER_FIELD(commandNewCode)
				CLASS_MEMBER_FIELD(commandNewReference)
				CLASS_MEMBER_FIELD(commandRemoveCode)
				CLASS_MEMBER_FIELD(commandRemoveReference)
				CLASS_MEMBER_FIELD(gridViewReferences)
				CLASS_MEMBER_FIELD(hTrackerCodeLength)
				CLASS_MEMBER_FIELD(hTrackerSpecialCharLength)
				CLASS_MEMBER_FIELD(listViewCodes)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textBoxPassword)
				CLASS_MEMBER_FIELD(textBoxSearch)
				CLASS_MEMBER_FIELD(textBoxTitle)
				CLASS_MEMBER_FIELD(textBoxUsername)
			END_CLASS_MEMBER(::gacpass::CodeBookWindowConstructor)

			BEGIN_ENUM_ITEM(::gacpass::HostType)
				ENUM_CLASS_ITEM(Database)
				ENUM_CLASS_ITEM(Server)
				ENUM_CLASS_ITEM(Website)
			END_ENUM_ITEM(::gacpass::HostType)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeDisplayer)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiCustomControl)
				CLASS_MEMBER_BASE(::gacpass::HostTypeDisplayerConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::HostTypeDisplayer*(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetType, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetType, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(TypeChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_Type)
				CLASS_MEMBER_PROPERTY_EVENT(Type, GetType, SetType, TypeChanged)
			END_CLASS_MEMBER(::gacpass::HostTypeDisplayer)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeDisplayerConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::HostTypeDisplayerConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_HostTypeDisplayer_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::HostTypeDisplayerConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeEditor)
				CLASS_MEMBER_BASE(::vl::presentation::templates::GuiGridEditorTemplate)
				CLASS_MEMBER_BASE(::gacpass::HostTypeEditorConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::HostTypeEditor*(), NO_PARAMETER)
				CLASS_MEMBER_FIELD(items)
			END_CLASS_MEMBER(::gacpass::HostTypeEditor)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeEditorConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::HostTypeEditorConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_HostTypeEditor_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(comboBox)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::HostTypeEditorConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeItemTemplate)
				CLASS_MEMBER_BASE(::vl::presentation::templates::GuiTextListItemTemplate)
				CLASS_MEMBER_BASE(::gacpass::HostTypeItemTemplateConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::HostTypeItemTemplate*(::gacpass::HostType), { L"__vwsn_ctor_parameter_SelectedType" })
				CLASS_MEMBER_METHOD(GetSelectedType, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_parameter_SelectedType)
				CLASS_MEMBER_PROPERTY_READONLY(SelectedType, GetSelectedType)
			END_CLASS_MEMBER(::gacpass::HostTypeItemTemplate)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeItemTemplateConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::HostTypeItemTemplateConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_HostTypeItemTemplate_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(SelectedType)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::HostTypeItemTemplateConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeVisualizer)
				CLASS_MEMBER_BASE(::vl::presentation::templates::GuiGridVisualizerTemplate)
				CLASS_MEMBER_BASE(::gacpass::HostTypeVisualizerConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::HostTypeVisualizer*(), NO_PARAMETER)
			END_CLASS_MEMBER(::gacpass::HostTypeVisualizer)

			BEGIN_CLASS_MEMBER(::gacpass::HostTypeVisualizerConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::HostTypeVisualizerConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_HostTypeVisualizer_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::HostTypeVisualizerConstructor)

			BEGIN_INTERFACE_MEMBER(::gacpass::ICode)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(AddReference, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetHidePassword, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetId, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetPassword, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetReferences, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetTitle, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetUsername, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetId, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetPassword, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetTitle, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetUsername, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(Update, { L"code" })
				CLASS_MEMBER_EVENT(IdChanged)
				CLASS_MEMBER_EVENT(PasswordChanged)
				CLASS_MEMBER_EVENT(TitleChanged)
				CLASS_MEMBER_EVENT(UsernameChanged)
				CLASS_MEMBER_PROPERTY_READONLY(HidePassword, GetHidePassword)
				CLASS_MEMBER_PROPERTY_EVENT(Id, GetId, SetId, IdChanged)
				CLASS_MEMBER_PROPERTY_EVENT(Password, GetPassword, SetPassword, PasswordChanged)
				CLASS_MEMBER_PROPERTY_READONLY(References, GetReferences)
				CLASS_MEMBER_PROPERTY_EVENT(Title, GetTitle, SetTitle, TitleChanged)
				CLASS_MEMBER_PROPERTY_EVENT(Username, GetUsername, SetUsername, UsernameChanged)
			END_INTERFACE_MEMBER(::gacpass::ICode)

			BEGIN_INTERFACE_MEMBER(::gacpass::ICodeBookViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(AddCode, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetCodes, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetSearch, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetSelectedCode, NO_PARAMETER)
				CLASS_MEMBER_METHOD(OnItemLeftButtonDoubleClick, { L"arguments" })
				CLASS_MEMBER_METHOD(RemoveCode, { L"code" })
				CLASS_MEMBER_METHOD(SetSearch, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetSelectedCode, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(UpdateCode, { L"code" })
				CLASS_MEMBER_EVENT(SearchChanged)
				CLASS_MEMBER_EVENT(SelectedCodeChanged)
				CLASS_MEMBER_PROPERTY_READONLY(Codes, GetCodes)
				CLASS_MEMBER_PROPERTY_EVENT(Search, GetSearch, SetSearch, SearchChanged)
				CLASS_MEMBER_PROPERTY_EVENT(SelectedCode, GetSelectedCode, SetSelectedCode, SelectedCodeChanged)
			END_INTERFACE_MEMBER(::gacpass::ICodeBookViewModel)

			BEGIN_INTERFACE_MEMBER(::gacpass::IEditCodeViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(Clear, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetCode, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetCodeLength, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetSelectedReference, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetSpecialCharLength, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetCodeLength, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetSelectedReference, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetSpecialCharLength, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(CodeLengthChanged)
				CLASS_MEMBER_EVENT(SelectedReferenceChanged)
				CLASS_MEMBER_EVENT(SpecialCharLengthChanged)
				CLASS_MEMBER_PROPERTY_READONLY(Code, GetCode)
				CLASS_MEMBER_PROPERTY_EVENT(CodeLength, GetCodeLength, SetCodeLength, CodeLengthChanged)
				CLASS_MEMBER_PROPERTY_EVENT(SelectedReference, GetSelectedReference, SetSelectedReference, SelectedReferenceChanged)
				CLASS_MEMBER_PROPERTY_EVENT(SpecialCharLength, GetSpecialCharLength, SetSpecialCharLength, SpecialCharLengthChanged)
			END_INTERFACE_MEMBER(::gacpass::IEditCodeViewModel)

			BEGIN_INTERFACE_MEMBER(::gacpass::IKey)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetId, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetKey, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetId, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetKey, { L"__vwsn_value_" })
				CLASS_MEMBER_PROPERTY(Id, GetId, SetId)
				CLASS_MEMBER_PROPERTY(Key, GetKey, SetKey)
			END_INTERFACE_MEMBER(::gacpass::IKey)

			BEGIN_INTERFACE_MEMBER(::gacpass::ILoginViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetLoggedIn, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetPassword, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetPassword, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(LoggedInChanged)
				CLASS_MEMBER_EVENT(PasswordChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(LoggedIn, GetLoggedIn, LoggedInChanged)
				CLASS_MEMBER_PROPERTY_EVENT(Password, GetPassword, SetPassword, PasswordChanged)
			END_INTERFACE_MEMBER(::gacpass::ILoginViewModel)

			BEGIN_INTERFACE_MEMBER(::gacpass::IReference)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetCodeId, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetContent, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetId, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetType, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetCodeId, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetContent, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetId, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetType, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(Update, { L"reference" })
				CLASS_MEMBER_PROPERTY(CodeId, GetCodeId, SetCodeId)
				CLASS_MEMBER_PROPERTY(Content, GetContent, SetContent)
				CLASS_MEMBER_PROPERTY(Id, GetId, SetId)
				CLASS_MEMBER_PROPERTY(Type, GetType, SetType)
			END_INTERFACE_MEMBER(::gacpass::IReference)

			BEGIN_INTERFACE_MEMBER(::gacpass::IRegisterViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetConfirmPassword, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetConfirmPasswordError, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetMainPasswordSet, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetPassword, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetPasswordError, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Register, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetConfirmPassword, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetPassword, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(ConfirmPasswordChanged)
				CLASS_MEMBER_EVENT(ConfirmPasswordErrorChanged)
				CLASS_MEMBER_EVENT(MainPasswordSetChanged)
				CLASS_MEMBER_EVENT(PasswordChanged)
				CLASS_MEMBER_EVENT(PasswordErrorChanged)
				CLASS_MEMBER_PROPERTY_EVENT(ConfirmPassword, GetConfirmPassword, SetConfirmPassword, ConfirmPasswordChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(ConfirmPasswordError, GetConfirmPasswordError, ConfirmPasswordErrorChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(MainPasswordSet, GetMainPasswordSet, MainPasswordSetChanged)
				CLASS_MEMBER_PROPERTY_EVENT(Password, GetPassword, SetPassword, PasswordChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(PasswordError, GetPasswordError, PasswordErrorChanged)
			END_INTERFACE_MEMBER(::gacpass::IRegisterViewModel)

			BEGIN_INTERFACE_MEMBER(::gacpass::IViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetCodeBookViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetEditCodeViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetLoginViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetRegisterViewModel, NO_PARAMETER)
				CLASS_MEMBER_EVENT(CodeBookViewModelChanged)
				CLASS_MEMBER_EVENT(EditCodeViewModelChanged)
				CLASS_MEMBER_EVENT(LoginViewModelChanged)
				CLASS_MEMBER_EVENT(RegisterViewModelChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(CodeBookViewModel, GetCodeBookViewModel, CodeBookViewModelChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(EditCodeViewModel, GetEditCodeViewModel, EditCodeViewModelChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(LoginViewModel, GetLoginViewModel, LoginViewModelChanged)
				CLASS_MEMBER_PROPERTY_EVENT_READONLY(RegisterViewModel, GetRegisterViewModel, RegisterViewModelChanged)
			END_INTERFACE_MEMBER(::gacpass::IViewModel)

			BEGIN_CLASS_MEMBER(::gacpass::LoginWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiCustomControl)
				CLASS_MEMBER_BASE(::gacpass::LoginWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::LoginWindow*(::vl::Ptr<::gacpass::ILoginViewModel>), { L"__vwsn_ctor_parameter_ViewModel" })
				CLASS_MEMBER_METHOD(FlyoutAnimation, { L"container" })
				CLASS_MEMBER_METHOD(GetViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(OutAnimation, { L"container" })
				CLASS_MEMBER_FIELD(__vwsn_parameter_ViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(ViewModel, GetViewModel)
			END_CLASS_MEMBER(::gacpass::LoginWindow)

			BEGIN_CLASS_MEMBER(::gacpass::LoginWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::LoginWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_LoginWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(Container)
				CLASS_MEMBER_FIELD(ViewModel)
				CLASS_MEMBER_FIELD(buttonLogin)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textBoxPassword)
			END_CLASS_MEMBER(::gacpass::LoginWindowConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::MainWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiWindow)
				CLASS_MEMBER_BASE(::gacpass::MainWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::MainWindow*(::vl::Ptr<::gacpass::IViewModel>), { L"__vwsn_ctor_parameter_ViewModel" })
				CLASS_MEMBER_METHOD(GetViewModel, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_parameter_ViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(ViewModel, GetViewModel)
			END_CLASS_MEMBER(::gacpass::MainWindow)

			BEGIN_CLASS_MEMBER(::gacpass::MainWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::MainWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_MainWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(ViewModel)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::MainWindowConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::ReferenceFilter)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiCustomControl)
				CLASS_MEMBER_BASE(::gacpass::ReferenceFilterConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::ReferenceFilter*(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_instance_ctor_, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetFilter, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetFilter, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(UpdateFilter, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_prop_Filter)
				CLASS_MEMBER_PROPERTY_READONLY(Filter, GetFilter)
				CLASS_MEMBER_FIELD(callback)
			END_CLASS_MEMBER(::gacpass::ReferenceFilter)

			BEGIN_CLASS_MEMBER(::gacpass::ReferenceFilterConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::ReferenceFilterConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_ReferenceFilter_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::gacpass::ReferenceFilterConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::RegisterWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiCustomControl)
				CLASS_MEMBER_BASE(::gacpass::RegisterWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::RegisterWindow*(::vl::Ptr<::gacpass::IRegisterViewModel>), { L"__vwsn_ctor_parameter_ViewModel" })
				CLASS_MEMBER_METHOD(GetViewModel, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_parameter_ViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(ViewModel, GetViewModel)
			END_CLASS_MEMBER(::gacpass::RegisterWindow)

			BEGIN_CLASS_MEMBER(::gacpass::RegisterWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::RegisterWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_RegisterWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_22)
				CLASS_MEMBER_FIELD(__vwsn_precompile_23)
				CLASS_MEMBER_FIELD(__vwsn_precompile_24)
				CLASS_MEMBER_FIELD(__vwsn_precompile_25)
				CLASS_MEMBER_FIELD(__vwsn_precompile_26)
				CLASS_MEMBER_FIELD(__vwsn_precompile_27)
				CLASS_MEMBER_FIELD(__vwsn_precompile_28)
				CLASS_MEMBER_FIELD(__vwsn_precompile_29)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_30)
				CLASS_MEMBER_FIELD(__vwsn_precompile_31)
				CLASS_MEMBER_FIELD(__vwsn_precompile_32)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(ViewModel)
				CLASS_MEMBER_FIELD(buttonSignUp)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textBoxConfirmPassword)
				CLASS_MEMBER_FIELD(textBoxPassword)
			END_CLASS_MEMBER(::gacpass::RegisterWindowConstructor)

			BEGIN_CLASS_MEMBER(::gacpass::TextEditor)
				CLASS_MEMBER_BASE(::vl::presentation::templates::GuiGridEditorTemplate)
				CLASS_MEMBER_BASE(::gacpass::TextEditorConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gacpass::TextEditor*(), NO_PARAMETER)
			END_CLASS_MEMBER(::gacpass::TextEditor)

			BEGIN_CLASS_MEMBER(::gacpass::TextEditorConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gacpass::TextEditorConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gacpass_TextEditor_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textBox)
			END_CLASS_MEMBER(::gacpass::TextEditorConstructor)

#undef _
			class GacPassTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::gacpass::CodeBookWindow)
					ADD_TYPE_INFO(::gacpass::CodeBookWindowConstructor)
					ADD_TYPE_INFO(::gacpass::HostType)
					ADD_TYPE_INFO(::gacpass::HostTypeDisplayer)
					ADD_TYPE_INFO(::gacpass::HostTypeDisplayerConstructor)
					ADD_TYPE_INFO(::gacpass::HostTypeEditor)
					ADD_TYPE_INFO(::gacpass::HostTypeEditorConstructor)
					ADD_TYPE_INFO(::gacpass::HostTypeItemTemplate)
					ADD_TYPE_INFO(::gacpass::HostTypeItemTemplateConstructor)
					ADD_TYPE_INFO(::gacpass::HostTypeVisualizer)
					ADD_TYPE_INFO(::gacpass::HostTypeVisualizerConstructor)
					ADD_TYPE_INFO(::gacpass::ICode)
					ADD_TYPE_INFO(::gacpass::ICodeBookViewModel)
					ADD_TYPE_INFO(::gacpass::IEditCodeViewModel)
					ADD_TYPE_INFO(::gacpass::IKey)
					ADD_TYPE_INFO(::gacpass::ILoginViewModel)
					ADD_TYPE_INFO(::gacpass::IReference)
					ADD_TYPE_INFO(::gacpass::IRegisterViewModel)
					ADD_TYPE_INFO(::gacpass::IViewModel)
					ADD_TYPE_INFO(::gacpass::LoginWindow)
					ADD_TYPE_INFO(::gacpass::LoginWindowConstructor)
					ADD_TYPE_INFO(::gacpass::MainWindow)
					ADD_TYPE_INFO(::gacpass::MainWindowConstructor)
					ADD_TYPE_INFO(::gacpass::ReferenceFilter)
					ADD_TYPE_INFO(::gacpass::ReferenceFilterConstructor)
					ADD_TYPE_INFO(::gacpass::RegisterWindow)
					ADD_TYPE_INFO(::gacpass::RegisterWindowConstructor)
					ADD_TYPE_INFO(::gacpass::TextEditor)
					ADD_TYPE_INFO(::gacpass::TextEditorConstructor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadGacPassTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<GacPassTypeLoader>());
				}
#endif
				return false;
			}
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
