#pragma once
#include <crow.h>
#include "playersDatabase.h"
#include <crow.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <unordered_map>
#include "Game.h"


namespace game
{
	class Routing
	{
	public:
		void run(PlayerStorage& storage,Game& game,std::unordered_map<int,Player>& connectedPlayers);


	private:
		crow::response addPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const;
		crow::response submitAnswer(PlayerStorage& storage, const crow::request& req, int playerId);
		static crow::response getAnswers(PlayerStorage& storage, int drawingId);
		crow::response addLineToTableRoute(Game& game, const crow::request& req);
		crow::response verifyPlayer(PlayerStorage& storage, const crow::request& req);
		crow::response connectPlayer(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req);
		crow::response disconnectPlayer(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers,Game& game, const crow::request& req);
		crow::response checkAlreadyConnected(PlayerStorage& storage, std::unordered_map<int, Player>& connectedPlayers, const crow::request& req);
		crow::response setLanguageRoute(Game& game, const crow::request& req);
		crow::response setDifficultyRoute(Game& game, const crow::request& req);
		crow::json::wvalue generateLobbyCode(Game& game, const crow::request& req);
		crow::json::wvalue getLobbyCode(Game& game, const crow::request& req);
		crow::response addPlayerToLobby(PlayerStorage& storage, Game& game, const crow::request& req);
		crow::json::wvalue getCurrentDrawer(Game& game, const crow::request& req);
		crow::response checkIfWordIsCorrect(Game& game,PlayerStorage& storage, const crow::request& req);
		crow::json::wvalue getConnectedPlayers(Game& game, const crow::request& req);
		crow::json::wvalue getWordforSubRound(Game& game, const crow::request& req);
		crow::json::wvalue getWordForGuessers(Game& game, const crow::request& req);
	private:
		crow::SimpleApp m_app;
	};
}
