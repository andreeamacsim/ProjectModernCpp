#include<ctime>
#include<thread> 
#include<iostream>
#include<algorithm>
#include<map>
#include<ranges>
#include"Game.h"
#include<vector>
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

void game::Game::setCurrentWord(PlayerStorage& storage)
{
	this->m_currentWord = storage.getRandomWord(m_language, m_difficultyLevel);
}

Word game::Game::getCurrentWord() const
{
	return this->m_currentWord;
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

void game::Game::startRound(PlayerStorage& storage)
{
	for (auto player : m_players)
	{

		startSubround(storage, player.first);
	}
}

bool game::Game::isReadyForNewSubround() const 
{
	if (m_currentRound < 4) {
		const Round& currentSubround = m_rounds[m_currentRound];
		std::time_t currentTime = std::time(nullptr);
		std::time_t subroundStartTime = currentSubround.getStartTime();

		auto equalScores = [&currentSubround](const auto& scores) {
			return std::ranges::equal(currentSubround.getPlayerScores(), scores);
			};

		auto readyForNewSubround = [&]() {
			return currentTime - subroundStartTime >= 60 &&
				(m_currentRound == 0 || !equalScores(m_rounds[m_currentRound - 1].getPlayerScores()));
			};

		return readyForNewSubround();
	}

	return false;
}


void game::Game::startSubround(PlayerStorage& storage,int id)
{
		m_currentRoundStartTime = std::time(nullptr);
		m_correctAnswerTimes.clear();
		setCurrentWord(storage);

		Player subroundDrawer = m_players[id];

		auto newSubround = std::make_unique<Round>(m_currentWord.getWord(), subroundDrawer.getUsername(), std::time(nullptr));

		m_rounds.push_back(std::move(*newSubround));

		m_currentDrawer = subroundDrawer;
		++m_currentRound;

		bool wordGuessed; 
		std::time_t responseTimes = getResponseTime();

		std::for_each(m_players.begin(), m_players.end(), [&](auto& playerPair) {
			Player& player = playerPair.second;
			Points& playerPoints = player.getPointsObject();

			playerPoints.calculateScore(wordGuessed, responseTimes);
			if (responseTimes == 0)
				playerPoints.applyFailedGuessingPoints();
			else
				playerPoints.applyGuessingPoints(responseTimes);
			});

		/*std::time_t roundStartTime = std::time(nullptr);
			while (std::time(nullptr) - roundStartTime < 60) {
			}
			finishRound();*/
}

void game::Game::RunGame(PlayerStorage& storage)
{

	const uint8_t numRounds = 4; 
	m_currentRound = 0;
	for (uint8_t roundNumber = 1; roundNumber < numRounds; ++roundNumber)
	{
			startRound(storage);
			
	}
}


 void Game::playerSentCorrectAnswer(const Player& player)
 {
	 m_correctAnswerTimes[player.getId()] = std::time(nullptr);
 }

 std::time_t Game::getResponseTime() const
 {
	 if (m_correctAnswerTimes.empty()) {
		 return 0;  
	 }
	 else {
	
		 auto it = std::max_element(m_correctAnswerTimes.begin(), m_correctAnswerTimes.end(),
			 [](const auto& lhs, const auto& rhs) {
				 return lhs.second < rhs.second;
			 });

		 return it->second - m_currentRoundStartTime;
	 }
 }

 void game::Game::finishRound()
 {
	 if (m_currentRound < m_rounds.size()) {
		 const Round& currentSubround = m_rounds[m_currentRound];


			 for (const auto& playerPair : m_players)
			 {
				 Player player = playerPair.second;
				 if (player.getGuessedWord()) {
					 player.getPointsObject().calculateScore(true, getResponseTime());
					 player.getPointsObject().applyGuessingPoints(getResponseTime());
				 }
				 else {
					 player.getPointsObject().applyFailedGuessingPoints();
				 }
			 }
	 }
 }

 void game::Game::setIfPlayerGuessed(std::string username, bool isCorrect)
 {
	 m_guessedWordForPlayer[username] = isCorrect;
 }

 bool game::Game::CheckAllAnswers()
 {
	 return std::all_of(m_guessedWordForPlayer.begin(), m_guessedWordForPlayer.end(),
		 [](const auto& pair) { return pair.second; });
 }

 std::string game::Game::revealCharacters()
 {
	 srand(static_cast<unsigned>(time(nullptr)));

	 size_t maximumLetters = m_currentWord.getWord().length() / 2;
	 size_t letterCount = 0;

	 std::vector<bool> revealed(m_currentWord.getWord().length(), false);
	 std::string revealedWord;
	 revealedWord.resize(m_currentWord.getWord().length());

	 for (size_t i = 0; i < revealedWord.length(); i++) {
		 if (!revealed[i]) {
			 revealedWord[i] = '_';
		 }
	 }

	 while (letterCount < maximumLetters) {
		 size_t randomPosition = rand() % m_currentWord.getWord().length();
		 if (!revealed[randomPosition]) {
			 revealedWord[randomPosition] = m_currentWord.getWord()[randomPosition];
			 revealed[randomPosition] = true;
			 letterCount++;
		 }
	 }

	 return revealedWord;
 }







