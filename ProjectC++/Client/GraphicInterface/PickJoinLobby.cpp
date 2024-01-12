#include "PickJoinLobby.h"
#include "LobbyInterface.h"
#include "JoinLobby.h"

PickJoinLobby::PickJoinLobby(std::string username,QWidget *parent)
	: QMainWindow(parent)
{
	m_username = username;
	ui.setupUi(this);
	connect(ui.joinLobby, &QPushButton::clicked, this, &PickJoinLobby::toJoinLobby);
	connect(ui.createLobby, &QPushButton::clicked, this, &PickJoinLobby::toCreateLobby);
}

PickJoinLobby::~PickJoinLobby()
{}
void PickJoinLobby::toCreateLobby()
{
	bool owner = true;
	LobbyInterface* lobby = new LobbyInterface(m_username,owner," ");
	lobby->show();
	this->hide();
}
void PickJoinLobby::toJoinLobby()
{
	JoinLobby* lobby = new JoinLobby(m_username,this);
	lobby->show();
	this->hide();
}
