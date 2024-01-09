#include  <iostream>;
#include <ctime>;
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

void Game::setDifficultyLevel()
{
	std::map<std::string, uint8_t> difficultyOptions{
	   {"Easy", 1},
	   {"Medium", 2},
	   {"Hard", 3}
	};

	auto printOptions = [&]() {
		std::cout << "Choose difficulty level:" << std::endl;
		for (const auto& [name, value] : difficultyOptions) {
			std::cout << value << ": " << name << std::endl;// functie lambda
		}
		};

	uint8_t option = 0;
	while (option == 0) {
		printOptions();

		std::string input;
		std::cin >> input;

		auto it = difficultyOptions.find(input);
		if (it != difficultyOptions.end()) {
			option = it->second;
			m_difficultyLevel = option;
		}
		else {
			std::cout << "Invalid input. Please enter a valid difficulty level." << std::endl;
		}
	}
}

void game::Game::setLanguage()
{
	std::map<std::string, uint8_t> languageOptions{
	   {"English", 1},
	   {"Romanian", 2}
	};

	auto printOptions = [&]() {
		std::cout << "Choose difficulty level:" << std::endl;
		for (const auto& [name, value] : languageOptions) {
			std::cout << value << ": " << name << std::endl;// functie lambda
		}
		};

	uint8_t option = 0;
	while (option == 0) {
		printOptions();

		std::string input;
		std::cin >> input;

		auto it = languageOptions.find(input);
		if (it != languageOptions.end()) {
			option = it->second;
			m_language = option;
		}
		else {
			std::cout << "Invalid input. Please enter a valid language number." << std::endl;
		}
	}
}

void game::Game::StartNewRound()
{
	const int numSubrounds = m_players.size();
	for (int subround = 1; subround <= numSubrounds; ++subround) 
	{
		/*Word wordSubround;
		wordSubround.generateWords();
		std::string newWord = wordSubround.selectRandomWord();
			
		Player subroundDrawer = m_players[subround];
		Round newSubround(newWord, subroundDrawer.getUsername());*/
			
	}
}

int game::Game::getLobbyNumber()
{
	srand(time(0));
	int nr = std::rand() % 900000 + 100000;
	return nr;
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
	return m_difficultyLevel;
}

uint8_t game::Game::getLanguage() const
{
	return m_language;
}

bool game::Game::isReadyForNewSubround() const
{
	if (m_currentRound < m_rounds.size()) {
		const Round& currentSubround = m_rounds[m_currentRound];

		std::time_t currentTime = std::time(nullptr);
		std::time_t subroundStartTime = currentSubround.getStartTime(); // de facut functia getStartTime

		if (currentTime - subroundStartTime >= 60) {
			return true;
		}
	}

	return false;
}

void game::Game::startSubround()
{
	if (m_currentRound < m_rounds.size()) {
		std::string newWord = m_wordList[std::rand() % m_wordList.size()].getWord(); 

		Player subroundDrawer = m_players[m_currentRound + 1]; 

		//Round newSubround(newWord, subroundDrawer.getUsername(), std::time(nullptr))

		//m_rounds.push_back(newSubround);

		m_currentDrawer = subroundDrawer;
		++m_currentRound;
	}
}



