module word;
import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;
using game::Word;
bool Word::verify()
{
    std::ifstream inputFile("words.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Eroare la deschiderea fișierului cu cuvinte.\n";
        return false;
    }
    return true;
}

std::string game::Word::getWord() const
{
    return m_word;
}

void game::Word::setWord(std::string word)
{
    this->m_word = word;
}

void Word::generateWords()
{
    std::ifstream inputFile("words.txt");
    std::string word;
    while (std::getline(inputFile, word)) 
    {
        Word w;
        w.setWord(word);
        m_words.push_back(w);
    }
}


std::string Word::selectRandomWord()
{
    if (verify())
    {
        int randomIndex = rand() % m_words.size();
        return m_words[randomIndex].getWord();
    }
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

uint32_t game::Word::getId()
{
    return m_id;
}

void game::Word::setId( uint32_t id)
{
    m_id = id;
}

std::vector<Word> game::Word::getWords()
{
    return m_words;
}
