#pragma once

#include <QMainWindow>
#include "ui_DrawingInterface.h"
#include "DrawingClass.h"
#include <QPushButton>
#include <QPainter>
#include <QCheckBox>
#include "Chat.h"
class DrawingInterface : public QMainWindow
{
	Q_OBJECT

public:
	DrawingInterface(std::string username,QWidget *parent = nullptr);
	~DrawingInterface();
	void setDrawingLines();
	void setDrawer();
	void revealCharacters();
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
	void draw(const QColor& color, QPainter& p, const uint8_t& width, std::pair<std::pair<float, float>, std::pair<float, float>> line) const;
	
private slots:
	void on_widthSlider_valueChanged();
private:
	QTimer* m_timerforWord;
	QTimer* m_timerForDrawing;
	QTimer* m_timerForDrawer;
	bool m_drawer;
	std::string m_username;
	QRect m_drawingBox;
	DrawingClass* m_drawingArea;
	Ui::DrawingInterfaceClass ui;
	Chat* m_chatInstance;
};
