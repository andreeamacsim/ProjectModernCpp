#include "LobbyInterface.h"
#include <QPixmap>
#include "ProfileInterface.h"
#include "DrawingInterface.h"
#include "Chat.h"

LobbyInterface::LobbyInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.Romanian->setEnabled(m_Owner);
	ui.English->setEnabled(m_Owner);
	ui.Easy->setEnabled(m_Owner);
	ui.Medium->setEnabled(m_Owner);
	ui.Hard->setEnabled(m_Owner);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &LobbyInterface::goToProfile);
	connect(ui.pushButton_6, &QPushButton::clicked, this, &LobbyInterface::goToDrawing);
	connect(ui.Easy, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Medium, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Hard, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Romanian, &QPushButton::clicked, this, &LobbyInterface::setLanguage);
	connect(ui.English, &QPushButton::clicked, this, &LobbyInterface::setLanguage);

}
LobbyInterface::LobbyInterface(bool Owner, QWidget* parent) :QMainWindow(parent),m_Owner{Owner}
{
	ui.setupUi(this);
	ui.Romanian->setEnabled(m_Owner);
	ui.English->setEnabled(m_Owner);
	ui.Easy->setEnabled(m_Owner);
	ui.Medium->setEnabled(m_Owner);
	ui.Hard->setEnabled(m_Owner);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &LobbyInterface::goToProfile);
	connect(ui.pushButton_6, &QPushButton::clicked, this, &LobbyInterface::goToDrawing);
	connect(ui.Easy, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Medium, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Hard, &QPushButton::clicked, this, &LobbyInterface::setDifficulty);
	connect(ui.Romanian, &QPushButton::clicked, this, &LobbyInterface::setLanguage);
	connect(ui.English, &QPushButton::clicked, this, &LobbyInterface::setLanguage);
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
	ProfileInterface* profileInterface = new ProfileInterface();
	this->close();
	profileInterface->show();
}
LobbyInterface::~LobbyInterface()
{}

void LobbyInterface::setOwner(bool owner)
{
	this->m_Owner = owner;
}

void LobbyInterface::goToDrawing()
{
	DrawingInterface* drawingInterface = new DrawingInterface();
	Chat* chatInterface = new Chat();
	this->close();
	drawingInterface->show();
	chatInterface->show();
}
