#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("INPROTEC - PLC SIEMENS");
    w.show();
    return a.exec();
}
