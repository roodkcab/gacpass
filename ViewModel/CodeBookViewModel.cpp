#include "CodeBookViewModel.h"

std::unique_ptr<std::string> WStringToString(const WString &string) {
	auto s = std::wstring(string.Buffer());
    return std::make_unique<std::string>(s.begin(), s.end());
}

WString WStringFromString(const std::string &s) {
	return WString(std::wstring(s.begin(), s.end()).c_str());
}

namespace sqlite_orm {

    template<>
    struct type_printer<WString> : public text_printer {};

    template<>
    struct statement_binder<WString> {
        int bind(sqlite3_stmt *stmt, int index, const WString &value) {
            if(auto str = WStringToString(value)) {
                return statement_binder<std::string>().bind(stmt, index, *str);
            }
			return statement_binder<std::nullptr_t>().bind(stmt, index, nullptr);
        }
    };

    template<>
    struct field_printer<WString> {
        std::string operator()(const WString &t) const {
			return *WStringToString(t);
        }
    };

    template<>
    struct row_extractor<WString> {
        WString extract(sqlite3_stmt *stmt, int columnIndex) {
            return WStringFromString((const char *)sqlite3_column_text(stmt, columnIndex));
        }
    };

    /**
     *  This is where sqlite_orm lib understands that your type is nullable - by
     *  specializing type_is_nullable<T> and deriving from std::true_type.
     */
    template<>
    struct type_is_nullable<WString> : public std::true_type {

        //  this function must return whether value null or not (false is null). Don't forget to implement it
        bool operator()(const WString &g) const {
            return g != L"";
        }
    };
}

CodeBookViewModel::CodeBookViewModel() 
	:storage(DBCodes())
{
	this->Load();
}

Ptr<IValueObservableList> CodeBookViewModel::GetCodes()
{
	return codes.GetWrapper();
}

Ptr<gacpass::ICode> CodeBookViewModel::GetSelectedCode()
{
	return selectedCode;
}

void CodeBookViewModel::SetSelectedCode(Ptr<gacpass::ICode> value)
{
	if (selectedCode != value)
	{
		selectedCode = value;
		SelectedCodeChanged();
	}
}

WString CodeBookViewModel::GetSearch()
{
	return search;
}

void CodeBookViewModel::SetSearch(const WString& value)
{
	if (value.Length() < search.Length())
	{
		this->Load();
	}
	search = value;
	List<Ptr<gacpass::ICode>> filteredCodes;
	CopyFrom(filteredCodes, codes);
	auto l = From(filteredCodes).Where([=](Ptr<gacpass::ICode> x) { return std::wstring(x.Obj()->GetWebsite().Buffer()).find(search.Buffer()) != std::string::npos; });

	codes.Clear();
	FOREACH(Ptr<gacpass::ICode>, code, l) codes.Add(code);
	this->SearchChanged();
}

Ptr<gacpass::ICode> CodeBookViewModel::CreateCode()
{
	return MakePtr<Code>();
}

void CodeBookViewModel::AddCode(Ptr<gacpass::ICode> code)
{
	codes.Add(code);
	storage.insert(Code(code));
}

void CodeBookViewModel::UpdateCode(Ptr<gacpass::ICode> code)
{
	vint index = codes.IndexOf(code.Obj());
	if (index != -1)
	{
		storage.update(Code(code));
		codes.NotifyUpdate(index, 1);
	}
}

void CodeBookViewModel::RemoveCode(Ptr<gacpass::ICode> code)
{
	codes.Remove(code.Obj());
	storage.remove<Code>(code->GetId());
}

void CodeBookViewModel::OnItemLeftButtonDoubleClick(GuiItemMouseEventArgs* arguments)
{
	auto code = codes.Get(arguments->itemIndex);
	if (code)
	{
		auto clipboard = GetCurrentController()->ClipboardService()->WriteClipboard();
		clipboard->SetText(code->GetPassword());
		clipboard->Submit();
	}
}

void CodeBookViewModel::Load()
{
	codes.Clear();
	storage.sync_schema();
	auto codes = storage.get_all<Code>();
	for (auto& code : codes)
	{
		this->codes.Add(MakePtr<Code>(code));
	}
}
