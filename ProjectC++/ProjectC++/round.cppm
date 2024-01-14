module;
#include <ctime>;
#include <map>
#include <unordered_map>
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

        void addGuess(const std::string& guess, const Player& guesser);
        bool isGuessed() const;
        const std::string& getWord() const;
        const std::string& getDrawer() const;
        const std::vector<std::string>& getGuesses() const;
        std::vector<std::string> getGuessesForPlayer(const std::string& player) const;
        std::time_t getStartTime() const;
        const std::unordered_map<int, Player>& getPlayerScores() const
        {
            return m_playerScores;
        }

    private:
        std::string m_word;
        std::string m_drawer;
        std::vector<std::string> m_guesses;
        bool m_guessed;
        std::time_t m_startTime;
        std::unordered_map<int, Player> m_playerScores;
        
    };
}