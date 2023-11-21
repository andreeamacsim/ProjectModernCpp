#pragma once

#include <QMainWindow>
#include "ui_LobbyInterface.h"

class LobbyInterface : public QMainWindow
{
	Q_OBJECT

public:
	LobbyInterface(QWidget *parent = nullptr);
	~LobbyInterface();

private:
	Ui::LobbyInterfaceClass ui;
};
