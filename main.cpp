#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(400, 316);
    w.setWindowTitle("bracketsCorrector");
    w.show();

    return a.exec();
}
