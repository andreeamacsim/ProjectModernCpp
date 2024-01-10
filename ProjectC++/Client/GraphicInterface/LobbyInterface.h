#pragma once

#include <QMainWindow>
#include "ui_LobbyInterface.h"

class LobbyInterface : public QMainWindow
{
	Q_OBJECT

public:
	LobbyInterface(QWidget *parent = nullptr);
	LobbyInterface(bool Owner,QWidget *parent = nullptr);
	~LobbyInterface();
	void setOwner(bool owner);
public slots:
	void generateCode();
	void setLanguage();
	void setDifficulty();
	void goToProfile();
	void goToDrawing();
private:
	bool m_Owner;
	Ui::LobbyInterfaceClass ui;
};
