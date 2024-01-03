//#include <cpr/cpr.h>
#include "MessageDLL.h"


int MessageDLL::CheckAnswer(const char* answer, const std::string& currentWord)
{
    GameResult result = TryAgain;

    //std::string currentWord = GetCurrentWordFromServer();

    if (strcmp(answer, currentWord.c_str()) == 0) {
        result = Congratulations;
    }

    return static_cast<int>(result);
}

/*std::string MessageDLL::GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
    return "";
}*/