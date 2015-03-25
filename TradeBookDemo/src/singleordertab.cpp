#include "singleordertab.h"
#include "singleorderformdialog.h"
#include "singleordertablemodel.h"
#include "singleorderform.h"

#include <QtWidgets>

SingleOrderTab::SingleOrderTab(QWidget *parent)
    : QWidget(parent)
{
    orderForm = new SingleOrderForm(this);

    tableModel = new SingleOrderTableModel(this);

    tableView = new QTableView;
    btnAdd = new QPushButton(tr("New"));
    btnEdit = new QPushButton(tr("Edit"));
    btnOrder = new QPushButton(tr("Order"));

    // Set Connect
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(addOrder()));
    connect(btnEdit, SIGNAL(clicked()), this, SLOT(editOrder()));
    connect(btnOrder, SIGNAL(clicked()), this, SLOT(sendOrder()));

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
    layout->addWidget(orderForm, 2);
    layout->addWidget(tableView, 1);
    layout->addLayout(btnLayout);

    setLayout(layout);
}

void SingleOrderTab::addOrder()
{
    qDebug() << "addOrder";

    SingleOrderFormDialog dialog;
    dialog.setWindowTitle(tr("Add Order"));

    if (dialog.exec()) {
        qDebug() << "addOrder OK";
    }
}

void SingleOrderTab::editOrder()
{
}

void SingleOrderTab::sendOrder()
{
}
