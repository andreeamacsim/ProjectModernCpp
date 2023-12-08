#include "Chat.h"

Chat::Chat(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &Chat::sendMessage);
	
}

Chat::~Chat()
{}
void Chat::sendMessage()
{
    QString message = ui.textEdit->toPlainText();
    ui.listWidget->addItem(message);
    ui.textEdit->clear();
}