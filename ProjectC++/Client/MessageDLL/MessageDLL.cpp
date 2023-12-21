#include "MessageDLL.h"
#include <cpr/cpr.h>


int MessageDLL::CheckAnswer(const char* answer)
{
    GameResult result = TryAgain;

    std::string currentWord = GetCurrentWordFromServer();

    if (strcmp(answer, currentWord.c_str()) == 0) {
        result = Congratulations;
    }

    return static_cast<int>(result);
}

std::string GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
}