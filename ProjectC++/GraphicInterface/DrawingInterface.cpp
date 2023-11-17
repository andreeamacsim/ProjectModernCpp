#include "DrawingInterface.h"
#include <QColorDialog>
#include <QInputDialog>

DrawingInterface::DrawingInterface(QWidget *parent)
	: QMainWindow(parent)
{ 
	ui.setupUi(this);
	m_drawingArea = new DrawingClass;
	setWindowTitle("Gartic");
	changeColorButton = ui.changeColorButton;
	connect(changeColorButton, &QPushButton::clicked, this, &DrawingInterface::changePenColor);

	changeWidthButton = ui.changeWidthButton;
	connect(changeWidthButton, &QPushButton::clicked, this, &DrawingInterface::changePenWidth);
}

DrawingInterface::~DrawingInterface()
{

}
void DrawingInterface::changePenColor()
{
	QColor penColor = QColorDialog::getColor(m_drawingArea->getPenColor());
	if (penColor.isValid())
		m_drawingArea->setPenColor(penColor);
}
void DrawingInterface::changePenWidth()
{
	bool ok;
	uint8_t penWidth = QInputDialog::getInt(this, "Change pen width", "Width:", m_drawingArea->getPenWidth(), 1, 255, 1, &ok);

	if (ok)
	{
		uint8_t newWidth = penWidth;
		m_drawingArea->setPenWidth(newWidth);
	}
}


