#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
#include <time.h>

namespace sql = sqlite_orm;
import profile;
import player;
import GameModule;
import word;

namespace game
{
    inline auto CreateStorage(const std::string& filename) {
        return sql::make_storage(
            filename,
            sql::make_table(
                "Player",
                sql::make_column("id", &Player::setId, &Player::getId, sql::primary_key().autoincrement()),
                sql::make_column("username", &Player::setUsername, &Player::getUsername),
                sql::make_column("password", &Player::setPassword, &Player::getPassword),
                sql::make_column("email", &Player::setEmail, &Player::getEmail)
            ),
            sql::make_table(
                "Word",
                sql::make_column("id",&Word::setId,&Word::getId, sql::primary_key().autoincrement()),
                sql::make_column("word",&Word::setWord,&Word::getWord),
                sql::make_column("difficulty",&Word::setDifficulty, &Word::getDifficulty),
                sql::make_column("language",&Word::setLanguage, &Word::getLanguage)
            )
            //sql::make_table(
    //	"Profile",
    //	sql::make_column("username", &Profile::getPlayerName, &Profile::setPlayerName, sql::primary_key()),
    //	sql::make_column("age",&Profile::getAge,&Profile::setAge),
    //	sql::make_column("country",&Profile::getCountry,&Profile::setCountry),
    //	sql::make_column("level",&Profile::getLevel,&Profile::setLevel),
    //	sql::make_column("description",&Profile::getDescription,&Profile::setDescription),
    //)
        );
    }

    using Storage = decltype(CreateStorage(""));

    class PlayerStorage {
    public:
        bool Initialize();

        std::vector<Player>getPlayers();
        std::vector<Word>getWords();
        void AddPlayerToStorage(std::string username, std::string password, std::string email);
        Game& getGame();
        void addLine(std::pair<std::pair<float, float>, std::pair<float, float>>line, std::string color, uint8_t width);
        Word GetCurrentWord() const;
        std::vector<Word> readWordsFromFile(Language language, Difficulty difficuly, std::string fileName);
        Player checkUser(const std::string& username);
        std::vector<Word>getWords(Language language, Difficulty difficulty);
    private:
        void PopulateStorage();
        const std::string kDbFile{ "database.sqlite" };
        Storage m_db = CreateStorage(kDbFile);
        Game m_game;
        Word  m_currentWord;

    };
}