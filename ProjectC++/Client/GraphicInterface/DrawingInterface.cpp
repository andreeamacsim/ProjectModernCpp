#include "DrawingInterface.h"
#include <QColorDialog>
#include <QInputDialog>
#include <QFileDialog>
#include <qmessagebox.h>
#include "../MessageDLL/MessageDLL.h"
#include "Chat.h"
#include <cpr/cpr.h>
#include <crow.h>

DrawingInterface::DrawingInterface(QString username,QWidget *parent)
	: QMainWindow(parent)
{ 
	m_username = username;
	ui.setupUi(this);
	m_drawingArea = new DrawingClass;
	setWindowTitle("Gartic");
	m_drawingBox= QRect(50, 50, 600, 400);
	connect(ui.drawing, &QPushButton::clicked, this, &DrawingInterface::setDrawer);
	m_drawer = false;

}

DrawingInterface::~DrawingInterface()
{

}

void DrawingInterface::setDrawingLines(bool drawer)
{
	if (drawer == false&& m_timer%50==0)
	{
		cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/drawingTable" });
		auto lines = crow::json::load(response.text);
		if (m_drawingArea->getLines().size() != lines.size()) {
			for (const auto& l : lines)
			{
				float startPointX = l["startPointX"].d();
				float startPointY = l["startPointY"].d();
				float finalPointX = l["finalPointX"].d();
				float finalPointY = l["finalPointY"].d();
				std::string color = l["color"].s();
				int width = l["width"].i();
				std::pair<float, float> sPoint = std::make_pair(startPointX, startPointY);
				std::pair<float, float>fPoint = std::make_pair(finalPointX, finalPointY);
				auto line = std::make_pair(sPoint, fPoint);
				m_drawingArea->addLine(line, color, width);
			}
		}
	}
}


void DrawingInterface::setDrawer()
{
	m_drawer = true;
}

void DrawingInterface::mousePressEvent(QMouseEvent* event)
{
	if (m_drawer == true) {
		if (event->button() == Qt::LeftButton)
		{
			m_drawingArea->setDrawing(true);
			m_drawingArea->getStartPoint() = event->pos();

		}
	}
}

void DrawingInterface::mouseMoveEvent(QMouseEvent* event)
{
	if (m_drawingArea->isDrawing())
	{
		QPoint startPoint = m_drawingArea->getStartPoint();
		if (m_drawingBox.contains(startPoint) && m_drawingBox.contains(event->pos())) {

			int penWidth = m_drawingArea->getPenWidth();
			std::pair<float,float>lPoint = std::make_pair(startPoint.x(),startPoint.y());
			std::pair<float,float>rPoint = std::make_pair(event->pos().x(), event->pos().y());
			std::pair<std::pair<float, float>, std::pair<float, float>> line = std::make_pair(lPoint, rPoint);
			std::string color;
			if (ui.red->isChecked())
				color = "red";

			else if (ui.blue->isChecked())
				color = "blue";

			else if (ui.cyan->isChecked())
				color = "cyan";

			else if (ui.green->isChecked())
				color = "green";

			else if (ui.magenta->isChecked())
				color = "magenta";

			else if (ui.yellow->isChecked())
				color = "yellow";

			else if (ui.black->isChecked())
				color = "black";

			else if (ui.brown->isChecked()) {
				QColor brown(139, 69, 19);
				color = "brown";

			}
			else if (ui.gray->isChecked())
				color = "gray";

			else if (ui.darkBlue->isChecked())
				color = "darkBlue";

			else if (ui.darkGreen->isChecked())
				color = "darkGreen";

			else if (ui.eraser->isChecked())
				color = "white";

			else if (ui.orange->isChecked())
				color = "orange";
			update();
			cpr::Parameters parameters = cpr::Parameters{
				{"startPointX", std::to_string(lPoint.first)},
				{"startPointY", std::to_string(lPoint.second)},
				{"finalPointX", std::to_string(rPoint.first)},
				{"finalPointY", std::to_string(rPoint.second)},
				{"color", color},
				{"width", std::to_string(penWidth)} };
			auto response = cpr::Get(cpr::Url{ "http://localhost:18080/addline" }, parameters);
			m_drawingArea->addLine(line, color, penWidth);
			m_drawingArea->setStartPoint(event->pos());
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
	setDrawingLines(m_drawer);
	auto lines = m_drawingArea->getLines();
	if (!lines.empty()) {

		for (const auto& l : lines)
		{
			
			auto line = std::get<0>(l);
			auto color = std::get<1>(l);
			auto width = std::get<2>(l);

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
				draw(QColor(255, 165, 0), p, width, line);
			}
		}
		update();
	}
	m_timer++;
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

