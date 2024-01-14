#include "Routing.h"
#include <thread>
import random;
using namespace game;
import player;

void game::Routing::run(PlayerStorage& storage,Game& game, std::unordered_map<int, Player>& connectedPlayers)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is a Gartic Phone type of game";
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
		return addPlayerToGameRoute(storage, req, playerId);

		});

	CROW_ROUTE(m_app, "/submitanswer/<int>")([&storage, this](const crow::request& req, int playerId) {
		return submitAnswer(storage, req, playerId); 
		});
	CROW_ROUTE(m_app, "/drawingTable")([&game,this]() {

		std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>> drawingTable;
		drawingTable = game.getDrawingTable();
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
	CROW_ROUTE(m_app, "/addline")([&game, this](const crow::request& req) {
		return addLineToTableRoute(game, req);
		});
	CROW_ROUTE(m_app, "/verifyUser")([&storage, this](const crow::request& req) {
		return verifyPlayer(storage,req);
		});
	CROW_ROUTE(m_app, "/connectedPlayers")([&storage,&connectedPlayers, this](const crow::request& req) {
		return connectPlayer(storage, connectedPlayers,req);
		});

	CROW_ROUTE(m_app, "/disconnectPlayer")([&storage, &connectedPlayers,&game,this](const crow::request& req) {
		return disconnectPlayer(storage, connectedPlayers,game,req);
		});
	CROW_ROUTE(m_app, "/checkAlreadyConnected")([&storage, &connectedPlayers, this](const crow::request& req) {
		return checkAlreadyConnected(storage, connectedPlayers, req);
		});
	CROW_ROUTE(m_app,"/setLanguage")([&game, this](const crow::request& req) {
		return setLanguageRoute(game, req);
		});
	CROW_ROUTE(m_app, "/setDifficulty")([&game, this](const crow::request& req) {
		return setDifficultyRoute(game, req);
		});
	CROW_ROUTE(m_app, "/generateLobbyCode")([&game, this](const crow::request& req) {
		return generateLobbyCode(game, req);
		});
	CROW_ROUTE(m_app, "/getLobbyCode")([&game, this](const crow::request& req) {
		return getLobbyCode(game, req);
		});
	CROW_ROUTE(m_app, "/joinGameLobby")([&storage, &game, this](const crow::request& req) {
		return addPlayerToLobby(storage, game, req);
		});
	CROW_ROUTE(m_app, "/getCurrentDrawer")([&game,this](const crow::request& req) {
		return getCurrentDrawer(game, req);
		});
	CROW_ROUTE(m_app, "/checkIfWordIsCorrect")([&game,&storage,this](const crow::request& req) {
		return checkIfWordIsCorrect(game, storage, req);
		});
	CROW_ROUTE(m_app, "/players")([&game, this](const crow::request& req) {
		return getConnectedPlayers(game, req);
		});
	CROW_ROUTE(m_app, "/getWord")([&game, this](const crow::request& req) {
		return getWordforSubRound(game, req);
		});
	CROW_ROUTE(m_app, "/revealCharacters")([&game, this](const crow::request& req) {
		return getWordForGuessers(game, req);
		});
	CROW_ROUTE(m_app, "/run")([&game, &storage, this](const crow::request& req) {
		game.RunGame(storage);
		return crow::response(200);
		});



	m_app.port(18080).multithreaded().run();
}

crow::response game::Routing::addPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const
{
	char* username_chr = req.url_params.get("username");
	char* password_chr = req.url_params.get("password");
	char* email_chr = req.url_params.get("email");
	std::string username = "";
	std::string password = "";
	std::string email = "";
	if (username_chr != nullptr && password_chr != nullptr && email_chr!=nullptr) {
		username = std::string(username_chr);
		if (auto player = storage.checkUser(username); player.getUsername() == username)
			return crow::response(400);
		password = std::string(password_chr);
		email = std::string(email_chr);
		storage.addPlayerToStorage(username,password,email);
		return crow::response(200);
	}
	else {

		return crow::response(400);
	}
}

crow::response game::Routing::submitAnswer(PlayerStorage& storage, const crow::request& req, int playerId)
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

crow::response game::Routing::getAnswers(PlayerStorage& storage, int drawingId)
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

crow::response game::Routing::addLineToTableRoute(Game& game, const crow::request& req)
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
		game.DrawLine(line, color, width);
		return crow::response(200);
	}
	else
		return crow::response(400);
}

crow::response game::Routing::verifyPlayer(PlayerStorage& storage, const crow::request& req)
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

crow::response game::Routing::connectPlayer(PlayerStorage& storage,std::unordered_map<int,Player>& connectedPlayers, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		connectedPlayers[player.getId()] = player;
		return crow::response(200);
	}
	else
		return crow::response(401);
}

crow::response game::Routing::disconnectPlayer(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers,Game& game, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1) {
		std::erase_if(connectedPlayers, [&player](const auto& connectedPlayer) {
			return connectedPlayer.first == player.getId();
			});
		std::erase_if(game.getPlayers(), [&player](const auto& connectedPlayer) {
			return connectedPlayer.first == player.getId();
			});
		return crow::response(200);
	}
	else {
		return crow::response(401);
	}
}

crow::response game::Routing::checkAlreadyConnected(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		auto it = connectedPlayers.find(player.getId());
		if (it != connectedPlayers.end())
			return crow::response(200);
	}

	return crow::response(405);

}

crow::response game::Routing::setLanguageRoute(Game& game, const crow::request& req)
{
	char* languageChr = req.url_params.get("language");
	if (languageChr != nullptr)
	{
		int language = std::stoi(languageChr);
		game.setLanguage(language);
		return crow::response(200);
	}

	return crow::response(406);

}

crow::response game::Routing::setDifficultyRoute(Game& game, const crow::request& req)
{
	char* difficultyChr = req.url_params.get("difficulty");
	if ( difficultyChr!= nullptr)
	{
		int difficulty = std::stoi(difficultyChr);
		game.setDifficultyLevel(difficulty);
		return crow::response(200);
	}
	return crow::response();

}

crow::json::wvalue game::Routing::generateLobbyCode(Game& game, const crow::request& req)
{
	srand(time(0));
	uint32_t generatedCode = game::generateGameCode();
	game.setGameCode(generatedCode);
	crow::json::wvalue code{
		{"generatedCode",std::to_string(generatedCode)}
	};
	return code;
}

crow::json::wvalue game::Routing::getLobbyCode(Game& game, const crow::request& req)
{
	crow::json::wvalue code{
		{"generatedCode",std::to_string(game.getGameCode())}
	};
	return code;
}

crow::response game::Routing::addPlayerToLobby(PlayerStorage& storage, Game& game, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	if (player.getId() != -1)
	{
		game.addPlayerToGame(player);
		return crow::response(200);
	}

	return crow::response(405);
}

crow::json::wvalue game::Routing::getCurrentDrawer(Game& game, const crow::request& req)
{
	auto player = game.getCurrentDrawer();
	crow::json::wvalue drawer{
		{"username",player.getUsername()}
	};
	return drawer;
}

crow::response game::Routing::checkIfWordIsCorrect(Game& game,PlayerStorage& storage, const crow::request& req)
{
	char* username = req.url_params.get("username");
	auto player = storage.checkUser(username);
	char* wordChr = req.url_params.get("word");
	if (username != nullptr)
	{
		if (wordChr == game.getCurrentWord().getWord()) {
			game.getPlayers()[player.getId()].setGuessedWord(true);
			return crow::response(200);
		}
	}
	return crow::response(405);
}

crow::json::wvalue game::Routing::getConnectedPlayers(Game& game, const crow::request& req)
{
	std::vector<crow::json::wvalue> playersJSON;
	auto players = game.getPlayers();
	for (auto it : players)
	{
		playersJSON.push_back( crow::json::wvalue{{
			"username",it.second.getUsername()}
			} );
	}
	return crow::json::wvalue{playersJSON};
}

crow::json::wvalue game::Routing::getWordforSubRound(Game& game, const crow::request& req)
{
	return crow::json::wvalue{
		{"word",game.getCurrentWord().getWord()}
	};
}

crow::json::wvalue game::Routing::getWordForGuessers(Game& game, const crow::request& req)
{
	return crow::json::wvalue{
		{"word",game.revealCharacters()}
	};
}
