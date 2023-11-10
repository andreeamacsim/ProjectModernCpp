#pragma once

#include <QMainWindow>
#include "ui_LoginInterface.h"

class LoginInterface : public QMainWindow
{
	Q_OBJECT

public:
	LoginInterface(QWidget *parent = nullptr);
	~LoginInterface();

private:
	Ui::LoginInterfaceClass ui;
};
