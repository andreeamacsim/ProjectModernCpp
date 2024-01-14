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
import PointsModule;
import word;

namespace game
{
    inline auto createStorage(const std::string& filename) {
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
            ),
            sql::make_table(
                "Points",
                sql::make_column("id",&Points::setId,&Points::getId,sql::primary_key().autoincrement()),
                sql::make_column("userId",&Points::setUserId,&Points::getUserId),
                sql::make_column("playerPoints",&Points::setPoints,&Points::getPoints)
                )
           
        );
    }

    using Storage = decltype(createStorage(""));

    class PlayerStorage {
    public:
        bool Initialize();

        std::vector<Player>getPlayers();
        std::vector<Word>getWords();
        void addPlayerToStorage(std::string username, std::string password, std::string email);
        Word getCurrentWord() const;
        std::vector<Word> readWordsFromFile(Language language, Difficulty difficuly, std::string fileName);
        Player checkUser(const std::string& username);
        Word getRandomWord(Language language, Difficulty difficulty);
    private:
        void populateStorage();
        const std::string kDbFile{ "database.sqlite" };
        Storage m_db = createStorage(kDbFile);
        Word  m_currentWord;

    };
}