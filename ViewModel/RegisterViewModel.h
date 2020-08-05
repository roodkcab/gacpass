#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

class RegisterViewModel : public Object, public virtual gacpass::IRegisterViewModel
{
private:
	WString password;
	WString confirmPassword;
	Regex regexLcLetters;
	Regex regexUcLetters;
	Regex regexNumbers;

public:
	RegisterViewModel();
	WString GetPassword()override;
	void SetPassword(const WString& value)override;
	WString GetPasswordError()override;
	WString GetConfirmPassword()override;
	void SetConfirmPassword(const WString& value)override;
	WString GetConfirmPasswordError()override;
	bool GetMainPasswordSet()override;
	void Register()override;
};
