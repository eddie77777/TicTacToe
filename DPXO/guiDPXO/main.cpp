#include "guiDPXO.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString st = "Tibi";
    guiDPXO w;
    w.show();
    return a.exec();
}
