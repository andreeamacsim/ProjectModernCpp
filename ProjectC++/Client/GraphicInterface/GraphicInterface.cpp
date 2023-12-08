#include "GraphicInterface.h"
#include "LoginInterface.h"

GraphicInterface::GraphicInterface(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked, this, &GraphicInterface::on_pushButton_clicked);
}

void GraphicInterface::on_pushButton_2_clicked()
{
    LoginInterface* login=new LoginInterface(this);

    login->show();
}
void GraphicInterface::on_pushButton_clicked()
{
    qApp->quit();
}
GraphicInterface::~GraphicInterface()
{}
