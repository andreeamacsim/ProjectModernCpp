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
	DrawingInterface(QString username,QWidget *parent = nullptr);
	~DrawingInterface();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
	void draw(const QColor& color, QPainter& p, const uint8_t& width, std::pair<std::pair<float, float>, std::pair<float, float>> line) const;
	
private slots:
	void on_widthSlider_valueChanged();
private:
	QString m_username;
	QRect m_drawingBox;
	DrawingClass* m_drawingArea;
	//QMenu* fileMenu;
	//QAction* m_openAct;
	//QAction* m_penColorAct;
	//QAction* m_penWidthAct;
	//QAction* m_clearDrawingArea;
	Ui::DrawingInterfaceClass ui;
	Chat* m_chatInstance;
};
