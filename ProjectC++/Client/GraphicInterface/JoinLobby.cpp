#include "JoinLobby.h"
#include <cpr/cpr.h>
#include <crow.h>
#include "LobbyInterface.h"
#include <qmessagebox.h>

JoinLobby::JoinLobby(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.connectButton, &QPushButton::clicked, this, &JoinLobby::connectButton);
}
void JoinLobby::connectButton()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/getLobbyCode" });
	auto generatedCodeJSON = crow::json::load(response.text);
	std::string generatedCode = generatedCodeJSON["generatedCode"].s();

	QString code = QString::fromUtf8(generatedCode);

	if (ui.lineEdit->text()==code)
	{
		LobbyInterface* lobby = new LobbyInterface();
		lobby->show();
		this->hide();
	}
	else
	{
		QMessageBox::warning(this, "Error", "Inncorect Code");
	}
}
JoinLobby::~JoinLobby()
{}
