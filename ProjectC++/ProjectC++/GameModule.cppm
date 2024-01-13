module;
import <vector>;
import player;
import round;
import word;
import <iostream>;
import <unordered_map>;
import "Enums.h";

export module GameModule;
import PointsModule;
namespace game 
{
    export class Game
    {
    public:
        Game() ;
        Game(std::unordered_map<int, Player>& players, const std::vector<Round>& rounds, const std::vector<Word>& wordList, uint8_t currentRound, Player currentDrawer);

        void setGameCode(uint32_t gameCode);
        void setPlayers(std::unordered_map<int, Player>& players);
        void setRounds(const std::vector<Round>& rounds);
        void setWordList(const std::vector<Word>& wordList);
        void setCurrentRound(uint8_t currentRound);
        void setCurrentDrawer(Player currentDrawer);
        void setDifficultyLevel(int difficulty);
        void setLanguage(int language);
        void DrawLine(std::pair<std::pair<float, float>, std::pair<float, float>>line, std::string color, uint8_t width);
        void addPlayerToGame(Player p);
        void disconnetPlayer(Player p);
        std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>>& getDrawingTable();

        uint32_t getGameCode();
        std::unordered_map<int, Player>& getPlayers() ;
        std::vector<Round>& getRounds() ;
        std::vector<Word>& getWordsList()  ;
        uint8_t getCurrentRound() const;
        Player getCurrentDrawer() const;
        uint8_t getDifficultyLevel() const;
        uint8_t getLanguage() const;
        bool isReadyForNewSubround() const;
        void startSubround();
        void RunGame();
        bool checkIfWordGuessed() const;
        void playerSentCorrectAnswer(const Player& player);
        std::time_t getResponseTime() const;
        void finishRound();
     


    private:
        std::unordered_map<int,Player> m_players;
        std::vector<Round> m_rounds;
        std::vector<Word> m_wordList;
        uint8_t m_currentRound;
        Difficulty m_difficultyLevel;
        Language m_language;
        Player m_currentDrawer;
        std::vector<std::tuple<std::pair<std::pair<float, float>, std::pair<float, float>>, std::string, uint8_t>> m_drawingTable;
        uint32_t m_gameCode;
        std::unordered_map<int, std::time_t> m_correctAnswerTimes;// timpul pentru fiecare player
        std::time_t m_currentRoundStartTime;
    
    };
}