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

std::vector<Word> game::PlayerStorage::getWords()
{
	return m_db.get_all<Word>();
}

void PlayerStorage::AddPlayerToStorage(std::string username, std::string password, std::string email)
{
	Player p;
	p.setUsername(username);
	p.setPassword(password);
	p.setEmail(email);
	m_db.insert(p);
	//m_db.insert(Player{username,password,email})
}


Word game::PlayerStorage::GetCurrentWord() const
{
	return m_currentWord;
}

std::vector<Word> game::PlayerStorage::readWordsFromFile(Language language, Difficulty difficuly, std::string fileName)
{
	std::vector<Word> words;
	std::ifstream file(fileName);
	std::string word;
	while (!file.eof())
	{
		file >> word;
		//Word w(-1, word, difficuly, language);
		words.emplace_back(-1, word, difficuly, language);
	}
	return words;
	file.close();
}

Player game::PlayerStorage::checkUser(const std::string& username)
{
	auto players = m_db.get_all<Player>(sql::where(sql::c(&Player::getUsername) == username));
	if (!players.empty())
	{
		Player player = players[0];
		return player;
	}
	else
	{
		Player p;
		return p;
	}
}

std::vector<Word> game::PlayerStorage::getRandomWord(Language language, Difficulty difficulty)
{
	auto allWords = m_db.get_all<Word>(sql::where(sql::and_(sql::c(&Word::getLanguage) == static_cast<int>(language),
		sql::c(&Word::getDifficulty) == static_cast<int>(difficulty))));

	std::srand(std::time(nullptr));
	auto randomIndex = std::rand() % allWords.size();

	return { allWords[randomIndex] };
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
	std::vector<Word> RomanianEasyWords=readWordsFromFile(Language::Romanian,Difficulty::Easy,"RomanianEasyWords.txt");
	std::vector<Word> RomanianHardWords = readWordsFromFile(Language::Romanian, Difficulty::Hard, "RomanianHardWords.txt");

	std::vector<Word>RomanianMediumWords = readWordsFromFile(Language::Romanian, Difficulty::Medium, "RomanianMediumWords.txt");

	std::vector<Word>EnglishEasyWords = readWordsFromFile(Language::English, Difficulty::Easy, "EnglishEasyWords.txt");

	std::vector<Word>EnglishHardWords = readWordsFromFile(Language::English, Difficulty::Hard, "EnglishHardWords.txt");

	std::vector<Word>EnglishMediumWords = readWordsFromFile(Language::English, Difficulty::Medium, "EnglishMediumWords.txt");

	std::vector<Word> words;
	words.insert(words.end(), RomanianEasyWords.begin(), RomanianEasyWords.end());
	words.insert(words.end(), RomanianHardWords.begin(), RomanianHardWords.end());
	words.insert(words.end(), RomanianMediumWords.begin(), RomanianMediumWords.end());
	words.insert(words.end(), EnglishEasyWords.begin(), EnglishEasyWords.end());
	words.insert(words.end(), EnglishHardWords.begin(), EnglishHardWords.end());
	words.insert(words.end(), EnglishMediumWords.begin(), EnglishMediumWords.end());
	m_db.insert_range(words.begin(), words.end());



}
