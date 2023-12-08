#include "ProfileInterface.h"
#include "LobbyInterface.h"

ProfileInterface::ProfileInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &ProfileInterface::goToLobby);
}
void ProfileInterface::goToLobby()
{
	LobbyInterface* lobbyInterface = new LobbyInterface();
	this->close();
	lobbyInterface->show();
}

ProfileInterface::~ProfileInterface()
{}
