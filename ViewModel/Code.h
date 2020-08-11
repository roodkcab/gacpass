#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include <string>

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

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
	int GetId()override;
	void SetId(const int _id)override;
	WString GetWebsite()override;
	void SetWebsite(const WString& _website)override;
	WString GetUsername()override;
	void SetUsername(const WString& _username)override;
	WString GetPassword()override;
	void SetPassword(const WString& _password)override;
	WString GetHidePassword()override;
	void Update(const int _id, const WString& _website, const WString& _username, const WString& _password)override;
  };
