
#include "LoginInterface.h"
#include "CreateAccount.h"
#include "../MessageDLL/MessageDLL.h"
#include "PickJoinLobby.h"

LoginInterface::LoginInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &LoginInterface::on_pushButton_4_clicked);
    connect(ui.LogIn, &QPushButton::clicked, this, &LoginInterface::logIn);
}

void LoginInterface::on_pushButton_4_clicked()
{
	CreateAccount* create = new CreateAccount(this);
	this->hide();
	create->show();
}

void LoginInterface::logIn()
{
    bool found = false;
    MessageDLL::LoginStatus loginResult;

    std::string username = ui.userName->text().toUtf8().constData();
    std::string password = ui.password->text().toUtf8().constData();

    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/verifyUser" }, cpr::Parameters{
        {"username", username},
        {"password", password}
        });

    if (response.status_code == 200)
    {
        found = true;
        cpr::Response response1 = cpr::Get(cpr::Url{ "http://localhost:18080/checkAlreadyConnected" }, cpr::Parameters{
            {"username", username}
            });

        if (response1.status_code == 405 && found == true)
        {
            loginResult = MessageDLL::GetMessageStatus(found, false, false);
            //auto  mess = MessageDLL::GetMessageText(loginResult);
            //QString message = QString::fromStdString(mess);
            QMessageBox::information(this, "Login","da");
            PickJoinLobby* pickJoinInterface = new PickJoinLobby(this);
            pickJoinInterface->show();
            this->hide();
            cpr::Response resp = cpr::Get(cpr::Url{ "http://localhost:18080/connectedPlayers" }, cpr::Parameters{
                {"username", username}
                });
        }
        else if (response1.status_code == 200 && found == true)
        {
            loginResult = MessageDLL::GetMessageStatus(found, true, false);
            //auto mess = MessageDLL::GetMessageText(loginResult);
           // QString message = QString::fromStdString(mess);
            QMessageBox msgBox(QMessageBox::Warning, "Login", "ac", QMessageBox::Ok, this);
            msgBox.setStyleSheet("QPushButton { color: white; }");
            msgBox.exec();
        }
    }
    else
    {
        loginResult = MessageDLL::GetMessageStatus(found, false, true);
        //auto mess = MessageDLL::GetMessageText(loginResult);
       // QString message = QString::fromStdString(mess);

        QMessageBox msgBox(QMessageBox::Warning, "Login", "nu", QMessageBox::Ok, this);
        msgBox.setStyleSheet("QPushButton { color: white; }");
        msgBox.exec();
    }
}


LoginInterface::~LoginInterface()
{
    QString usernameQStr = ui.userName->text();
    std::string username= usernameQStr.toUtf8().constData();
    cpr::Response resp = cpr::Get(cpr::Url{ "http://localhost:18080/disconnectPlayer" }, cpr::Parameters{
        {"username",username} });
}
