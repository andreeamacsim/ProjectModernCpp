#include "LoginInterface.h"
#include "CreateAccount.h"

LoginInterface::LoginInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &LoginInterface::on_pushButton_4_clicked);
}
void LoginInterface::on_pushButton_LogIn_clicked()
{
	QString username = ui.userName->text();
	QString password = ui.password->text();

	if (username == "test" && password == "test")
	{
		QMessageBox::information(this, "Login", "Username and password is corect");
	}
	else
		QMessageBox::warning(this, "Login", "Username and password is inncorect");
}
void LoginInterface::on_pushButton_4_clicked()
{
	CreateAccount* create = new CreateAccount(this);
	create->show();
}

LoginInterface::~LoginInterface()
{}
