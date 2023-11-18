#pragma once

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <vector>

class DrawingClass  : public QWidget
{
	Q_OBJECT

public:
	DrawingClass(QWidget *parent=0);
	~DrawingClass();
	//bool openImage(const QString& filename);
	void setPenColor(const QColor& color);
	void setPenWidth(const uint8_t width);
	std::vector<QLine>& getLines();
	const QColor& getPenColor() const;
	const uint8_t& getPenWidth() const;
	void addLine(QLine line);
	bool isDrawing();
	void setDrawing(bool drawing);
	QPoint& getStartPoint();
	void setStartPoint(QPoint point);

//protected:
//	void mousePressEvent(QMouseEvent* event) override;
//	void mouseMoveEvent(QMouseEvent* event) override;
//	void mouseReleaseEvent(QMouseEvent* event) override;
//	void paintEvent(QPaintEvent* event) override;
private:
	QColor m_penColor;
	uint8_t m_penWidth;
	std::vector<QLine> m_drawingLines;
	bool m_drawing;
	QPoint m_startPoint;

};
