module;

export module profile;
import <string>;

namespace game {
    export class Profile
    {

    public:
        Profile() : m_playerName("unknownName"), m_age(0), m_country("unknownCountry"), m_level(0), m_description("noDescription")
        {
        }
        Profile(const std::string& playerName, uint16_t age, const std::string& country, uint32_t level, const std::string& description)
            : m_playerName(playerName), m_age(age), m_country(country), m_level(level), m_description(description)
        {
        }

        std::string getPlayerName() const;
        //uint16_t getAge() const;
        std::string getCountry() const;
        uint32_t getLevel() const;
        std::string getDescription() const;

        void setPlayerName(const std::string& playerName);
        void setAge(int age);
        void setCountry(const std::string& country);
        void setLevel(int level);
        void setDescription(const std::string& description);

    private:
        std::string m_playerName;
        uint16_t m_age;
        std::string m_country;
        uint32_t m_level;
        std::string m_description;
    };
}


