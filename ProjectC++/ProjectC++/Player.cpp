module player;

Player::Player()
{
}

Player::Player(std::string username, std::string password, Profile playerProfile):m_username(username),m_password(password),m_playerProfile(playerProfile)
{
}

std::string Player::getUsername()
{
	return this->m_username;
}

std::string Player::getPassword()
{
	return this->m_username;
}

Profile Player::getProfile()
{
	return this->m_playerProfile;
}

void Player::setUsername(std::string username)
{
	this->m_username = username;
}

void Player::setPassword(std::string password)
{
	this->m_password = password;
}
