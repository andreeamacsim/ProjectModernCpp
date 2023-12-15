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
		std::string selectRandomWord();
		bool verify();
		std::string getWord() const;
		void setWord(std::string word);
		void generateWords();
		std::string revealCharacter();
		uint32_t getId();
		void setId(uint32_t id);
		std::vector<Word> getWords();
	private:
		uint32_t m_id;
		std::string m_word;
		std::vector<Word>m_words;
	};
}
