module profile;
using game::Profile;
game::Profile::Profile() : m_playerName{ "unknownName" }, m_age{ 0 }, m_country{ "unknownCountry" }, m_level{ 0 }, m_description{ "noDescription" }
{
}
game::Profile::Profile(const std::string& playerName, uint16_t age, const std::string& country, uint32_t level, const std::string& description)
    : m_playerName{ playerName }, m_age{ age }, m_country{ country }, m_level{ level }, m_description{ description }
{
}
std::string Profile::getPlayerName() const
{
    return this->m_playerName;
}


std::string Profile::getCountry() const
{
    return this->m_country;
}

uint32_t Profile::getLevel() const
{
    return this->m_level;
}

std::string Profile::getDescription() const
{
    return this->m_description;
}

void Profile::setPlayerName(const std::string& playerName)
{
    this->m_playerName = playerName;
}

void Profile::setAge(int age)
{
    this->m_age = age;
}

void Profile::setCountry(const std::string& country)
{
    this->m_country = country;
}

void Profile::setLevel(int level)
{
    this->m_level = level;
}

void Profile::setDescription(const std::string& description)
{
    this->m_description = description;
}
