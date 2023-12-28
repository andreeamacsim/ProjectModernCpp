module;
import <vector>;
import player;
import round;
import word;
import <iostream>;

export module GameModule;
namespace game 
{
    export class Game
    {
    public:
        Game()  ;
        Game(const std::vector<Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList, uint8_t currentRound, Player currentDrawer);

        void setPlayers(const std::vector<Player>& players);
        void setRounds(const std::vector<Round>& rounds);
        void setWordList(const std::vector<Word>& wordList);
        void setCurrentRound(uint8_t currentRound);
        void setCurrentDrawer(Player currentDrawer);
        void setDifficultyLevel();
        void  StartNewRound();
        
        void DrawLine(std::pair<std::pair<float, float>, std::pair<float, float>>line, std::string color, uint8_t width);

        std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>>& getDrawingTable();

        std::vector<Player>& getPlayers() ;
        std::vector<Round>& getRounds() ;
        std::vector<Word>& getWordsList()  ;
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
        std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>> m_drawingTable;
    };
}