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

	private:
		crow::SimpleApp m_app;
	};
}
