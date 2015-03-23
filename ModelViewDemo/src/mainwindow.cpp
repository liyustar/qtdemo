#include "mainwindow.h"

#include <QtWidgets>
#include <QDir>

namespace {

void test() {
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QModelIndex parentIndex = model->index(QDir::currentPath());
    // int numRows = model->rowCount(parentIndex);
    int numRows = model->rowCount();
    qDebug() << "numRows: " << numRows;

    for (int row = 0; row < numRows; ++row) {
        QModelIndex index = model->index(row, 0, parentIndex);
        QString text = model->data(index, Qt::DisplayRole).toString();
        qDebug() << "   [" << row << "]: " << text;
    }
}

}

MainWindow::MainWindow() {
    // createMainLayout();
    // createTreeListFileView();
    // test();
    createExampleModel();
}

void MainWindow::createMainLayout() {

    /* 添加自定义布局 */

    // 主控件，放入MainWindow的中央控件中
    mainWidget = new QWidget;
    // mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}

void MainWindow::createTreeListFileView() {

    /* 添加自定义布局 */
    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Two views onto the same file system model");

    // 主控件，放入MainWindow的中央控件中
    setCentralWidget(splitter);
}

void MainWindow::createExampleModel() {
    // Unindented for quoting purposes:
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel *model = new QStringListModel(numbers);
    QListView *view = new QListView;
    view->setModel(model);

    setCentralWidget(view);
}
