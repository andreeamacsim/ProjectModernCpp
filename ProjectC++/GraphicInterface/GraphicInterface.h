#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GraphicInterface.h"
#include "LoginInterface.h"
#include "ui_LoginInterface.h"
class GraphicInterface : public QMainWindow
{
    Q_OBJECT

public:
    GraphicInterface(QWidget *parent = nullptr);
    ~GraphicInterface();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::GraphicInterfaceClass ui;
    QPushButton *pushButton_2;

   
};
