module word;
import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;
module word;

bool verify()
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

