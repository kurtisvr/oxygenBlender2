#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>


//This is the main file that actually calls the GUI
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setFixedSize(800,480);
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();
    return a.exec();
}
