#include "mainwindow.h"
#include <QPixmap>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("Password Generator by Amogh Raina");

    QPixmap pixmap(":/logo/img/32680994b925140b048e2ee11f03aaf0.png");
    w.setWindowIcon(QIcon(pixmap));
     w.setFixedSize(w.size());
    return a.exec();




}
