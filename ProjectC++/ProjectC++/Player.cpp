module player;
import <regex>;
import profile;
import PointsModule;

using namespace game;

Player::Player()
{
	this->m_id = -1;
}

Player::Player(int16_t id,std::string username, std::string password, std::string email)
	:m_email{ email }, m_username{ username }, m_password{ password }, m_id{ id }
{
}

std::string Player::getEmail() const
{
	return this->m_email;
}

std::string Player::getUsername() const
{
	return this->m_username;
}

int16_t Player::getId() const
{ 
	return m_id;
}

bool game::Player::getGuessedWord()
{
	return m_guessedWord;
}

std::string Player::getPassword() const
{
	return this->m_password;
}


void game::Player::setGuessedWord(bool guessedWord)
{
	m_guessedWord = guessedWord;
}

void Player::setId(int16_t id)
{
	m_id = id;
}

void Player::setEmail(std::string email)
{
	this->m_email = email;
}

void Player::setUsername(std::string username)
{
	this->m_username = username;
}

void Player::setPassword(std::string password)
{
	this->m_password = password;
}


void Player::checkPassword(const std::string& password)
{
	if (password == "")
	{
		throw std::exception("Password field can't be empty");
	}

	const std::regex passwordPattern("^(?=.*[a-z])(?=/*[A-Z])(?=.*[@$!%*?])[A-Za-z\\d@$!%*?&]{8,}$");
	if (!std::regex_match(password, passwordPattern))
	{
		throw std::exception("Invalid password!\nThe password must contain at least:\n-8 characters\n-a number\n-a special character");
	}
}


void Player::checkEmail(const std::string& email)
{
	if (email == "")
	{
		throw std::exception("Email field can't be empty");
	}

	const std::regex emailPattern("^([a-zA-Z0-9_\\ \\.+)@([a-zA-Z0-9_\\-\\.]+)\\.([a-zA-Z]{2,5})$");
	if (!std::regex_match(email, emailPattern))
	{
		throw std::exception("Invalid email");
	}
}

void Player::checkUsername(const std::string& username)
{
	if (username == "")
	{
		throw std::exception("Username field can't be empty");
	}

	const std::regex usernamePattern("^[a-zA-Z0-9_]+$");
	if (!std::regex_match(username, usernamePattern))
	{
		throw std::exception("Invalid username");
	}
	
}

Points& Player::getPointsObject()
{
	return m_points;
}


