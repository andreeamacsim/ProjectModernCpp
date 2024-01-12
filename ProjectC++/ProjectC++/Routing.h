#pragma once
#include <crow.h>
#include "playersDatabase.h"
#include <crow.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <unordered_map>
import GameModule;


namespace game
{
	class Routing
	{
	public:
		void Run(PlayerStorage& storage,Game& game,std::unordered_map<int,Player>& connectedPlayers);


	private:
		crow::response AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const;
		crow::response StartNewRoundRoute(Game& storage) const;
		crow::response RevealLetters(PlayerStorage& storage, const crow::request& req, int playerId);
		crow::response SubmitAnswer(PlayerStorage& storage, const crow::request& req, int playerId);
		static crow::response GetAnswers(PlayerStorage& storage, int drawingId);
		static std::string GenerateUniqueLobbyCode();
		crow::response GetWordRoute(PlayerStorage& storage);
		crow::response AddLineToTableRoute(Game& game, const crow::request& req);
		crow::response VerifyPlayer(PlayerStorage& storage, const crow::request& req);
		crow::response connectPlayer(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req);
		crow::response disconnectPlayer(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req);
		crow::response CheckAlreadyConnected(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req);
		crow::response SetLanguageRoute(Game& game, const crow::request& req);
		crow::response SetDifficultyRoute(Game& game, const crow::request& req);
		crow::json::wvalue generateLobbyCode(Game& game, const crow::request& req);
		crow::json::wvalue getLobbyCode(Game& game, const crow::request& req);
		crow::response addPlayerToLobby(PlayerStorage& storage, Game& game, const crow::request& req);

	private:
		crow::SimpleApp m_app;
	};
}
