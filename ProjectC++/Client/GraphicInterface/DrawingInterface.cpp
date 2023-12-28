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
			std::pair<float,float>lPoint = std::make_pair(startPoint.x(),startPoint.y());
			std::pair<float,float>rPoint = std::make_pair(event->pos().x(), event->pos().y());
			std::pair<std::pair<float, float>, std::pair<float, float>> line = std::make_pair(lPoint, rPoint);
			
			if (ui.red->isChecked())
				m_drawingArea->addLine(line,"red", penWidth);
			else if(ui.blue->isChecked())
				m_drawingArea->addLine(line, "blue", penWidth);
			else if(ui.cyan->isChecked())
				m_drawingArea->addLine(line, "cyan", penWidth);
			else if(ui.green->isChecked())
				m_drawingArea->addLine(line, "green", penWidth);
			else if(ui.magenta->isChecked())
				m_drawingArea->addLine(line, "magenta", penWidth);
			else if(ui.yellow->isChecked())
				m_drawingArea->addLine(line, "yellow", penWidth);
			else if (ui.black->isChecked())
				m_drawingArea->addLine(line, "black", penWidth);
			else if (ui.brown->isChecked()) {
				QColor brown(139, 69, 19);
				m_drawingArea->addLine(line,"brown", penWidth);
			}
			else if (ui.gray->isChecked())
				m_drawingArea->addLine(line, "gray", penWidth);
			else if (ui.darkBlue->isChecked())
				m_drawingArea->addLine(line, "darkBlue", penWidth);
			else if (ui.darkGreen->isChecked())
				m_drawingArea->addLine(line, "darkGreen", penWidth);
			else if (ui.eraser->isChecked())
				m_drawingArea->addLine(line, "white", penWidth);
			else if(ui.orange->isChecked())
				m_drawingArea->addLine(line,"orange", penWidth);
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
		std::pair line  = std::get<0>(l);
		uint8_t width = std::get<2>(l);
		std::string color = std::get<1>(l);
			if (color == "red")
			{
				draw(Qt::red, p, width, line);
			}
			else if (color == "blue")
			{
				draw(Qt::blue, p, width, line);
			}
			else if (color == "cyan")
			{
				draw(Qt::cyan, p, width, line);
			}
			else if (color == "green")
			{
				draw(Qt::green, p, width, line);

			}
			else if (color == "magenta")
			{
				draw(Qt::magenta, p, width, line);

			}
			else if (color == "yellow")
			{
				draw(Qt::yellow, p, width, line);

			}
			else if (color == "brown") //Color :Brown
			{
				draw(QColor(139, 69, 19), p, width, line);

			}
			else if (color == "black")
			{
				draw(Qt::black, p, width, line);

			}
			else if (color == "gray")
			{
				draw(Qt::gray, p, width, line);

			}
			else if (color == "darkGreen")
			{
				draw(Qt::darkGreen, p, width, line);

			}
			else if (color == "darkBlue")
			{
				draw(Qt::darkBlue, p, width, line);

			}
			else if (color == "white")
			{
				draw(Qt::white, p, width, line);
			}
			else if (color == "orange") //Color: Orange
			{
				draw(QColor(255,165,0), p, width, line);
			}
	}
	update();
}

void DrawingInterface::draw(const QColor& color,QPainter &p,const uint8_t &width, std::pair<std::pair<float, float>, std::pair<float, float>> line) const
{
	QPen pen(color);
	pen.setWidth(width);
	p.setPen(pen);

	p.drawLine(line.first.first,line.first.second,line.second.first,line.second.second);
}


void DrawingInterface::on_widthSlider_valueChanged()
{
	uint8_t penWitdh = ui.widthSlider->value();
	m_drawingArea->setPenWidth(penWitdh);
}

