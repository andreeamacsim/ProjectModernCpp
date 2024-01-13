//#include <cpr/cpr.h>
#include "MessageDLL.h";
#include <iostream>;



MessageDLL::GameResult MessageDLL::CheckAnswer(int response)
{
    GameResult result = TryAgain;


    if (response==200) {
        result = Congratulations;
    }
    return result;
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
    }

    return message;
}




/*std::string MessageDLL::GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
    return "";
}*/