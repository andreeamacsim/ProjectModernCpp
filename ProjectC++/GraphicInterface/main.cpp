#include "GraphicInterface.h"
#include <QtWidgets/QApplication>
#include "LoginInterface.h"
#include "DrawingInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicInterface w;
    w.show();
    DrawingInterface d;
    //d.show();
    return a.exec();
}
