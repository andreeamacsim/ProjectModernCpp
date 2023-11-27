module player;

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
