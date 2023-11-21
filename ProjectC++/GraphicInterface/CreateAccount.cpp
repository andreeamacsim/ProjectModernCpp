#include "CreateAccount.h"
#include "LoginInterface.h"

CreateAccount::CreateAccount(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
}

CreateAccount::~CreateAccount()
{}

void CreateAccount::on_backButton_clicked()
{
	LoginInterface* loginInterface = new LoginInterface(this);
    loginInterface->show();
    this->hide();
}
