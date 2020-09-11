#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "db/DB.h"

using namespace vl::collections;
using namespace vl::reflection::description;

class CodeBookViewModel : public Object, public virtual gacpass::ICodeBookViewModel
{
private:
	ObservableList<Ptr<gacpass::ICode>> codes;
	Ptr<gacpass::ICode> selectedCode;
	WString host;
	WString username;
	Ptr<gacpass::ILoginViewModel> loginViewModel;

public:
	CodeBookViewModel(Ptr<gacpass::ILoginViewModel> _loginViewModel);
	void Load();
	Ptr<IValueObservableList> GetCodes()override;
	Ptr<gacpass::ICode> GetSelectedCode()override;
	void SetSelectedCode(Ptr<gacpass::ICode> value)override;
	WString GetSearch()override;
	void SetSearch(const WString& search)override;
	Ptr<gacpass::ICode> AddCode()override;
	void UpdateCode(Ptr<gacpass::ICode> code)override;
	void RemoveCode(Ptr<gacpass::ICode> code)override;
	void OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)override;

private:
	void updateReference(Ptr<gacpass::ICode> code);
	void search();

};
