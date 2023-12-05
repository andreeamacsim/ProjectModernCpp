
#include "LoginInterface.h"
#include "CreateAccount.h"

LoginInterface::LoginInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &LoginInterface::on_pushButton_4_clicked);
	connect(ui.pushButton_LogIn, &QPushButton::clicked, this, &LoginInterface::onLoginButtonClicked);
}
void LoginInterface::on_pushButton_LogIn_clicked()
{
    QString username = ui.userName->text();
    QString password = ui.password->text();
    QString message;

    if (username == "test" && password == "test")
    {
        message = "<font color='white'>Username and password are correct</font>";
        QMessageBox::information(this, "Login", message);
    }
    else
    {
        message = "<font color='white'>Username and password are incorrect</font>";
        QMessageBox msgBox(QMessageBox::Warning, "Login", message, QMessageBox::Ok, this);
        msgBox.setStyleSheet("QPushButton { color: white; }");
        msgBox.exec();
    }
}
void LoginInterface::on_pushButton_4_clicked()
{
	CreateAccount* create = new CreateAccount(this);
	this->hide();
	create->show();
}

LoginInterface::~LoginInterface()
{}

void LoginInterface::onLoginButtonClicked()
{
	ProfileInterface* profileInterface = new ProfileInterface(this);
	profileInterface->show();
	this->hide();
}