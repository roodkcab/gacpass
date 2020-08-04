#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;

class CodeBookViewModel : public Object, public virtual gacpass::ICodeBookViewModel
{
private:
	ObservableList<Ptr<gacpass::ICode>> codes;
	Ptr<gacpass::ICode> selectedCode;

public:
	CodeBookViewModel();
	Ptr<IValueObservableList> GetCodes()override;
	Ptr<gacpass::ICode> GetSelectedCode()override;
	void SetSelectedCode(Ptr<gacpass::ICode> value)override;
	Ptr<gacpass::ICode> CreateCode()override;
	void AddCode(Ptr<gacpass::ICode> code)override;
	void NotifyUpdate(gacpass::ICode* code)override;

private:
	void Load();
	void Store();
};
