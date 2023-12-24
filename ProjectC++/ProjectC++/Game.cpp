#include  <iostream>;
#include<algorithm>;
#include <map>
module  GameModule;
import <vector>;
import player;
using namespace game;
Game::Game()
{
}

Game::Game(const std::vector<Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList,  uint8_t currentRound, Player currentDrawer)
	: m_players{ players }
	, m_rounds{ rounds }
	, m_wordList{ wordList }
	, m_currentRound{ currentRound }
	, m_currentDrawer{ currentDrawer }
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
	std::map<std::string, uint8_t> difficultyOptions{
	   {"Easy", 1},
	   {"Medium", 2},
	   {"Hard", 3}
	};

	uint8_t option = 0;
	while (option == 0)
	{
		std::cout << "Choose difficulty level:" << std::endl;
		std::cout << "1: Easy" << std::endl;
		std::cout << "2: Medium" << std::endl;
		std::cout << "3: Hard" << std::endl;

		std::string input;
		std::cin >> input;

		auto it = difficultyOptions.find(input);
		if (it != difficultyOptions.end())
		{
			option = it->second;
			m_difficultyLevel = option;
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid difficulty level." << std::endl;
		}
	}
}

	void game::Game::StartNewRound()
{
		const int numSubrounds = m_players.size();
		for (int subround = 1; subround <= numSubrounds; ++subround) 
		{
			//Word wordSubround;
			//wordSubround.generateWords();
			//std::string newWord = wordSubround.selectRandomWord();
			//
			//Player subroundDrawer = m_players[subround];
			//Round newSubround(newWord, subroundDrawer.getUsername());
			//
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




