#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"

using namespace vl;

class EditCodeViewModel : public virtual gacpass::IEditCodeViewModel
{
private:
	Ptr<gacpass::ICode> code;
	vint codeLength = 10;
	vint specialCharLength = 0;

public:
	EditCodeViewModel();
	EditCodeViewModel(Ptr<gacpass::ICode> code);
	Ptr<gacpass::ICode> GetCode()override;
	void SetCode(Ptr<gacpass::ICode> code)override;
	vint GetCodeLength()override;
	void SetCodeLength(vint codeLength)override;
	vint GetSpecialCharLength()override;
	void SetSpecialCharLength(vint specialCharLength)override;

private:
	WString genCode(const int length, const int specialCharLength);
};

