module;
import <string>;
import <vector>;
import <cstdlib>;
import <ctime>;
import "Enums.h";

export module word;

namespace game {
	export class Word
	{
	public:
		Word();
		Word(uint32_t id, std::string word, Difficulty difficulty, Language language);
		std::string getWord() const;
		uint32_t getId();
		int getDifficulty() const;
		int getLanguage() const;


		void setWord(std::string word);
		void setId(uint32_t id);
		void setDifficulty(int difficulty);
		void setLanguage(int language);


		std::string revealCharacter();
	private:
		uint32_t m_id;
		std::string m_word;
		Difficulty m_difficulty;
		Language m_language;
		
	};
}
