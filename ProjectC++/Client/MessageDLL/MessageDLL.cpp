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

const char* MessageDLL::GetMessageText(LoginStatus status)
{
    switch (status) {
    case MessageDLL::LoginStatus::Connected:
        return "Username and password are correct";
    case MessageDLL::LoginStatus::AlreadyConnected:
        return "User is already connected";
    case MessageDLL::LoginStatus::IncorrectCredentials:
        return "Username and password are incorrect";
    }
    return "";
}




/*std::string MessageDLL::GetCurrentWordFromServer()
{
    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/getword" });
    return wordResponse.text;
    return "";
}*/