#pragma once
#include <crow.h>
#include "playersDatabase.h"
#include <crow.h>
#include <cstdlib>
#include <ctime>
#include <sstream>


namespace game
{
	class Routing
	{
	public:
		void Run(PlayerStorage& storage);

	private:
		crow::response AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const;
		crow::response StartNewRoundRoute(PlayerStorage& storage) const;
		crow::response RevealLetters(PlayerStorage& storage, const crow::request& req, int playerId);
		crow::response SubmitAnswer(PlayerStorage& storage, const crow::request& req, int playerId);
		static crow::response GetAnswers(PlayerStorage& storage, int drawingId);
		static std::string GenerateUniqueLobbyCode();
		crow::response GetWordRoute(PlayerStorage& storage);
		crow::response AddLineToTableRoute(PlayerStorage& storage, const crow::request& req);
		crow::response VerifyPlayer(PlayerStorage& storage, const crow::request& req);
		crow::response connectPlayer(PlayerStorage& storage, const crow::request& req);
		crow::response disconnectPlayer(PlayerStorage& storage, const crow::request& req);
		crow::response CheckAlreadyConnected(PlayerStorage& storage, const crow::request& req);
		crow::response SetLanguageRoute(PlayerStorage& storage, const crow::request& req);
		crow::response SetDifficultyRoute(PlayerStorage& storage, const crow::request& req);
	private:
		crow::SimpleApp m_app;
	};
}
