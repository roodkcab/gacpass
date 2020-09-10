#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"

using namespace vl;

class EditCodeViewModel : public virtual gacpass::IEditCodeViewModel
{
private:
	Ptr<gacpass::ICode> code;
	Ptr<gacpass::IReference> selectedReference;
	vint codeLength = 0;
	vint specialCharLength = 0;

public:
	EditCodeViewModel();
	EditCodeViewModel(Ptr<gacpass::ICode> code);
	Ptr<gacpass::IReference> GetSelectedReference()override;
	void SetSelectedReference(Ptr<gacpass::IReference> value)override;
	Ptr<gacpass::ICode> GetCode()override;
	vint GetCodeLength()override;
	void SetCodeLength(vint codeLength)override;
	vint GetSpecialCharLength()override;
	void SetSpecialCharLength(vint specialCharLength)override;
	void Clear()override;

private:
	WString genCode();
};

