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
		int getId()const;
		int getDifficulty() const;
		int getLanguage() const;


		void setWord(std::string word);
		void setId(int id);
		void setDifficulty(int difficulty);
		void setLanguage(int language);


		std::string revealCharacter();
	private:
		int m_id;
		std::string m_word;
		Difficulty m_difficulty;
		Language m_language;
		
	};
}
