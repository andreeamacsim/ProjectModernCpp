#pragma once

#include <QMainWindow>
#include "ui_ProfileInterface.h"
#include <cpr/cpr.h>
#include <crow.h>

class ProfileInterface : public QMainWindow
{
	Q_OBJECT

public:
	ProfileInterface(QString username,QWidget *parent = nullptr);
	~ProfileInterface();
public slots:
	void goToLobby();
	

private:
	QString m_username;
	Ui::ProfileInterfaceClass ui;
};
