#include <ctime>;
import <string>;
import <vector>;
module round;
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

void Round::AddGuess(const std::string& guess)
{
	m_guesses.emplace_back(guess);
}

bool Round::IsGuessed() const
{
	return false;
}

const std::string& Round::GetWord() const
{
	return m_word;
}

const std::string& Round::GetDrawer() const
{
	return m_drawer;
}

const std::vector<std::string>& Round::GetGuesses() const
{
	return m_guesses;
}

std::vector<std::string> Round::GetGuessesForPlayer(const std::string& player) const
{
	return std::vector<std::string>();
}

std::time_t Round::getStartTime() const
{
	std::time_t now=time(nullptr);
	return now;
}




