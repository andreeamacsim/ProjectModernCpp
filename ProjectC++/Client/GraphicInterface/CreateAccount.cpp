#include "CreateAccount.h"
#include "LoginInterface.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <string>
#include <sstream>
#include <numeric>


CreateAccount::CreateAccount(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
	connect(ui.register_2, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
}

CreateAccount::~CreateAccount()
{}


void CreateAccount::on_register_2_clicked()
{
	QString usernameQStr = ui.usernameLabel->text();
	QString passwordQstr = ui.passwordLabel->text();
	QString emailQStr = ui.emailLabel->text();

	std::string username = usernameQStr.toUtf8().constData();
	std::string password = passwordQstr.toUtf8().constData();
	std::string email = emailQStr.toUtf8().constData();
	std::stringstream urlBuilder;
	int id = 1;
	cpr::Parameters parameters = cpr::Parameters{
			{"username", username},
			{ "password",password},
			{ "email",email} };
	urlBuilder << "http://localhost:18080/addplayertogame/" << id;
	auto b = urlBuilder.str();
	auto response = cpr::Get(
		cpr::Url{ urlBuilder.str() },parameters
	);
	if (response.status_code == 200 || response.status_code == 201) {
		QMessageBox::information(this, "Register", "Register completed");
	}
	else if(response.status_code==400)
		QMessageBox::information(this, "Register", "Username is already used.");
	else {
		QMessageBox::warning(this, "Register", "Registration error");
	}
}

void CreateAccount::on_backButton_clicked()
{
	LoginInterface* loginInterface = new LoginInterface(this);
    loginInterface->show();
    this->hide();
}
