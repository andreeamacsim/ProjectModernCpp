#pragma once

#include <QMainWindow>
#include "ui_LobbyInterface.h"

class LobbyInterface : public QMainWindow
{
	Q_OBJECT

public:
	LobbyInterface(std::string username,bool owner,std::string lobbyCode,QWidget *parent = nullptr);
	~LobbyInterface();
	void setOwner(bool owner);
	void showButtons();
	void showConnectedPlayers();
public slots:
	void generateCode();
	void setLanguage();
	void setDifficulty();
	void goToProfile();
	void goToDrawing();
private:
	int m_attempts = 0;
	QTimer* m_connectedPlayersTimer;
	std::string m_lobbyCode;
	std::string m_username;
	bool m_Owner;
	Ui::LobbyInterfaceClass ui;
};
