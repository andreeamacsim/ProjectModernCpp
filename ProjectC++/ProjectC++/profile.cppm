module;

export module profile;
import <string>;

namespace game {
    export class Profile
    {

    public:
        Profile();
        Profile(const std::string& playerName, uint16_t age, const std::string& country, uint32_t level, const std::string& description);

        std::string getPlayerName() const;
        //uint16_t getAge() const;
        std::string getCountry() const;
        uint32_t getLevel() const;
        std::string getDescription() const;

        void setPlayerName(const std::string& playerName);
        void setAge(uint16_t age);
        void setCountry(const std::string& country);
        void setLevel(uint32_t level);
        void setDescription(const std::string& description);

    private:
        std::string m_playerName;
        uint16_t m_age;
        std::string m_country;
        uint32_t m_level;
        std::string m_description;
    };
}


