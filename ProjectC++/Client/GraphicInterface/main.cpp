#include "GraphicInterface.h"
#include <QtWidgets/QApplication>
#include "LoginInterface.h"
#include "DrawingInterface.h"

#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicInterface w;
    w.show();
    return a.exec();
}
