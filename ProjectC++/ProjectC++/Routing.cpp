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
				{"id", player.getId()}, 
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

	CROW_ROUTE(m_app, "/getword")([this, &storage]() {
		return this->GetWordRoute(storage);
		});


	/*CROW_ROUTE(m_app, "/finalrankings")([&storage, this]() {
		return GetFinalRankings(storage);
		});*/
	// de calculat aici si scorul total 

	


	m_app.port(18080).multithreaded().run();
}

crow::response game::Routing::AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const
{
	char* username_chr = req.url_params.get("username");
	char* password_chr = req.url_params.get("password");
	char* email_chr = req.url_params.get("email");
	std::string username = "";
	std::string password = "";
	std::string email = "";
	if (username_chr != nullptr && password_chr != nullptr && email_chr!=nullptr) {
		username = std::string(username_chr);
		password = std::string(password_chr);
		email = std::string(email_chr);
		storage.AddPlayerToStorage(username,password,email);
		return crow::response(200);
	}
	else {
		// Întoarce o eroare sau răspuns corespunzător
		return crow::response(400);
	}
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
	if (!req.body.empty()) 
	{
		std::string playerAnswer = req.body;

		std::string responseMessage = "Răspunsul de la jucătorul " + std::to_string(playerId) + ": " + playerAnswer;
		return crow::response(responseMessage);
	}
	else 
	{
		return crow::response(400, "Bad Request - Empty request body");
	};

	
}

crow::response game::Routing::GetAnswers(PlayerStorage& storage, int drawingId)
{
	std::ostringstream responseStream;
	responseStream << "Drawing ID: " << drawingId << "\n";
	responseStream << "Answers: Câine, Casă, Soare";

	return crow::response(responseStream.str());
	//CROW_ROUTE(app, "/get-answers/<int>")
	//	.methods("GET"_method)
	//	([](const crow::request& req, int drawingId) {
	//	return Routing::GetAnswers(PlayerStorage(), drawingId);
	//		});

	//app.port(8080).multithreaded().run();
}

std::string game::Routing::GenerateUniqueLobbyCode()
{
	std::srand(static_cast<unsigned>(std::time(0)));
	std::ostringstream lobbyCodeStream;
	for (int i = 0; i < 6; ++i) {
		lobbyCodeStream << static_cast<char>('A' + (std::rand() % 26));
	}

	return lobbyCodeStream.str();

}

crow::response game::Routing::GetWordRoute(PlayerStorage& storage)
{
	Word currentWord = storage.GetCurrentWord();
	std::string word = currentWord.getWord();
	return crow::response(word);
}
