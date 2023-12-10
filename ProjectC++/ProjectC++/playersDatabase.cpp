#include "playersDatabase.h"
using namespace game;

bool PlayerStorage::Initialize()
{

	m_db.sync_schema();
	return true;
}

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

void game::PlayerStorage::PopulateStorage()
{
	std::vector<Player> players{
			Player{-1,"Andreea","andreea2003","mandreealavinia@yahoo.com",},
			Player{-1,"Mihai","mihai2003","mihaimoisescu2003@yahoo.com"},
			Player{-1,"Cristina","cristina2003","iuliaparaschiv@yahoo.com"},
			Player{-1,"Alex","alexandru","alexalexandru@gmail.com"}
	};
	m_db.insert_range(players.begin(), players.end());
}
