#include "DrawingClass.h"

DrawingClass::DrawingClass(QWidget *parent)
	: QWidget(parent)
{}

DrawingClass::~DrawingClass()
{}

void DrawingClass::setPenColor(const QColor & color)
{
}

void DrawingClass::setPenWidth(const uint8_t width)
{
}

QColor DrawingClass::getPenColor() const
{
	return QColor();
}

uint8_t DrawingClass::getPenWidth() const
{
	return 0;
}
void DrawingClass::clearDrawingArea() {

}
void DrawingClass::mousePressEvent(QMouseEvent* event)
{
}

void DrawingClass::mouseMoveEvent(QMouseEvent* event)
{
}

void DrawingClass::mouseReleaseEvent(QMouseEvent* event)
{
}

void DrawingClass::paintEvent(QPaintEvent* event)
{
}

void DrawingClass::drawLineTo(const QPointF& endPoint)
{
}
