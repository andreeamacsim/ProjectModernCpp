#include "playersDatabase.h"

std::vector<Player> PlayerStorage::getPlayers()
{
	return m_db.get_all<Player>();
}

void PlayerStorage::AddPlayerToStorage(std::string username, std::string password, std::string email)
{
	Player p;
	p.setUsername(username);
	p.setEmail(email);
	p.setPassword(password);
	m_db.insert(p);
	//m_db.insert(Player{username,password,email})
}
