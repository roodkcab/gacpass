#ifndef ORM_HOSTTYPE_H_
#define ORM_HOSTTYPE_H_

#include "GacPass.h"
#include <string>
#include <sqlite_orm/sqlite_orm.h>

using namespace vl;
using namespace sqlite_orm;

int HostTypeToInt(const gacpass::HostType& type);
gacpass::HostType HostTypeFromInt(const int s);

namespace sqlite_orm {

    template<>
    struct type_printer<gacpass::HostType> : public integer_printer {};

    template<>
    struct statement_binder<gacpass::HostType> {
        int bind(sqlite3_stmt *stmt, int index, const gacpass::HostType& value) {
			return statement_binder<int>().bind(stmt, index, HostTypeToInt(value));
        }
    };

    template<>
    struct field_printer<gacpass::HostType> {
        int operator()(const gacpass::HostType& t) const {
			return HostTypeToInt(t);
        }
    };

    template<>
    struct row_extractor<gacpass::HostType> {
        gacpass::HostType extract(sqlite3_stmt *stmt, int columnIndex) {
            return HostTypeFromInt((int)sqlite3_column_int(stmt, columnIndex));
        }
    };
}

#endif
