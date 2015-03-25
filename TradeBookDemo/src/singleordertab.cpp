#include "singleordertab.h"

#include <QtWidgets>

SingleOrderTab::SingleOrderTab(QWidget *parent)
    : QWidget(parent)
{
    tableModel = new SingleOrderTableModel(this);

    tableView = new QTableView;
    btnAdd = new QPushButton(tr("New"));
    btnEdit = new QPushButton(tr("Edit"));
    btnOrder = new QPushButton(tr("Order"));

    createLayout();
}

void SingleOrderTab::createLayout()
{
    QGridLayout *btnLayout = new QGridLayout;
    btnLayout->setColumnStretch(0, 1);
    btnLayout->addWidget(btnAdd, 0, 1);
    btnLayout->addWidget(btnEdit, 0, 2);
    btnLayout->addWidget(btnOrder, 0, 3);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableView, 1);
    layout->addLayout(btnLayout);

    setLayout(layout);
}
