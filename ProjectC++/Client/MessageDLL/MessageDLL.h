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
        AlreadyConnected,
        IncorrectCredentials

    };

    static GameResult CheckAnswer(int response);
    static LoginStatus GetMessageStatus(bool find, bool alreadyConnected, bool incorrectCredentials);
    static std::string GetMessageText(LoginStatus status);
    
};