#include "pch.h"
#include "MessageDLL.h"

int MessageDLL::CheckAnswer(const char* answer) {
    GameResult result = TryAgain;
    if (strcmp(answer, "CuvantCorect") == 0) {
        result = Congratulations;
    }

    return static_cast<int>(result);
}

