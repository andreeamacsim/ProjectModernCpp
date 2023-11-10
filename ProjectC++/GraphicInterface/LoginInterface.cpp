#include "LoginInterface.h"

LoginInterface::LoginInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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
LoginInterface::~LoginInterface()
{}
