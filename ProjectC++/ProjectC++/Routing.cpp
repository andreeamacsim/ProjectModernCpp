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

	}
	return crow::json::wvalue{ players_json };
		});
	CROW_ROUTE(m_app, "/addplayertogame/<int>")([&storage, this](const crow::request& req, int playerId) {
		return AddPlayerToGameRoute(storage, req, playerId);

		});
	m_app.port(18080).multithreaded().run();

	CROW_ROUTE(m_app, "/startround")([&storage, this]() {
		return StartNewRoundRoute(storage);
		});

	/*CROW_ROUTE(m_app, "/draw/<int>")([&storage, this](const crow::request& req, int playerId) {
		return ProcessDrawing(storage, req, playerId);
		});*/

	CROW_ROUTE(m_app, "/revealletters/<int>")([&storage, this](const crow::request& req, int playerId) {
		return RevealLetters(storage, req, playerId);
		});

	CROW_ROUTE(m_app, "/submitanswer/<int>")([&storage, this](const crow::request& req, int playerId) {
		return SubmitAnswer(storage, req, playerId);
		});// TODO

	/*CROW_ROUTE(m_app, "/finalrankings")([&storage, this]() {
		return GetFinalRankings(storage);
		});*/


}

crow::response game::Routing::AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const
{
	char* username_chr = req.url_params.get("username");
	char* password_chr = req.url_params.get("password");
	char* email_chr = req.url_params.get("email");

	storage.AddPlayerToStorage(username_chr, password_chr, email_chr);

	return crow::response(200);
}

crow::response game::Routing::StartNewRoundRoute(PlayerStorage& storage) const
{
	Game& game = storage.getGame();
	game.StartNewRound();
	return crow::response{ "New round started." };
}

crow::response game::Routing::RevealLetters(PlayerStorage& storage, const crow::request& req, int playerId)
{
	Word currentWord = storage.GetCurrentWord();
	std::string revealedLetters = currentWord.revealCharacter();
	return crow::response(revealedLetters);
}

crow::response game::Routing::SubmitAnswer(PlayerStorage& storage, const crow::request& req, int playerId)
{
	// de implementat de Cristina 
	return crow::response();
}
