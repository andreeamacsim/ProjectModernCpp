#include "LobbyInterface.h"
#include <QPixmap>
#include "ProfileInterface.h"
#include "DrawingInterface.h"
#include "Chat.h"
#include <ctime>

LobbyInterface::LobbyInterface(std::string username,bool owner,std::string lobbyCode,QWidget *parent)
	: QMainWindow(parent)
{
	m_username = username;
	m_Owner = owner;
	m_lobbyCode = lobbyCode;
	ui.setupUi(this);
	showButtons();
	connect(ui.generateCode, &QPushButton::clicked, this, &LobbyInterface::generateCode);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &LobbyInterface::goToProfile);
	connect(ui.startGame, &QPushButton::clicked, this, &LobbyInterface::goToDrawing);
	connect(ui.Easy, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Medium, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Hard, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Romanian, &QPushButton::clicked, this, &LobbyInterface::setLanguage);
	connect(ui.English, &QPushButton::clicked, this, &LobbyInterface::setLanguage);
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/joinGameLobby" }, cpr::Parameters{
	{"username",m_username}
		});
	ui.code->setText(QString::fromUtf8(m_lobbyCode));

}
void LobbyInterface::setLanguage()
{

	int language=-1;
	if (ui.Romanian->isChecked())
		language = 0;
	else if (ui.English->isChecked())
		language = 1;
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/setLanguage" }, cpr::Parameters{
		{"language",std::to_string(language)}
		});
}
void LobbyInterface::setDifficulty()
{
	int difficulty = -1;
	if (ui.Easy->isChecked())
		difficulty = 0;
	else if (ui.Medium->isChecked())
		difficulty = 1;
	else if (ui.Hard->isChecked())
		difficulty = 2;
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/setDifficulty" }, cpr::Parameters{
	{"difficulty",std::to_string(difficulty)}
		});
}
void LobbyInterface::goToProfile()
{
	ProfileInterface* profileInterface = new ProfileInterface(m_username);
	this->close();
	profileInterface->show();
}
LobbyInterface::~LobbyInterface()
{}

void LobbyInterface::setOwner(bool owner)
{
	this->m_Owner = owner;
}

void LobbyInterface::showButtons()
{
		ui.Romanian->setEnabled(m_Owner);
		ui.English->setEnabled(m_Owner);
		ui.Easy->setEnabled(m_Owner);
		ui.Medium->setEnabled(m_Owner);
		ui.Hard->setEnabled(m_Owner);
		ui.generateCode->setEnabled(m_Owner);
}

void LobbyInterface::goToDrawing()
{
	DrawingInterface* drawingInterface = new DrawingInterface(m_username);
	Chat* chatInterface = new Chat(m_username);
	this->close();
	drawingInterface->show();
	chatInterface->show();
}
void LobbyInterface::generateCode()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/generateLobbyCode" });
	auto generatedCodeJSON = crow::json::load(response.text);
	m_lobbyCode = generatedCodeJSON["generatedCode"].s();

	QString code = QString::fromUtf8(m_lobbyCode);
	ui.code->setText(code);
}
