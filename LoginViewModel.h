#define GAC_HEADER_USE_NAMESPACE
#include "UI/Source/GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

class LoginViewModel : public Object, public virtual gacpass::ILoginViewModel 
{
private:
	WString password;

public:
	LoginViewModel();
	WString GetPassword()override;
	void SetPassword(const WString& value)override;
};
