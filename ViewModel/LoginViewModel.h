#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "db/DB.h"

class LoginViewModel : public Object, public virtual gacpass::ILoginViewModel 
{
private:
	WString password;

public:
	LoginViewModel();
	WString GetPassword()override;
	void SetPassword(const WString& value)override;
	bool GetLoggedIn()override;
};
