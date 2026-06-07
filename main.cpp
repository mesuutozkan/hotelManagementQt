#include "mainwindow.h"

#include <QApplication>

#include "hotel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    auto result = QCoreApplication::exec();

    //Delete Hotel Singleton Object

    delete Hotel::getInstance();

    return result;
}
