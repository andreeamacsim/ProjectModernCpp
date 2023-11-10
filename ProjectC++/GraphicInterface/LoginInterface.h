#pragma once

#include <QMainWindow>
#include "ui_LoginInterface.h"

class LoginInterface : public QMainWindow
{
	Q_OBJECT

public:
	LoginInterface(QWidget *parent = nullptr);
	~LoginInterface();
private slots:
	void on_pushButton_LogIn_clicked();

private:
	Ui::LoginInterfaceClass ui;
};
