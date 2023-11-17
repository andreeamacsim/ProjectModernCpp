#pragma once

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QColor>

class DrawingClass  : public QWidget
{
	Q_OBJECT

public:
	DrawingClass(QWidget *parent);
	~DrawingClass();
	void setPenColor(const QColor& color);
	void setPenWidth(const uint8_t width);

	QColor getPenColor() const;
	uint8_t getPenWidth() const;
public slots:
	void clearDrawingArea();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
private:
	void drawLineTo(const QPointF& endPoint);
	QColor m_penColor;
	uint8_t m_penWidth;
	bool drawing;
	QPointF startPoint;

};
