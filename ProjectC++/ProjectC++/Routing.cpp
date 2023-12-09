#include "Routing.h"

using namespace game;

import player;

void game::Routing::Run(PlayerStorage& storage)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is a Gartic Phone type of game";
		});
	CROW_ROUTE(m_app, "/players")([&storage]() {
		std::vector<crow::json::wvalue> players_json;

	auto players = storage.getPlayers();
	for (const auto& player : players)
	{
		players_json.push_back(crow::json::wvalue{
			{"id", player.getId()},  // product_json["id"] = product.id;
			{"username", player.getUsername()},
			{"password", player.getPassword()},
			{"email", player.getEmail()}
			});

		//std::string product_json = db.dump(product);	
	}
	return crow::json::wvalue{ players_json };
		});
}

crow::response game::Routing::AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const
{
	char* username_chr = req.url_params.get("username");
	char* password_chr = req.url_params.get("password");
	char* email_chr = req.url_params.get("email");



	return crow::response(200);
}
