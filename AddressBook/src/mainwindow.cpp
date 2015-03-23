#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow() {
    createMainLayout();
}

void MainWindow::createMainLayout() {
    // 控件元素初始化
    tableView = new QTableView();
    btnAdd = new QPushButton("Add");
    btnRemove = new QPushButton("Remove");
    edtSearch = new QLineEdit("");

    // 构造子布局，要嵌套到主布局中
    QWidget *gridWidget = new QWidget;
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setColumnStretch(0, 1);
    gridLayout->addWidget(btnRemove, 0, 1);
    gridLayout->addWidget(btnAdd, 0, 2);
    gridWidget->setLayout(gridLayout);

    // 构造Box主布局，将其他控件元素放入布局中
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableView);
    layout->addWidget(gridWidget);
    layout->addWidget(edtSearch);

    // 主控件，放入MainWindow的中央控件中
    mainWidget = new QWidget;
    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}
