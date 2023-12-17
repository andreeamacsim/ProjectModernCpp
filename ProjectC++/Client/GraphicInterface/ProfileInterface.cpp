#include "ProfileInterface.h"
#include "LobbyInterface.h"

ProfileInterface::ProfileInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &ProfileInterface::goToLobby);
	ui.usernameLabel->setText(m_username);
	ui.emailLabel->setText(m_email);
}
void ProfileInterface::goToLobby()
{
	LobbyInterface* lobbyInterface = new LobbyInterface();
	this->close();
	lobbyInterface->show();
}

ProfileInterface::~ProfileInterface()
{}

void ProfileInterface::initialize(const QString & username, const QString & email)
{
	m_username = username;
	m_email = email;

	ui.usernameLabel->setText(m_username);
	ui.emailLabel->setText(m_email);
}

