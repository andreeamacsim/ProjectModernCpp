#pragma once

#include <QMainWindow>
#include "ui_DrawingInterface.h"
#include "DrawingClass.h"
#include <QPushButton>

class DrawingInterface : public QMainWindow
{
	Q_OBJECT

public:
	DrawingInterface(QWidget *parent = nullptr);
	~DrawingInterface();
private slots:
	void changePenColor();
	void changePenWidth();
private:
	QPushButton* changeColorButton;
	QPushButton* changeWidthButton;
	DrawingClass* m_drawingArea;
	//QMenu* fileMenu;
	//QAction* m_openAct;
	//QAction* m_penColorAct;
	//QAction* m_penWidthAct;
	//QAction* m_clearDrawingArea;
	Ui::DrawingInterfaceClass ui;
};
