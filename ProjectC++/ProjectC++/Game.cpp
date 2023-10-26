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

void Game::setCurrentDrawer(Player currentDrawer)
{
	m_currentDrawer = currentDrawer;
}

std::vector<Player>& Game::getPlayers()
{
	return this->m_players;
}

std::vector<Round>& Game::getRounds()
{
	return this->m_rounds;
}

std::vector<Word>& Game::getWordsList()
{
	return this->m_wordList;
}

uint8_t Game::getCurrentRound()
{
	return m_currentRound;
}

Player Game::getCurrentDrawer()
{
	return m_currentDrawer;
}
