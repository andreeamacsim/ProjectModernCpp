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
    static LoginStatus DisplayLoginMessage(bool find, bool alreadyConnected, bool incorrectCredentials);
    
};