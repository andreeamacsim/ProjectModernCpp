#include "Game.h"
Game::Game()
{
}

Game::Game(const std::vector<Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList,  uint8_t currentRound, Player currentDrawer)
	: m_players(players)
	, m_rounds(rounds)
	, m_wordList(wordList)
	, m_currentRound(currentRound)
	, m_currentDrawer(currentDrawer)
{
}

void Game::setPlayers( const std::vector<Player>& players)
{
	m_players = players;
}

void Game::setRounds(const std::vector<Round>& rounds)
{
	m_rounds = rounds;
}

void Game::setWordList(const std::vector<Word>& wordList)
{
	m_wordList = wordList;
}

void Game::setCurrentRound(uint8_t currentRound)
{
	m_currentRound = currentRound;
}

void Game::setCurrentPlayer(Player currentDrawer)
{
	m_currentDrawer = currentDrawer;
}
