#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow() {
    orderWidget = new OrderWidget;
    setCentralWidget(orderWidget);

    createMenus();
}

void MainWindow::createMenus() {
    // File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));

    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}
