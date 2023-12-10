#pragma once

#include <QMainWindow>
#include "ui_Chat.h"

class Chat : public QMainWindow
{
	Q_OBJECT

public:
	Chat(QWidget *parent = nullptr);
	~Chat();

private slots:
	void sendMessage();

private:
	Ui::ChatClass ui;
};