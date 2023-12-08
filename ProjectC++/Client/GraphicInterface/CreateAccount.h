#pragma once

#include <QMainWindow>
#include "ui_CreateAccount.h"

class CreateAccount : public QMainWindow
{
	Q_OBJECT

public:
	CreateAccount(QWidget *parent = nullptr);
	~CreateAccount();

private:
	Ui::CreateAccountClass ui;
private slots:
	void on_backButton_clicked();
};
