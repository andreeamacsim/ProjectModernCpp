#pragma once

#include <QMainWindow>
#include "ui_JoinLobby.h"

class JoinLobby : public QMainWindow
{
	Q_OBJECT

public:
	JoinLobby(QString username,QWidget *parent = nullptr);
	~JoinLobby();
private slots:
	void connectButton();
private:
	QString m_username;
	Ui::JoinLobbyClass ui;
};
