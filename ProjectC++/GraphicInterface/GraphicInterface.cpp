#include "GraphicInterface.h"
#include "LoginInterface.h"

GraphicInterface::GraphicInterface(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
void GraphicInterface::on_pushButton_2_clicked()
{
    LoginInterface* login=new LoginInterface(this);
    login->show();
}
GraphicInterface::~GraphicInterface()
{}
