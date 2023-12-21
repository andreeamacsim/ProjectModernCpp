#pragma once

#ifdef MESSAGEDLL_EXPORTS
#define MESSAGEDLL_API __declspec(dllexport)
#else
#define MESSAGEDLL_API __declspec(dllimport)
#endif

enum GameResult {
    Congratulations,
    TryAgain
};

class MESSAGEDLL_API MessageDLL {
public:
    static int CheckAnswer(const char* answer);
};