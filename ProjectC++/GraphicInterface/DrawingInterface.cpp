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

}

DrawingInterface::~DrawingInterface()
{

}


void DrawingInterface::on_red_stateChanged(int arg)
{

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
		QLine line(m_drawingArea->getStartPoint(), event->pos());
		if (ui.red->isChecked())
			m_drawingArea->addLine(line, Qt::red);
		else
			m_drawingArea->addLine(line, Qt::black);
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
		if (p1.second == Qt::red)
		{
			p.setPen(Qt::red);
			p.drawLine(p1.first);
			update();
		}
		else
		{
			p.setPen(Qt::black);
			p.drawLine(p1.first);
			update();
		}

	}
}



