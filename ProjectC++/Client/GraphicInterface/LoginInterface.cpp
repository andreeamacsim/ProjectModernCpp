
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
    QString usernameQStr = ui.userName->text();
    std::string username = usernameQStr.toUtf8().constData();
    QString passwordQStr = ui.password->text();
    std::string password = passwordQStr.toUtf8().constData();
    QString message;
    std::string email;
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/verifyUser" }, cpr::Parameters{
        {"username",username}
        });
    if (response.status_code == 200)
        found = true;
    MessageDLL::LoginStatus loginStatus = MessageDLL::DisplayLoginMessage(found);

    if (loginStatus == MessageDLL::Connected)
    {
        message = "<font color='white'>Username and password are correct</font>";
        QMessageBox::information(this, "Login", message);
        ProfileInterface* profileInterface = new ProfileInterface(this);
        QString emailQStr = QString::fromUtf8(email);
        profileInterface->initialize(usernameQStr, emailQStr);
        profileInterface->show();
        this->hide();
    }
    else
    {
        message = "<font color='white'>Username and password are incorrect</font>";
        QMessageBox msgBox(QMessageBox::Warning, "Login", message, QMessageBox::Ok, this);
        msgBox.setStyleSheet("QPushButton { color: white; }");
        msgBox.exec();
    }
    cpr::Response resp = cpr::Get(cpr::Url{ "http://localhost:18080/connectedPlayers" }, cpr::Parameters{
    {"username",username}});
}

LoginInterface::~LoginInterface()
{}
