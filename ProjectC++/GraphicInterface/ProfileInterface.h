#pragma once

#include <QMainWindow>
#include "ui_ProfileInterface.h"

class ProfileInterface : public QMainWindow
{
	Q_OBJECT

public:
	ProfileInterface(QWidget *parent = nullptr);
	~ProfileInterface();
public slots:
	void goToLobby();

private:
	Ui::ProfileInterfaceClass ui;
};
