import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;
module word;

std::string selectRandomWord(const std::vector<std::string>& words)
{
    if (verify())
    {
        int randomIndex = rand() % words.size();
        return words[randomIndex];
        
    }
}
