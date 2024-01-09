//#include <cpr/cpr.h>
#include "MessageDLL.h";
#include <iostream>;


MessageDLL::GameResult MessageDLL::CheckAnswer(const char* answer, const std::string& currentWord)
{
    GameResult result = TryAgain;


    if (strcmp(answer, currentWord.c_str()) == 0) {
        result = Congratulations;
    }
    return result;
}

MessageDLL::LoginStatus MessageDLL::DisplayLoginMessage(bool find, bool alreadyConnected, bool incorrectCredentials)
{
    if (find && !alreadyConnected && !incorrectCredentials)
        return Connected;
    else if (alreadyConnected)
        return AlreadyConnected;
    else if (incorrectCredentials)
        return IncorrectCredentials;
    else
        return NotConnected;
}



/*std::string MessageDLL::GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
    return "";
}*/