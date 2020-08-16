#pragma once
#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include <string>

using namespace vl;

class Code : public Object, public virtual gacpass::ICode
{
private:
	int id;
	WString	website;
	WString	username;
	WString	password;

public:
	Code();
	Code(const int _id, const WString& _website, const WString& _username, const WString& _password);
	Code(const Code& code);
	vint GetId()const override;
	void SetId(const vint _id)override;
	WString GetWebsite()const override;
	void SetWebsite(const WString& _website)override;
	WString GetUsername()const override;
	void SetUsername(const WString& _username)override;
	WString GetPassword()const override;
	void SetPassword(const WString& _password)override;
	WString GetHidePassword()const override;
	void Update(const vint _id, const WString& _website, const WString& _username, const WString& _password)override;
  };
