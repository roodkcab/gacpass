#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "DB.h"

class LoginViewModel : public Object, public virtual gacpass::ILoginViewModel 
{
private:
	WString password;
	decltype(DB())* storage;

public:
	LoginViewModel();
	void Load(decltype(DB())& _storage);
	WString GetPassword()override;
	void SetPassword(const WString& value)override;
	bool GetLoggedIn()override;
};
