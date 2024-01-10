#include "PickJoinLobby.h"
#include "LobbyInterface.h"
#include "JoinLobby.h"

PickJoinLobby::PickJoinLobby(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.joinLobby, &QPushButton::clicked, this, &PickJoinLobby::toJoinLobby);
	connect(ui.createLobby, &QPushButton::clicked, this, &PickJoinLobby::toCreateLobby);
}

PickJoinLobby::~PickJoinLobby()
{}
void PickJoinLobby::toCreateLobby()
{
	bool owner = true;
	LobbyInterface* lobby = new LobbyInterface(owner,this);
	lobby->show();
	this->hide();
}
void PickJoinLobby::toJoinLobby()
{
	JoinLobby* lobby = new JoinLobby(this);
	lobby->show();
	this->hide();
}
