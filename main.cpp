#include "doom.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Doom w;
    w.show();

    return a.exec();
}
