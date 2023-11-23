#pragma once

#include <QMainWindow>
#include "ui_DrawingInterface.h"
#include "DrawingClass.h"
#include <QPushButton>
#include <QPainter>
#include <QCheckBox>

class DrawingInterface : public QMainWindow
{
	Q_OBJECT

public:
	DrawingInterface(QWidget *parent = nullptr);
	~DrawingInterface();
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
private:

	DrawingClass* m_drawingArea;
	//QMenu* fileMenu;
	//QAction* m_openAct;
	//QAction* m_penColorAct;
	//QAction* m_penWidthAct;
	//QAction* m_clearDrawingArea;
	Ui::DrawingInterfaceClass ui;
};
