﻿import <ctime>;
module word;
import <string>;
import <vector>;
import <cstdlib>;
import<fstream>;

using game::Word;
game::Word::Word()
{
}
game::Word::Word(uint32_t id, std::string word, Difficulty difficulty, Language language):
    m_id{ id }, m_word{ word }, m_difficulty{ difficulty }, m_language{ language }
{
}
std::string game::Word::getWord() const
{
    return m_word;
}

void game::Word::setWord(std::string word)
{
    this->m_word = word;
}


std::string Word::revealCharacter()
{
    //de adaugat a.i. literele sa fie dezvaluite dupa 30s
    uint16_t maximumLetters = m_word.length() / 2;
    uint16_t letterCount = 0;
    std::vector<bool> revealed(m_word.length(), false);
    std::string revealedWord = m_word;
    for (int i = 0; i < revealedWord.length(); i++)
    {
        if (!revealed[i])
        {
            revealedWord[i] = '_';
        }
    }
    while (letterCount < maximumLetters)
    {
        int randomPosition = rand() % m_word.length();
        if (!revealed[randomPosition])
        {
            revealedWord[randomPosition] = m_word[randomPosition];
            revealed[randomPosition] = true;
            letterCount++;
        }

    }
    return revealedWord;
}

int game::Word::getId() const
{
    return m_id;
}

int game::Word::getDifficulty() const
{
    return static_cast<int>(m_difficulty);
}

int game::Word::getLanguage() const
{
    return static_cast<int>(m_language);
}

std::vector<std::string> game::Word::generateWords(uint8_t language, uint8_t difficulty)
{
    std::ifstream f;
    if(language==1)
        if(difficulty==1)
            f.open("EnglishEasyWords.txt");
        else
            if(difficulty==2)
                f.open("EnglishMediumWords.txt");
            else
                if(difficulty==3)
                    f.open("EnglishHardWords.txt");
     if(language==2)
         if (difficulty == 1)
             f.open("RomanianEasyWords.txt");
         else
             if (difficulty == 2)
                 f.open("RomanaianMediumWords.txt");
             else
                 if (difficulty == 3)
                     f.open("RomanaianHardWords.txt");
     std::vector<std::string> words;
     words.clear();
     std::string word;
     while (std::getline(f, word)) {
         words.push_back(word);
     }
     f.close();

    return words;
}



void game::Word::setId( int id)
{
    m_id = id;
}

void game::Word::setDifficulty(int difficulty)
{
    this->m_difficulty = static_cast<Difficulty>(difficulty);
}

void game::Word::setLanguage(int language)
{
    this->m_language = static_cast<Language>(language);
}
