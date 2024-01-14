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
		auto result = m_playerScores.find(0);  

		if (result != m_playerScores.end()) { 
			result->second.m_score++;  
			m_guessed = true;
		}
		else {  
			m_playerScores.emplace(0, guesser);
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






