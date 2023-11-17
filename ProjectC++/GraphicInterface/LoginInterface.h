#pragma once

#include <QMainWindow>
#include "ui_LoginInterface.h"
#include <qmessagebox.h>

class LoginInterface : public QMainWindow
{
	Q_OBJECT

public:
	LoginInterface(QWidget *parent = nullptr);
	~LoginInterface();

private slots:
	void on_pushButton_LogIn_clicked();
	void on_pushButton_4_clicked();
	/*void onLoginButtonClicked();*/

private:
	Ui::LoginInterfaceClass ui;
};
