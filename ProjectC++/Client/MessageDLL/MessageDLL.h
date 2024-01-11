#pragma once
#include <string>

#ifdef MESSAGEDLL_EXPORTS
#define MESSAGEDLL_API __declspec(dllexport)
#else
#define MESSAGEDLL_API __declspec(dllimport)
#endif

class MESSAGEDLL_API MessageDLL {
public:
    enum GameResult {
        Congratulations,
        TryAgain
    };

    enum LoginStatus {
        Connected,
        NotConnected,
        AlreadyConnected,
        IncorrectCredentials

    };

    static GameResult CheckAnswer(const char* answer, const std::string& currentWord);
    //static std::pair<LoginStatus, std::string> DisplayLoginMessage(bool find, bool alreadyConnected, bool incorrectCredentials);
    static LoginStatus DisplayLoginMessage2(bool find, bool alreadyConnected, bool incorrectCredentials);
    LoginStatus GetMessageStatus(bool find, bool alreadyConnected, bool incorrectCredentials);
    std::string GetMessageText(LoginStatus status);
    
};