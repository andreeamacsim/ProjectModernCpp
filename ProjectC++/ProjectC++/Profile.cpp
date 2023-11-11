module profile;
std::string Profile::getPlayerName() const
{
    return this->m_playerName;
}

uint16_t Profile::getAge() const
{
    return this-> m_age;
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
