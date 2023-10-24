#pragma once
#include <vector>
#include "Player.h"
#include "Round.h"
class Game
{
public:

private:
	std::vector<Player> m_players;
	std::vector<Round> m_rounds;
	uint8_t m_currentRound;



};

