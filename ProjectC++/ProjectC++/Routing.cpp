#include "Routing.h"

import random;
using namespace game;
import player;

void game::Routing::Run(PlayerStorage& storage)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is a Gartic Phone type of game";
		});
	CROW_ROUTE(m_app, "/players")([&storage]() {
		std::vector<crow::json::wvalue> players_json;

		auto players = storage.getGame().getPlayers();
		for (const auto& player : players)
		{
			players_json.push_back(crow::json::wvalue{
				{"id", player.second.getId()}, 
				{"username", player.second.getUsername()},
				{"email", player.second.getEmail()}
			});

		}
		return crow::json::wvalue{ players_json };
		});
	CROW_ROUTE(m_app, "/words")([&storage]() {
		std::vector<crow::json::wvalue>words_json;
		auto words = storage.getWords();
		for (const auto& word : words)
		{
			words_json.push_back(crow::json::wvalue{
				{"id", word.getId()},
				{"word", word.getWord()},
				{"difficulty", word.getDifficulty()},
				{"language",word.getLanguage()}
				});

		}
		return crow::json::wvalue{ words_json };
		});
	CROW_ROUTE(m_app, "/addplayertogame/<int>")([&storage, this](const crow::request& req, int playerId) {
		return AddPlayerToGameRoute(storage, req, playerId);

		});

	/*CROW_ROUTE(m_app, "/startround")([&storage, this]() {
		return StartNewRoundRoute(storage);
		});*/

	CROW_ROUTE(m_app, "/startsubround")([&storage, this]() {
		if (storage.getGame().isReadyForNewSubround()) {
			storage.getGame().startSubround();
			return crow::response("Subround started.");
		}
		else {
			return crow::response(400, "Bad Request - Game not ready for a new subround");
		}
		});

	CROW_ROUTE(m_app, "/revealletters/<int>")([&storage, this](const crow::request& req, int playerId) {
		return RevealLetters(storage, req, playerId);
		});

	CROW_ROUTE(m_app, "/submitanswer/<int>")([&storage, this](const crow::request& req, int playerId) {
		return SubmitAnswer(storage, req, playerId); 
		});// TODO

	CROW_ROUTE(m_app, "/getword")([this, &storage]() {
		return this->GetWordRoute(storage);
		});
	CROW_ROUTE(m_app, "/drawingTable")([&storage,this]() {

		std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>> drawingTable;
		drawingTable = storage.getGame().getDrawingTable();
		std::vector<crow::json::wvalue> drawingTable_json;
		for (const auto& line : drawingTable)
		{
			const auto& [lineCoordinates, color, width] = line;
			const auto& [startPoint, finalPoint] = lineCoordinates;
			drawingTable_json.push_back(crow::json::wvalue{
				{"startPointX",startPoint.first},
				{"startPointY",startPoint.second},
				{"finalPointX",finalPoint.first},
				{"finalPointY",finalPoint.second},
				{"color",color},
				{"width",width}
				});
		}
		return crow::json::wvalue{ drawingTable_json};
		});
	CROW_ROUTE(m_app, "/addline")([&storage, this](const crow::request& req) {
		return AddLineToTableRoute(storage, req);
		});
	/*CROW_ROUTE(m_app, "/finalrankings")([&storage, this]() {
		return GetFinalRankings(storage);
		});*/
	// de calculat aici si scorul total 
	CROW_ROUTE(m_app, "/verifyUser")([&storage, this](const crow::request& req) {
		return VerifyPlayer(storage,req);
		});
	CROW_ROUTE(m_app, "/connectedPlayers")([&storage, this](const crow::request& req) {
		return connectPlayer(storage, req);
		});

	CROW_ROUTE(m_app, "/disconnectPlayer")([&storage,this](const crow::request& req) {
		return disconnectPlayer(storage, req);
		});
	CROW_ROUTE(m_app, "/checkAlreadyConnected")([&storage, this](const crow::request& req) {
		return CheckAlreadyConnected(storage, req);
		});
	CROW_ROUTE(m_app,"/setLanguage")([&storage, this](const crow::request& req) {
		return SetLanguageRoute(storage, req);
		});
	CROW_ROUTE(m_app, "/setDifficulty")([&storage, this](const crow::request& req) {
		return SetDifficultyRoute(storage, req);
		});
	CROW_ROUTE(m_app, "/getLobbyCode")([&storage, this](const crow::request& req) {
		return getLobbyCode(storage, req);
		});
	


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

		return crow::response(400);
	}
}

//crow::response game::Routing::StartNewRoundRoute(PlayerStorage& storage) const
//{
//	Game& game = storage.getGame();
//	game.startNewRound();
//	return crow::response{ "New round started." };
//}

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

crow::response game::Routing::AddLineToTableRoute(PlayerStorage& storage, const crow::request& req)
{
	char* startPointX_chr = req.url_params.get("startPointX");
	char* startPointY_chr = req.url_params.get("startPointY");
	char* finalPointX_chr = req.url_params.get("finalPointX");
	char* finalPointY_chr = req.url_params.get("finalPointY");
	char* color_chr = req.url_params.get("color");
	char* width_chr = req.url_params.get("width");
	if (startPointX_chr != nullptr && startPointY_chr != nullptr && finalPointX_chr != nullptr && finalPointY_chr != nullptr && color_chr != nullptr && width_chr != nullptr)
	{
		float startPointX = std::stof(startPointX_chr);
		float startPointY = std::stof(startPointY_chr);
		float finalPointX = std::stof(finalPointX_chr);
		float finalPointY = std::stof(finalPointY_chr);
		std::string color = std::string(color_chr);
		uint8_t width = std::stoi(width_chr);
		std::pair<std::pair<float, float>, std::pair<float, float>>line = std::make_pair(std::make_pair(startPointX, startPointY), std::make_pair(finalPointX, finalPointY));
		storage.addLine(line, color, width);
		return crow::response(200);
	}
	else
		return crow::response(400);
}

crow::response game::Routing::VerifyPlayer(PlayerStorage& storage, const crow::request& req)
{
	char* username = req.url_params.get("username");
	char* password = req.url_params.get("password");
	if (username != nullptr && password != nullptr) {
		auto player = storage.checkUser(username);
		if (player.getId() != -1)
		{
			if (player.getPassword() == password)
				return crow::response(200);
		}
	}
	return crow::response(401);

}

crow::response game::Routing::connectPlayer(PlayerStorage& storage, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		storage.getGame().addPlayerToGame(player);
		return crow::response(200);
	}
	else
		return crow::response(401);
}

crow::response game::Routing::disconnectPlayer(PlayerStorage& storage, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		storage.getGame().disconnetPlayer(player);
		return crow::response(200);
	}
	else
		return crow::response(401);
}

crow::response game::Routing::CheckAlreadyConnected(PlayerStorage& storage, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		auto players = storage.getGame().getPlayers();
		auto it = players.find(player.getId());
		if (it != players.end())
			return crow::response(200);
	}

	return crow::response(405);

}

crow::response game::Routing::SetLanguageRoute(PlayerStorage& storage, const crow::request& req)
{
	char* languageChr = req.url_params.get("language");
	if (languageChr != nullptr)
	{
		int language = std::stoi(languageChr);
		storage.getGame().setLanguage(language);
		return crow::response(200);
	}

	return crow::response(406);

}

crow::response game::Routing::SetDifficultyRoute(PlayerStorage& storage, const crow::request& req)
{
	char* difficultyChr = req.url_params.get("difficulty");
	if ( difficultyChr!= nullptr)
	{
		int difficulty = std::stoi(difficultyChr);
		storage.getGame().setDifficultyLevel(difficulty);
		return crow::response(200);
	}
	return crow::response();

}

crow::json::wvalue game::Routing::getLobbyCode(PlayerStorage& storage, const crow::request& req)
{
	srand(time(0));
	int generatedCode = game::generateGameCode();
	crow::json::wvalue code{
		{"generatedCode",std::to_string(generatedCode)}
	};
	return code;
}

