#pragma once
#include <crow.h>
#include "playersDatabase.h"

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

	private:
		crow::SimpleApp m_app;
	};
}
