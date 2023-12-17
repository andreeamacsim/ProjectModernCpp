#pragma once

#include <QMainWindow>
#include "ui_ProfileInterface.h"
#include <cpr/cpr.h>
#include <crow.h>

class ProfileInterface : public QMainWindow
{
	Q_OBJECT

public:
	ProfileInterface(QWidget *parent = nullptr);
	~ProfileInterface();
	void initialize(const QString& username, const QString& email);
public slots:
	void goToLobby();
	

private:
	QString m_username;
	QString m_email;

	Ui::ProfileInterfaceClass ui;
};
