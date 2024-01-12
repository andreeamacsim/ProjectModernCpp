#pragma once

#include <QMainWindow>
#include "ui_Chat.h"

class Chat : public QMainWindow
{
	Q_OBJECT

public:
	Chat(std::string username,QWidget *parent = nullptr);
	~Chat();
	QString getLastSentMessage() const;
	void checkAnswerAndShowMessage();

private slots:
	void sendMessage();

private:
	std::string m_username;
	Ui::ChatClass ui;
	QString lastSentMessage;

};
