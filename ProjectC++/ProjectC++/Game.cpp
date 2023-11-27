#include  <iostream>;
module  GameModule;
import <vector>;
import player;

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

void Game::setDifficultyLevel()
{
	uint8_t option = -1;
	while (option)
	{
		std::cout << "Choose difficulty level:";
		std::cout << "Level 1: Easy";
		std::cout << "Level 2: Medium";
		std::cout << "Level 3: Hard";
		std::cin >> option;
		switch (option)
		{
		case 1:
		{
			m_difficultyLevel = 1;
			break;
		}
		case 2:
		{
			m_difficultyLevel = 2;
			break;
		}
		case 3:
		{
			m_difficultyLevel = 3;
			break;
		}

		}


	}
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

uint8_t Game::getCurrentRound() const
{
	return m_currentRound;
}

Player Game::getCurrentDrawer() const 
{
	return m_currentDrawer;
}

uint8_t Game::getDifficultyLevel() const
{
	return m_difficultyLevel;
}




