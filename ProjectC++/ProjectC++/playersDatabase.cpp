#include "playersDatabase.h"
using namespace game;

bool PlayerStorage::Initialize()
{

	m_db.sync_schema();
	auto initPlayerCount = m_db.count<Player>();
	if (initPlayerCount == 0)
	{
		PopulateStorage();
	}
	auto playerCount = m_db.count<Player>();
	return playerCount != 0;
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

Game& game::PlayerStorage::getGame()
{
	return m_game;
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
