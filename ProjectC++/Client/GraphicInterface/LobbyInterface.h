#pragma once

#include <QMainWindow>
#include "ui_LobbyInterface.h"

class LobbyInterface : public QMainWindow
{
	Q_OBJECT

public:
	LobbyInterface(std::string username,QWidget *parent = nullptr);
	LobbyInterface(std::string username,bool Owner,QWidget *parent = nullptr);
	~LobbyInterface();
	void setOwner(bool owner);
public slots:
	void generateCode();
	void setLanguage();
	void setDifficulty();
	void goToProfile();
	void goToDrawing();
private:
	std::string m_username;
	bool m_Owner;
	Ui::LobbyInterfaceClass ui;
};
