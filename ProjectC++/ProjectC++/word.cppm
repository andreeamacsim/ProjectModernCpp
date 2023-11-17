module;
import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;

export module word;

export class Word
{
public:
	std::string selectRandomWord(const std::vector<std::string>& words);
	bool verify();
	void generateWords();
	std::string revealCharacter(const std::string& word);
private:
	std::string m_word;
	std::vector<std::string>m_words;
};
