#pragma once

#include <QMainWindow>
#include "ui_JoinLobby.h"

class JoinLobby : public QMainWindow
{
	Q_OBJECT

public:
	JoinLobby(QWidget *parent = nullptr);
	~JoinLobby();

private:
	Ui::JoinLobbyClass ui;
};
