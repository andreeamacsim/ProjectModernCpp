#pragma once
#include "Game.h"
#include "playersDatabase.h"
#include "Routing.h"
using namespace game;
class ExtraClass
{
public:
	void RunGame();
private:
	Routing m_r;
	Game m_game;
	PlayerStorage m_storage;
	std::unordered_map<int, Player> m_connectedPlayers;
};

