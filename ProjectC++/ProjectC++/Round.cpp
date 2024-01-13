#include <ctime>;
import <string>;
import <vector>;
module round;
import player;
using game::Round;

Round::Round()
{
}

Round::Round(const std::string& word, const std::string& drawer)
{
	m_word = word;
	m_drawer = drawer;
}

game::Round::Round(const std::string& word, const std::string& drawer, std::time_t startTime)
{
	m_word = word;
	m_drawer = drawer;
	m_startTime = startTime;
}


void Round::addGuess(const std::string& guess, const game::Player& guesser)
{
	m_guesses.emplace_back(guess);
	if (guess == m_word && !m_guessed) {
		//  try_emplace pentru a evita cautarea duplicatelor
		auto result = m_playerScores.try_emplace(guesser, 0);

		if (result.second) {
			result.first->second++;
			m_guessed = true;
		}
	}
}

bool Round::isGuessed() const
{
	return false;
}

const std::string& Round::getWord() const
{
	return m_word;
}

const std::string& Round::getDrawer() const
{
	return m_drawer;
}

const std::vector<std::string>& Round::getGuesses() const
{
	return m_guesses;
}

std::vector<std::string> Round::getGuessesForPlayer(const std::string& player) const
{
	return std::vector<std::string>();
}

std::time_t Round::getStartTime() const
{
	std::time_t now=time(nullptr);
	return now;
}






