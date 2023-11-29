#pragma once

#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;

import player;

inline auto CreateStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"Player",
			sql::make_column("username", &Player::setUsername, &Player::getUsername, sql::primary_key()),
			sql::make_column("password", &Player::setPassword, &Player::getPassword),
			sql::make_column("e-mail", &Player::setEmail, &Player::getEmail)
		)
	);
}
using Storage = decltype(CreateStorage(""));


class PlayerStorage
{
public:
private:

private:
	const std::string kDbFile{ "players.sqlite" };
private:
	Storage m_db = CreateStorage(kDbFile);
};
