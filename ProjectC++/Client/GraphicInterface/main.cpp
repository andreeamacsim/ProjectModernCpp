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
    DrawingInterface d;
    //d.show();
   
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/players" });
    auto players = crow::json::load(response.text);
    for (const auto& player : players)
    {
        std::cout << player["id"] << ' ' << player["username"] <<" "<<player["password"] << " " << player["email"] << '\n';
    }
    return a.exec();
}
