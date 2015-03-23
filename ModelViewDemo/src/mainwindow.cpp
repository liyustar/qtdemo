#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow() {
    createMainLayout();
}

void MainWindow::createMainLayout() {
    // 主控件，放入MainWindow的中央控件中
    mainWidget = new QWidget;
    // mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}
