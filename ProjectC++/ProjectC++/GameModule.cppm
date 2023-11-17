module;
import <vector>;
import player;
import round;
import word;

export module GameModule;

export class Game
{
public:
    Game();
    Game(const std::vector<Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList, uint8_t currentRound, Player currentDrawer);

    void setPlayers(const std::vector<Player>& players);
    void setRounds(const std::vector<Round>& rounds);
    void setWordList(const std::vector<Word>& wordList);
    void setCurrentRound(uint8_t currentRound);
    void setCurrentDrawer(Player currentDrawer);
    void setDifficultyLevel();

    std::vector<Player>& getPlayers();
    std::vector<Round>& getRounds() ;
    std::vector<Word>& getWordsList() ;
    uint8_t getCurrentRound() const;
    Player getCurrentDrawer() const;
    uint8_t getDifficultyLevel() const;

private:
    std::vector<Player> m_players;
    std::vector<Round> m_rounds;
    std::vector<Word> m_wordList;
    uint8_t m_currentRound;
    uint8_t m_difficultyLevel;
    Player m_currentDrawer;
};