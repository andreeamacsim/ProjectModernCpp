module word;
import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;

bool Word::verify()
{
    std::ifstream inputFile("words.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Eroare la deschiderea fișierului cu cuvinte.\n";
        return false;
    }
    return true;
}

void Word::generateWords()
{
    std::ifstream inputFile("words.txt");
    std::string word;
    while (std::getline(inputFile, word)) 
    {
        m_words.push_back(word);
    }
}


std::string Word::selectRandomWord(const std::vector<std::string>& m_words)
{
    if (verify())
    {
        int randomIndex = rand() % m_words.size();
        return m_words[randomIndex];
    }
}

std::string Word::revealCharacter(const std::string& word)
{
    //de adaugat a.i. literele sa fie dezvaluite dupa 30s
    uint16_t maximumLetters = word.length() / 2;
    uint16_t letterCount = 0;
    std::vector<bool> revealed(word.length(), false);
    std::string revealedWord = word;
    for (int i = 0; i < revealedWord.length(); i++)
    {
        if (!revealed[i])
        {
            revealedWord[i] = '_';
        }
    }
    while (letterCount < maximumLetters)
    {
        int randomPosition = rand() % word.length();
        if (!revealed[randomPosition])
        {
            revealedWord[randomPosition] = word[randomPosition];
            revealed[randomPosition] = true;
            letterCount++;
        }

    }
    return revealedWord;
}