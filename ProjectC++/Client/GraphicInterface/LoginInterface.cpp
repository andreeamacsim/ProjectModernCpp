
#include "LoginInterface.h"
#include "CreateAccount.h"
#include "../MessageDLL/MessageDLL.h"

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
    QString message;
    MessageDLL::LoginStatus loginStatus;
    QString email;
    std::string username = ui.userName->text().toUtf8().constData();
    std::string password = ui.password->text().toUtf8().constData();
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/verifyUser" }, cpr::Parameters{
        {"username",username},
        {"password",password}
        });
    if (response.status_code == 200)
    {
        found = true;
        cpr::Response response1 = cpr::Get(cpr::Url{ "http://localhost:18080/checkAlreadyConnected" }, cpr::Parameters{
    {"username",username}
            });
        if (response1.status_code == 405 && found == true)
        {
            loginStatus = MessageDLL::DisplayLoginMessage(found, false, false);
        }
        else if (response1.status_code == 200 && found == true)
        {
            loginStatus = MessageDLL::DisplayLoginMessage(found, true, false);
        }
        if (loginStatus == MessageDLL::Connected)
        {
            message = "<font color='white'>Username and password are correct</font>";
            QMessageBox::information(this, "Login", message);
            ProfileInterface* profileInterface = new ProfileInterface(this);
            profileInterface->initialize(QString::fromUtf8(username), email);
            profileInterface->show();
            this->hide();
            cpr::Response resp = cpr::Get(cpr::Url{ "http://localhost:18080/connectedPlayers" }, cpr::Parameters{
            {"username",username} });
        }
        else if (loginStatus == MessageDLL::AlreadyConnected)
        {
            message = "<font color='white'>User is already connected</font>";
            QMessageBox::information(this, "Login", message);
        }

    }
    else
    {
        loginStatus = MessageDLL::DisplayLoginMessage(found, false, true);
        message = "<font color='white'>Username and password are incorrect</font>";
        QMessageBox msgBox(QMessageBox::Warning, "Login", message, QMessageBox::Ok, this);
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
