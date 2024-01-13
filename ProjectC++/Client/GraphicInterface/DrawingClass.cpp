#include "DrawingClass.h"

DrawingClass::DrawingClass(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	m_drawing = false;
	m_penWidth = 1;
	m_penColor = Qt::black;
	setMouseTracking(true);


}

DrawingClass::~DrawingClass()
{}


void DrawingClass::setPenColor(const QColor & color)
{
	this->m_penColor = color;
}

void DrawingClass::setPenWidth(const uint8_t width)
{
	this->m_penWidth = width;
}

std::vector<std::tuple<std::pair<std::pair<float,float>,std::pair<float,float>>, std::string, uint8_t>>& DrawingClass::getLines()
{
	return this->m_drawingLines;
}

const QColor& DrawingClass::getPenColor() const
{
	return this->m_penColor;
}

const uint8_t& DrawingClass::getPenWidth() const
{
	return this->m_penWidth;
}
void DrawingClass::addLine(std::pair<std::pair<float, float>, std::pair<float, float>>line, std::string color, uint8_t width)
{
	m_drawingLines.push_back({ line,color,width });
}
bool DrawingClass::isDrawing()
{
	return m_drawing;
}
void DrawingClass::setDrawing(bool drawing)
{
	this->m_drawing = drawing;
}
QPoint& DrawingClass::getStartPoint()
{
	return m_startPoint;
}

void DrawingClass::setStartPoint(QPoint point)
{
	this->m_startPoint = point;
}