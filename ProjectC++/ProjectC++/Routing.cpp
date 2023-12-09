#include "Routing.h"

using namespace game;

void game::Routing::Run(PlayerStorage& storage)
{

}

crow::response game::Routing::AddPlayerToGameRoute(PlayerStorage& storage, const crow::request& req, int playerId) const
{
	return crow::response();
}
