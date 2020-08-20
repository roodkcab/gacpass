#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "DB.h"

using namespace vl::collections;
using namespace vl::reflection::description;

class CodeBookViewModel : public Object, public virtual gacpass::ICodeBookViewModel
{
private:
	ObservableList<Ptr<gacpass::ICode>> codes;
	Ptr<gacpass::ICode> selectedCode;
	WString search;
	decltype(DB())* storage;

public:
	CodeBookViewModel();
	void Load(decltype(DB())& _storage);
	Ptr<IValueObservableList> GetCodes()override;
	Ptr<gacpass::ICode> GetSelectedCode()override;
	void SetSelectedCode(Ptr<gacpass::ICode> value)override;
	WString GetSearch()override;
	void SetSearch(const WString& search)override;
	Ptr<gacpass::IEditCodeViewModel> CreateEditCodeViewModel()override;
	void AddCode(Ptr<gacpass::ICode> code)override;
	void UpdateCode(Ptr<gacpass::ICode> code)override;
	void RemoveCode(Ptr<gacpass::ICode> code)override;
	void OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)override;

};
