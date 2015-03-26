#include "singleordertab.h"
#include "singleorderformdialog.h"
#include "singleordertablemodel.h"
#include "singleorderform.h"

#include <QtWidgets>

SingleOrderTab::SingleOrderTab(QWidget *parent)
    : QTabWidget(parent)
{
    tabDMA = new SingleOrderTab_DMA(this);
    tabAlgo = new SingleOrderTab_Algo(this);

    addTab(tabDMA, tr("DMA"));
    addTab(tabAlgo, tr("Algo"));
}

SingleOrderTab_DMA::SingleOrderTab_DMA(QWidget *parent)
    : QWidget(parent)
{
    orderForm = new SingleOrderForm(this);

    tableModel = new SingleOrderTableModel(this);

    tableView = new QTableView;
    btnAdd = new QPushButton(tr("&New"));
    btnEdit = new QPushButton(tr("&Edit"));
    btnCancel = new QPushButton(tr("&Cancel"));
    btnOrder = new QPushButton(tr("&Order"));

    // Set Connect
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(addOrder()));
    connect(btnEdit, SIGNAL(clicked()), this, SLOT(editOrder()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(cancelOrder()));
    connect(btnOrder, SIGNAL(clicked()), this, SLOT(sendOrder()));

    createLayout();
}

void SingleOrderTab_DMA::createLayout()
{
    QGridLayout *btnLayout = new QGridLayout;
    btnLayout->setColumnStretch(0, 1);
    btnLayout->addWidget(btnAdd, 0, 1);
    btnLayout->addWidget(btnEdit, 0, 2);
    btnLayout->addWidget(btnCancel, 0, 3);
    btnLayout->addWidget(btnOrder, 0, 4);

    btnAdd->setHidden(true);
    btnEdit->setHidden(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel(tr("Single Order - DMA")));
    layout->addWidget(orderForm, 2);
    layout->addLayout(btnLayout);
    layout->addWidget(tableView, 1);

    setLayout(layout);
}

void SingleOrderTab_DMA::addOrder()
{
    qDebug() << "addOrder";

    SingleOrderFormDialog dialog;
    dialog.setWindowTitle(tr("Add Order"));

    if (dialog.exec()) {
        qDebug() << "addOrder OK";
    }
}

void SingleOrderTab_DMA::editOrder()
{
}

void SingleOrderTab_DMA::cancelOrder()
{
}

void SingleOrderTab_DMA::sendOrder()
{
}

/// SingleOrderTab_Algo impl

SingleOrderTab_Algo::SingleOrderTab_Algo(QWidget *parent)
    : QWidget(parent)
{
    createLayout();
}

void SingleOrderTab_Algo::createLayout()
{
}
