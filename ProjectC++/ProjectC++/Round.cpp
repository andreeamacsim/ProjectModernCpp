module round;

Round::Round()
{
}

Round::Round(const std::string& word, const std::string& drawer)
{
	m_word = word;
	m_drawer = drawer;
}

void Round::AddGuess(const std::string& guess)
{
	m_guesses.emplace_back(guess);
}

bool Round::IsGuessed() const
{
	return false;
}

const std::string& Round::GetWord()
{
	return m_word;
}

const std::string& Round::GetDrawer()
{
	return m_drawer;
}

const std::vector<std::string>& Round::GetGuesses()
{
	return m_guesses;
}

std::vector<std::string> Round::GetGuessesForPlayer(const std::string& player)
{
	return std::vector<std::string>();
}
