#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow() {

    createMainLayout();

}

void MainWindow::createMainLayout() {

    // 主控件，放入MainWindow的中央控件中
    mainWidget = new QWidget;

    // 控件元素初始化
    tableView = new QTableView();
    btnAdd = new QPushButton("Add");
    btnRemove = new QPushButton("Remove");
    edtSearch = new QLineEdit("");

    // 构造子布局，要嵌套到主布局中


    // 构造Box主布局，将其他控件元素放入布局中
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableView);
    layout->addWidget(btnAdd);
    layout->addWidget(btnRemove);
    layout->addWidget(edtSearch);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}
