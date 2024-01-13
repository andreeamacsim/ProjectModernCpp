#include "Chat.h"
#include <cpr/cpr.h>
#include "DrawingInterface.h"
#include "../MessageDLL/MessageDLL.h"
#include <qmessagebox.h>

Chat::Chat(std::string username,QWidget *parent)
	: QMainWindow(parent)
{
    this->m_username = username;
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

    cpr::Response wordResponse = cpr::Get(cpr::Url{ "http://localhost:18080/checkIfWordIsCorrect" }, cpr::Parameters{
        {"username",m_username},
        {"word",answer}
        });
    int code = wordResponse.status_code;
    int result = MessageDLL::CheckAnswer(code);

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