#include "DrawingInterface.h"
#include <QColorDialog>
#include <QInputDialog>
#include <QFileDialog>
#include <qmessagebox.h>
#include "../MessageDLL/MessageDLL.h"
#include "Chat.h"

DrawingInterface::DrawingInterface(QWidget *parent)
	: QMainWindow(parent)
{ 
	ui.setupUi(this);
	m_drawingArea = new DrawingClass;
	setWindowTitle("Gartic");
	m_drawingBox= QRect(50, 50, 600, 400);
	

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
		QPoint startPoint = m_drawingArea->getStartPoint();
		if (m_drawingBox.contains(startPoint) && m_drawingBox.contains(event->pos())) {

			uint8_t penWidth = m_drawingArea->getPenWidth();
			QLine line(startPoint, event->pos());
			
			if (ui.red->isChecked())
				m_drawingArea->addLine(line, Qt::red, penWidth);
			else if(ui.blue->isChecked())
				m_drawingArea->addLine(line, Qt::blue, penWidth);
			else if(ui.cyan->isChecked())
				m_drawingArea->addLine(line, Qt::cyan, penWidth);
			else if(ui.green->isChecked())
				m_drawingArea->addLine(line, Qt::green, penWidth);
			else if(ui.magenta->isChecked())
				m_drawingArea->addLine(line, Qt::magenta, penWidth);
			else if(ui.yellow->isChecked())
				m_drawingArea->addLine(line, Qt::yellow, penWidth);
			else if (ui.black->isChecked())
				m_drawingArea->addLine(line, Qt::black, penWidth);
			else if (ui.brown->isChecked()) {
				QColor brown(139, 69, 19);
				m_drawingArea->addLine(line,brown, penWidth);
			}
			else if (ui.gray->isChecked())
				m_drawingArea->addLine(line, Qt::gray, penWidth);
			else if (ui.darkBlue->isChecked())
				m_drawingArea->addLine(line, Qt::darkBlue, penWidth);
			else if (ui.darkGreen->isChecked())
				m_drawingArea->addLine(line, Qt::darkGreen, penWidth);
			else if (ui.eraser->isChecked())
				m_drawingArea->addLine(line, Qt::white, penWidth);
			else if(ui.orange->isChecked())
				m_drawingArea->addLine(line, QColor(255, 165, 0), penWidth);
			m_drawingArea->setStartPoint(event->pos());
			update();
		}
	}
}

void DrawingInterface::mouseReleaseEvent(QMouseEvent* event)
{
	m_drawingArea->setDrawing(false);
}

void DrawingInterface::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	p.fillRect(m_drawingBox, Qt::white);
	p.drawRect(m_drawingBox);
	for (const auto& l: m_drawingArea->getLines())
	{
		QLine line  = std::get<0>(l);
		uint8_t width = std::get<2>(l);
		QColor color = std::get<1>(l);
		if (m_drawingBox.contains(std::get<0>(l).p1()) && m_drawingBox.contains(std::get<0>(l).p2())) {
			if (color == Qt::red)
			{
				draw(Qt::red, p, width, line);
			}
			else if (color == Qt::blue)
			{
				draw(Qt::blue, p, width, line);
			}
			else if (color == Qt::cyan)
			{
				draw(Qt::cyan, p, width, line);
			}
			else if (color == Qt::green)
			{
				draw(Qt::green, p, width, line);

			}
			else if (color == Qt::magenta)
			{
				draw(Qt::magenta, p, width, line);

			}
			else if (color == Qt::yellow)
			{
				draw(Qt::yellow, p, width, line);

			}
			else if (color == QColor(139, 69, 19)) //Color :Brown
			{
				draw(QColor(139, 69, 19), p, width, line);

			}
			else if (color == Qt::black)
			{
				draw(Qt::black, p, width, line);

			}
			else if (color == Qt::gray)
			{
				draw(Qt::gray, p, width, line);

			}
			else if (color == Qt::darkGreen)
			{
				draw(Qt::darkGreen, p, width, line);

			}
			else if (color == Qt::darkBlue)
			{
				draw(Qt::darkBlue, p, width, line);

			}
			else if (color == Qt::white)
			{
				draw(Qt::white, p, width, line);
			}
			else if (color == QColor(255, 165, 0)) //Color: Orange
			{
				draw(QColor(255,165,0), p, width, line);
			}
		}
	}
	update();
}

void DrawingInterface::draw(const QColor& color,QPainter &p,const uint8_t &width,const QLine &line) const
{
	QPen pen(color);
	pen.setWidth(width);
	p.setPen(pen);

	p.drawLine(line);
}


void DrawingInterface::on_widthSlider_valueChanged()
{
	uint8_t penWitdh = ui.widthSlider->value();
	m_drawingArea->setPenWidth(penWitdh);
}

