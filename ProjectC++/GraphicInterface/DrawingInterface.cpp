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
		else if(ui.blue->isChecked())
			m_drawingArea->addLine(line, Qt::blue);
		else if(ui.cyan->isChecked())
			m_drawingArea->addLine(line, Qt::cyan);
		else if(ui.green->isChecked())
			m_drawingArea->addLine(line, Qt::green);
		else if(ui.magenta->isChecked())
			m_drawingArea->addLine(line, Qt::magenta);
		else if(ui.yellow->isChecked())
			m_drawingArea->addLine(line, Qt::yellow);
		else if(ui.black->isChecked())
			m_drawingArea->addLine(line, Qt::black);
		else if (ui.brown->isChecked()) {
			QColor brown(139, 69, 19);
			m_drawingArea->addLine(line,brown);
		}
		else if (ui.gray->isChecked())
			m_drawingArea->addLine(line, Qt::gray);
		else if (ui.darkBlue->isChecked())
			m_drawingArea->addLine(line, Qt::darkBlue);
		else if (ui.darkGreen->isChecked())
			m_drawingArea->addLine(line, Qt::darkGreen);
		else if (ui.eraser->isChecked())
			m_drawingArea->addLine(line, Qt::white);
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
		else if (p1.second == Qt::blue)
		{
			p.setPen(Qt::blue);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::cyan)
		{
			p.setPen(Qt::cyan);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::green)
		{
			p.setPen(Qt::green);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::magenta)
		{
			p.setPen(Qt::magenta);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::yellow)
		{
			p.setPen(Qt::yellow);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == QColor(139, 69, 19)) //Color :Brown
		{
			p.setPen(QColor(139, 69, 19));
			p.drawLine(p1.first);
			update();
		}
		else if(p1.second ==Qt::black)
		{
			p.setPen(Qt::black);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::gray)
		{
			p.setPen(Qt::gray);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::darkGreen)
		{
			p.setPen(Qt::darkGreen);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::darkBlue)
		{
			p.setPen(Qt::darkBlue);
			p.drawLine(p1.first);
			update();
		}
		else if (p1.second == Qt::white)
		{
			p.setPen(Qt::white);
			p.drawLine(p1.first);
			update();
		}

	}
}



