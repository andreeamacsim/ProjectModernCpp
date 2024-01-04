#pragma once

#include <QMainWindow>
#include "ui_LoginInterface.h"
#include <qmessagebox.h>
#include "ProfileInterface.h"
#include "ui_ProfileInterface.h"



class LoginInterface : public QMainWindow
{
	Q_OBJECT

public:
	LoginInterface(QWidget *parent = nullptr);
	~LoginInterface();

private slots:
	void on_pushButton_4_clicked();
	void logIn();

private:
	Ui::LoginInterfaceClass ui;
};
