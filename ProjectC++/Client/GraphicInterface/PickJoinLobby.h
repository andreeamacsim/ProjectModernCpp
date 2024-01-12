#pragma once

#include <QMainWindow>
#include "ui_PickJoinLobby.h"

class PickJoinLobby : public QMainWindow
{
	Q_OBJECT

public:
	PickJoinLobby(std::string username,QWidget *parent = nullptr);
	~PickJoinLobby();
private slots:
	void toCreateLobby();
	void toJoinLobby();
private:
	Ui::PickJoinLobbyClass ui;
	std::string m_username;
};
