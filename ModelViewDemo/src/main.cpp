#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // 使用资源时候需要声明
    // Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);

    // TODO: 不知道干嘛
    app.setOrganizationName("QtProject");
    app.setApplicationName("ModelViewDemo Example");

    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
