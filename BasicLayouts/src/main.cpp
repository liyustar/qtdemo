#include "basiclayouts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BasicLayouts w;
    w.show();

    return a.exec();
}
