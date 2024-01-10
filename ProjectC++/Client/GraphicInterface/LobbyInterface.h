#pragma once

#include <QMainWindow>
#include "ui_LobbyInterface.h"

class LobbyInterface : public QMainWindow
{
	Q_OBJECT

public:
	LobbyInterface(QWidget *parent = nullptr);
	~LobbyInterface();
public slots:
	void setLanguage();
	void setDifficulty();
	void goToProfile();
	void goToDrawing();
private:
	Ui::LobbyInterfaceClass ui;
};
