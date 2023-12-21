#include "Chat.h"
#include "DrawingInterface.h"
#include "../MessageDLL/MessageDLL.h"
#include <qmessagebox.h>

Chat::Chat(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &Chat::sendMessage);
	
}

Chat::~Chat()
{}
QString Chat::getLastSentMessage() const
{
	return lastSentMessage;
}
void Chat::checkAnswerAndShowMessage()
{
    QString userAnswer = getLastSentMessage();

    QByteArray byteArray = userAnswer.toUtf8();
    const char* answer = byteArray.constData();

    int result = MessageDLL::CheckAnswer(answer);

    if (result == MessageDLL::Congratulations) {
        QMessageBox::information(this, "Felicitari!", "Cuvantul este corect!");
    }
    else {
        QMessageBox::warning(this, "Incercare", "Cuvantul este gresit. Incearca din nou.");
    }
}
void Chat::sendMessage()
{
    QString message = ui.textEdit->toPlainText();
    ui.listWidget->addItem(message);
    ui.textEdit->clear();
	lastSentMessage = message;
    checkAnswerAndShowMessage();


}