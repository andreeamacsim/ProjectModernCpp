#include "GraphicInterface.h"
#include <QtWidgets/QApplication>
#include "LoginInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicInterface w;
     w.show();

    return a.exec();
}
