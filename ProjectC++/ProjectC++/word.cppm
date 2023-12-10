module;
import <string>;
import <vector>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <iostream>;

export module word;

namespace game {
	export class Word
	{
	public:
		std::string selectRandomWord(const std::vector<Word>& words);
		bool verify();
		std::string getWord() const;
		void setWord(std::string word);
		void generateWords(std::vector<Word> words);
		std::string revealCharacter();
	private:
		std::string m_word;
		//std::vector<std::string>m_words;
	};
}
