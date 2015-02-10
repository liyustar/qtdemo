#include "dynamiclayouts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DynamicLayouts w;
    w.show();

    return a.exec();
}
