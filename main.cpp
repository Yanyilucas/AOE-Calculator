#include <QApplication>
#include"mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow MW;
    MW.show();
    return QApplication::exec();
}
