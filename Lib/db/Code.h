#pragma once
#define GAC_HEADER_USE_NAMESPACE
#include "Gacpass.h"
#include "Reference.h"
#include <string>

using namespace vl;
using namespace vl::collections;
using namespace vl::reflection::description;

class Code : public Object, public virtual gacpass::ICode
{
private:
	int id;
	WString	title;
	WString	username;
	WString	password;
	ObservableList<Ptr<gacpass::IReference>> references;

public:
	Code();
	//Code(const int _id, const WString& _title, const WString& _username, const WString& _password);
	Code(const Code& code);
	int GetId()const override;
	void SetId(const int _id)override;
	WString GetTitle()const override;
	void SetTitle(const WString& _website)override;
	WString GetUsername()const override;
	void SetUsername(const WString& _username)override;
	WString GetPassword()const override;
	void SetPassword(const WString& _password)override;
	WString GetHidePassword()override;
	Ptr<IValueObservableList> GetReferences()override;

	void Update(Ptr<ICode> code)override;
  };
