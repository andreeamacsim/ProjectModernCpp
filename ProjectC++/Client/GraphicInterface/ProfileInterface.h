#pragma once

#include <QMainWindow>
#include "ui_ProfileInterface.h"
#include <cpr/cpr.h>
#include <crow.h>

class ProfileInterface : public QMainWindow
{
	Q_OBJECT

public:
	ProfileInterface(std::string username,QWidget *parent = nullptr);
	~ProfileInterface();
public slots:
	void goToLobby();
	

private:
	std::string m_username;
	Ui::ProfileInterfaceClass ui;
};
