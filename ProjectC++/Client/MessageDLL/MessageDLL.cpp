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


MessageDLL::LoginStatus MessageDLL::DisplayLoginMessage2(bool find, bool alreadyConnected, bool incorrectCredentials)
{
    LoginStatus status;
    std::string message;

    if (find && !alreadyConnected && !incorrectCredentials) {
        status = LoginStatus::Connected;
        message = "Username and password are correct";
    }
    else if (alreadyConnected) {
        status = LoginStatus::AlreadyConnected;
        message = "User is already connected";
    }
    else if (incorrectCredentials) {
        status = LoginStatus::IncorrectCredentials;
        message = "Username and password are incorrect";
    }
    else {
        status = LoginStatus::NotConnected;
        message = "";
    }

    return status;
}

MessageDLL::LoginStatus MessageDLL::GetMessageStatus(bool find, bool alreadyConnected, bool incorrectCredentials)
{
     LoginStatus status;

     if (find && !alreadyConnected && !incorrectCredentials) {
         status = LoginStatus::Connected;
     }
     else if (alreadyConnected) {
         status = LoginStatus::AlreadyConnected;
     }
     else if (incorrectCredentials) {
         status = LoginStatus::IncorrectCredentials;
     }
     else {
         status = LoginStatus::NotConnected;
     }

     return status;
}

std::string MessageDLL::GetMessageText(LoginStatus status)
{
    std::string message;

    switch (status) {
    case MessageDLL::LoginStatus::Connected:
        message = "Username and password are correct";
        break;
    case MessageDLL::LoginStatus::AlreadyConnected:
        message = "User is already connected";
        break;
    case MessageDLL::LoginStatus::IncorrectCredentials:
        message = "Username and password are incorrect";
        break;
    case MessageDLL::LoginStatus::NotConnected:
        message = "";
        break;
    }

    return message;
}




/*std::string MessageDLL::GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
    return "";
}*/