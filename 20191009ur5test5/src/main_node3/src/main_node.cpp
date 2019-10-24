#include <QApplication>
#include <iostream>
#include "QDebug"
#include "../gui/form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w(argc, argv);
    w.show();
    int t = 10;
    std::cout << t << ": Gui is coming!" << std::endl;
    qDebug() << "Hello, sorry for keeping you waiting!";

    return a.exec();
}
