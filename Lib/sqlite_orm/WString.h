#ifndef ORM_WSTRING_H_
#define ORM_WSTRING_H_

#include "Vlpp.h"
#include <string>
#include <sqlite_orm/sqlite_orm.h>

using namespace vl;
using namespace sqlite_orm;

std::unique_ptr<std::string> WStringToString(const WString& string);
WString WStringFromString(const std::string& s);

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
        std::string operator()(const WString& t) const {
			return *WStringToString(t);
        }
    };

    template<>
    struct row_extractor<WString> {
        WString extract(sqlite3_stmt *stmt, int columnIndex) {
            return WStringFromString((const char *)sqlite3_column_text(stmt, columnIndex));
        }
    };

    template<>
    struct type_is_nullable<WString> : public std::true_type {
        bool operator()(const WString& g) const {
            return g != L"";
        }
    };
}

#endif