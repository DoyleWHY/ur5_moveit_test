#include <QApplication>
#include <iostream>
#include "QDebug"
#include "../gui/test_gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test_gui w(argc, argv);
    w.show();
    int t = 10;
    std::cout << t << ": Yes, it is!" << std::endl;
    qDebug() << "Hello, sorry for keeping you waiting!";

    return a.exec();
}
