#pragma once
#include "GacPass.h"
#include "util.hpp"
#include "db/Code.h"
#include "db/Key.h"
#include "db/Reference.h"
#include "sqlite_orm/WString.h"
#include "sqlite_orm/HostType.h"

using namespace vl;

template <typename... Args>
auto _DB()
{
	return make_storage(Appdata(L"\\gacpass.db"), 
		make_table("account",
			make_column("id", &Key::GetId, &Key::SetId, autoincrement(), primary_key()),
			make_column("key", &Key::GetKey, &Key::SetKey)
		),
		make_table("codes",
			make_column("id", &Code::GetId, &Code::SetId, autoincrement(), primary_key()),
			make_column("title", &Code::GetTitle, &Code::SetTitle),
			make_column("username", &Code::GetUsername, &Code::SetUsername),
			make_column("password", &Code::GetPassword, &Code::SetPassword)
		),
		make_table("references",
			make_column("id", &Reference::GetId, &Reference::SetId, autoincrement(), primary_key()),
			make_column("code_id", &Reference::GetCodeId, &Reference::SetCodeId),
			make_column("type", &Reference::GetType, &Reference::SetType),
			make_column("content", &Reference::GetContent, &Reference::SetContent)
		)
	);
}

static decltype(_DB()) DB()
{
	static decltype(_DB()) db = _DB();
	return db;
}

#define DB DB()
