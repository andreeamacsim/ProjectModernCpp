module;
#include <ctime>;
#include <map>
import <vector>;
import <string>;
import player;

export module round;

namespace game {
    export class Round
    {
    public:
        Round();
        Round(const std::string& word, const std::string& drawer);
        Round(const std::string& word, const std::string& drawer, std::time_t startTime);
        //void AddGuess(const std::string& guess);
        void AddGuess(const std::string& guess, const Player& guesser);
        bool IsGuessed() const;
        const std::string& GetWord() const;
        const std::string& GetDrawer() const;
        const std::vector<std::string>& GetGuesses() const;
        std::vector<std::string> GetGuessesForPlayer(const std::string& player) const;
        std::time_t getStartTime() const;
        const std::map<Player, int>& GetPlayerScores() const
        {
            return m_playerScores;
        }

    private:
        std::string m_word;
        std::string m_drawer;
        std::vector<std::string> m_guesses;
        bool m_guessed;
        std::time_t m_startTime;
        std::map<Player, int> m_playerScores;
        
    };
}