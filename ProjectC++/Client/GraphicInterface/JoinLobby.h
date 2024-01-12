#pragma once

#include <QMainWindow>
#include "ui_JoinLobby.h"

class JoinLobby : public QMainWindow
{
	Q_OBJECT

public:
	JoinLobby(std::string username,QWidget *parent = nullptr);
	~JoinLobby();
private slots:
	void connectButton();
private:
	std::string m_username;
	Ui::JoinLobbyClass ui;
};
