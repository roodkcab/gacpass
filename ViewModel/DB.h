#pragma once
#include "GacPass.h"
#include "util.hpp"
#include "Code.h"
#include "Key.h"
#include "sqlite_orm/WString.h"

using namespace vl;

template <typename... Args>
auto DB()
{
	return make_storage(Appdata(L"/gacpass.db"),
		make_table("account",
			make_column("id", &Key::GetId, &Key::SetId, autoincrement(), primary_key()),
			make_column("key", &Key::GetKey, &Key::SetKey)
		),
		make_table("codes",
			make_column("id", &Code::GetId, &Code::SetId, autoincrement(), primary_key()),
			make_column("website", &Code::GetWebsite, &Code::SetWebsite),
			make_column("username", &Code::GetUsername, &Code::SetUsername),
			make_column("password", &Code::GetPassword, &Code::SetPassword)
		)
	);
}
