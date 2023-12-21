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

    static int CheckAnswer(const char* answer);
    static std::string GetCurrentWordFromServer();
};