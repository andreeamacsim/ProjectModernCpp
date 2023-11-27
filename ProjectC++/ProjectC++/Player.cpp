module player;
#include <regex>

Player::Player()
{
}

Player::Player(std::string email,std::string username, std::string password, Profile playerProfile):m_email(email),m_username(username),m_password(password),m_playerProfile(playerProfile)
{
}

std::string  Player::getEmail() const
{
	return this->m_email;
}

std::string Player::getUsername() const
{
	return this->m_username;
}

std::string Player::getPassword() const
{
	return this->m_password;
}

Profile Player::getProfile() const
{
	return this->m_playerProfile;
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

	const std::regex passwordPatter("^(?=.*[a-z])(?=/*[A-Z])(?=.*[@$!%*?])[A-Za-z\\d@$!%*?&]{8,}$");
	if (!std::regex_match(password, passwordPattern))
	{
		throw std::exception("Invalid password!\nThe password must contain at least:\n-8 characters\n-a number\n-a special character");
	}
}
bool Player::isUsernameUnique(const std::string& username)
{
	//se va face cand vom avea baza de date 
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
	if (!isUsernameUnique(username))
	{
		throw std::exception("Username is not unique");
	}
}


