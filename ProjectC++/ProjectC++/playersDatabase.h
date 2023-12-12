#pragma once

#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>

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
                sql::make_column("id", &Player::setId, &Player::getId, sql::primary_key()),
                sql::make_column("username", &Player::setUsername, &Player::getUsername),
                sql::make_column("password", &Player::setPassword, &Player::getPassword),
                sql::make_column("email", &Player::setEmail, &Player::getEmail)
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
        void AddPlayerToStorage(std::string username, std::string password, std::string email);
        Game& getGame();
        Word GetCurrentWord() const;


    private:
        void PopulateStorage();
        const std::string kDbFile{ "players2.sqlite" };
        Storage m_db = CreateStorage(kDbFile);
        Game m_game;
        Word  m_currentWord;

    };
}