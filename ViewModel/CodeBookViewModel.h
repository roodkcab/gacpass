#define GAC_HEADER_USE_NAMESPACE
#include "GacPass.h"
#include "Code.h"
#include "util.hpp"
#include <sqlite_orm/sqlite_orm.h>

using namespace vl::collections;
using namespace vl::stream;
using namespace vl::regex;
using namespace vl::reflection::description;
using namespace sqlite_orm;

template <typename... Args>
auto DBCodes()
{
	return make_storage("gacpass.db", 
		make_table("codes",
			make_column("id", &Code::GetId, &Code::SetId, autoincrement(), primary_key()),
			make_column("website", &Code::GetWebsite, &Code::SetWebsite),
			make_column("username", &Code::GetUsername, &Code::SetUsername),
			make_column("password", &Code::GetPassword, &Code::SetPassword)
		)
	);
}

class CodeBookViewModel : public Object, public virtual gacpass::ICodeBookViewModel
{
private:
	ObservableList<Ptr<gacpass::ICode>> codes;
	Ptr<gacpass::ICode> selectedCode;
	WString search;
	decltype(DBCodes()) storage;

public:
	CodeBookViewModel();
	Ptr<IValueObservableList> GetCodes()override;
	Ptr<gacpass::ICode> GetSelectedCode()override;
	void SetSelectedCode(Ptr<gacpass::ICode> value)override;

	WString GetSearch()override;
	void SetSearch(const WString& search)override;

	Ptr<gacpass::ICode> CreateCode()override;
	void AddCode(Ptr<gacpass::ICode> code)override;
	void UpdateCode(Ptr<gacpass::ICode> code)override;
	void RemoveCode(Ptr<gacpass::ICode> code)override;

	void OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)override;

private:
	void Load();
};
