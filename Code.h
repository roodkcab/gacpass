#define GAC_HEADER_USE_NAMESPACE
#include "UI/Source/GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

class Code : public Object, public virtual gacpass::ICode
{
private:
	WString	website;
	WString	username;
	WString	password;

public:
	Code();
	WString GetWebsite()override;
	WString GetUsername()override;
	WString GetPassword()override;
	void Update(Ptr<gacpass::ICodeBookViewModel> _viewmodel, const WString& _website, const WString& _username, const WString& _password);
};
