#include <ctime>;
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

Game::Game(std::unordered_map<int, Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList,  uint8_t currentRound, Player currentDrawer)
	: m_players{ players }
	, m_rounds{ rounds }
	, m_wordList{ wordList }
	, m_currentRound{ currentRound }
	, m_currentDrawer{ currentDrawer }
{
}

void game::Game::setGameCode(uint32_t gameCode)
{
	m_gameCode = gameCode;
}

void Game::setPlayers(std::unordered_map<int, Player>& players)
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

void Game::setDifficultyLevel(int difficulty)
{
	this->m_difficultyLevel = static_cast<Difficulty>(difficulty);
}

void game::Game::setLanguage(int language)
{
	this->m_language = static_cast<Language>(language);
}


void Game::DrawLine(std::pair<std::pair<float, float>, std::pair<float, float>> line, std::string color, uint8_t width)
{
	this->m_drawingTable.push_back({ line,color,width });
}

void game::Game::addPlayerToGame(Player p)
{
	m_players[p.getId()]=p;
}

void game::Game::disconnetPlayer(Player p)
{
	m_players.erase(p.getId());
}

std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>>& game::Game::getDrawingTable()
{
	return m_drawingTable;
}


uint32_t game::Game::getGameCode()
{
	return this->m_gameCode;
}

std::unordered_map<int, Player>& Game::getPlayers()
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
	return static_cast<int>(m_difficultyLevel);
}

uint8_t game::Game::getLanguage() const
{
	return static_cast<int>(m_language);
}

bool game::Game::isReadyForNewSubround() const
{
	if (m_currentRound < m_rounds.size()) {
		const Round& currentSubround = m_rounds[m_currentRound];

		std::time_t currentTime = std::time(nullptr);
		std::time_t subroundStartTime = currentSubround.getStartTime(); 

		if (currentTime - subroundStartTime >= 60) {
			if (m_currentRound > 0) {

				const Round& previousSubround = m_rounds[m_currentRound - 1];

				const std::map<Player, int>& currentScores = currentSubround.GetPlayerScores();
				const std::map<Player, int>& previousScores = previousSubround.GetPlayerScores();

				if (currentScores != previousScores) {
					return true;
				}
			}
			else {
				return true;
			}

			}
		
	}
	return false;
}


void game::Game::startSubround()
{
	if (m_currentRound < m_rounds.size()) {
		std::string newWord = m_wordList[std::rand() % m_wordList.size()].getWord(); 

		Player subroundDrawer = m_players[m_currentRound + 1]; 

		Round newSubround(newWord, subroundDrawer.getUsername(), std::time(nullptr));

			m_rounds.push_back(newSubround);

		m_currentDrawer = subroundDrawer;
		++m_currentRound;
	}
}

void game::Game::RunGame()
{

	const uint8_t numRounds = 4;// din fisierul cu proiectul 

	for (uint8_t roundNumber = 0; roundNumber < numRounds; ++roundNumber)
	{
		while (m_currentRound < m_rounds.size()) {
			if (isReadyForNewSubround()) {
				startSubround();
				m_drawingTable.clear();
			}
			else {
				std::time_t start = std::time(nullptr);
				while (std::time(nullptr) - start < 1)
				{

				}

			}
		}
	}
}



