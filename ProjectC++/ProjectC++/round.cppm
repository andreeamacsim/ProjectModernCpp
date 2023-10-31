module;
import <vector>;
import <string>;

export module round;

export class Round
{
public:
    Round();
    Round(const std::string& word, const std::string& drawer);
    void AddGuess(const std::string& guess);
    bool IsGuessed() const;
    const std::string& GetWord();
    const std::string& GetDrawer();
    const std::vector<std::string>& GetGuesses();
    std::vector<std::string> GetGuessesForPlayer(const std::string& player);

private:
    std::string m_word;
    std::string m_drawer;
    std::vector<std::string> m_guesses;
    bool m_guessed;
};