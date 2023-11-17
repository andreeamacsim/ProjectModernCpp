#pragma once

#include <QMainWindow>
#include "ui_DrawingInterface.h"
class DrawingClass;

class DrawingInterface : public QMainWindow
{
	Q_OBJECT

public:
	DrawingInterface(QWidget *parent = nullptr);
	~DrawingInterface();
private slots:
	void penColor();
	void penWidth();
private:
	void createActions();
	void createMenus();
	DrawingClass* m_drawingArea;
	QMenu* fileMenu;
	QAction* m_openAct;
	QAction* m_penColorAct;
	QAction* m_penWidthAct;
	QAction* m_clearDrawingArea;
	Ui::DrawingInterfaceClass ui;
};
