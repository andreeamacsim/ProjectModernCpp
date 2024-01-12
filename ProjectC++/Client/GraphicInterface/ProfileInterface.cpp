#include "ProfileInterface.h"
#include "LobbyInterface.h"

ProfileInterface::ProfileInterface(std::string username,QWidget *parent)
	: QMainWindow(parent)
{
	this->m_username = username;
	ui.setupUi(this);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &ProfileInterface::goToLobby);

}
void ProfileInterface::goToLobby()
{
	LobbyInterface* lobbyInterface = new LobbyInterface(m_username);
	this->close();
	lobbyInterface->show();
}

ProfileInterface::~ProfileInterface()
{}


