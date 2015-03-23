#include "mainwindow.h"
#include "delegate.h"

#include <QtWidgets>

MainWindow::MainWindow() {
    createMainLayout();
}

void MainWindow::createMainLayout() {

    QStandardItemModel *model = new QStandardItemModel(4, 2);
    QTableView *tableView = new QTableView;
    tableView->setModel(model);

    SpinBoxDelegate *delegate = new SpinBoxDelegate();
    tableView->setItemDelegate(delegate);

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 2; ++column) {
            QModelIndex index = model->index(row, column, QModelIndex());
            model->setData(index, QVariant((row + 1) * (column + 1)));
        }
    }

    // 主控件，放入MainWindow的中央控件中
    setCentralWidget(tableView);
}
