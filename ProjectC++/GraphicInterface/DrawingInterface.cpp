#include "DrawingInterface.h"
#include <QColorDialog>
#include <QInputDialog>
#include <QFileDialog>

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
	uint8_t penWidth = QInputDialog::getInt(this, "Change pen width", "Width:", m_drawingArea->getPenWidth(), 1, 50, 1, &ok);

	if (ok)
	{
		uint8_t newWidth = penWidth;
		m_drawingArea->setPenWidth(newWidth);
	}
}

void DrawingInterface::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_drawingArea->setDrawing(true);
		m_drawingArea->getStartPoint() = event->pos();

	}
}

void DrawingInterface::mouseMoveEvent(QMouseEvent* event)
{
	if (m_drawingArea->isDrawing())
	{
		m_drawingArea->addLine({ m_drawingArea->getStartPoint(),event->pos() });
		m_drawingArea->setStartPoint(event->pos());
		update();
	}
}

void DrawingInterface::mouseReleaseEvent(QMouseEvent* event)
{
	m_drawingArea->setDrawing(false);
}

void DrawingInterface::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	for (auto p1: m_drawingArea->getLines())
	{
		p.drawLine(p1);
		update();

	}
}



