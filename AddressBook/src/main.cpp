#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);

    // TODO: 不知道干嘛
    app.setOrganizationName("QtProject");
    app.setApplicationName("AddressBook Example");

    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
