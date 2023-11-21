#include "LobbyInterface.h"
#include <QPixmap>
#include "ProfileInterface.h"
#include "DrawingInterface.h"

LobbyInterface::LobbyInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &LobbyInterface::goToProfile);
	connect(ui.pushButton_6, &QPushButton::clicked, this, &LobbyInterface::goToDrawing);

}
void LobbyInterface::goToProfile()
{
	ProfileInterface* profileInterface = new ProfileInterface();
	this->close();
	profileInterface->show();
}
LobbyInterface::~LobbyInterface()
{}

void LobbyInterface::goToDrawing()
{
	DrawingInterface* drawingInterface = new DrawingInterface();
	this->close();
	drawingInterface->show();
}
