#include "addresswidget.h"

#include <QtWidgets>

#include <iostream>
#include <sstream>

AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent)
{
    table = new TableModel(this);

    // newAddressTab = new NewAddressTab(this);
    tab = new QTabWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *btn = new QPushButton(tr("Add"));
    layout->addWidget(btn);
    tab->setLayout(layout);
    connect(btn, SIGNAL(clicked()), this, SLOT(addEntry()));

    addTab(tab, "Address Book");

    setupTabs();
}

void AddressWidget::readFromFile(const QString &fileName)
{
}

void AddressWidget::writeToFile(const QString &fileName)
{
}

void AddressWidget::addEntry()
{
    static int n = 0;
    const char ALP[27] = "JKLRXUCGNHAODPQBMFISETVWYZ";
    qDebug() << "addEntry";

    std::ostringstream oss;
    oss << ALP[n % 26] << n;
    n++;

    addEntry(QString(oss.str().c_str()), QString((oss.str() + " Address").c_str()));
}

void AddressWidget::addEntry(QString name, QString address)
{
    QList<QPair<QString, QString> > list = table->getList();
    QPair<QString, QString> pair(name, address);

    if (!list.contains(pair)) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index, address, Qt::EditRole);
        // removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
                tr("The name \"%1\" already exists.").arg(name));
    }
}

void AddressWidget::editEntry()
{
}

void AddressWidget::removeEntry()
{
}

void AddressWidget::setupTabs()
{
    QStringList groups;
    groups << "ABC" << "DEF" << "GHI" << "JKL" << "MNO" << "PQR" << "STU" << "VW" << "XYZ";

    for (int i = 0; i < groups.size(); ++i) {
        QString str = groups.at(i);
        QString regExp = QString("^[%1].*").arg(str);

        // Set Proxy Model
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setFilterRegExp(QRegExp(regExp, Qt::CaseInsensitive));
        proxyModel->setFilterKeyColumn(0);

        QTableView *tableView = new QTableView;
        tableView->setModel(proxyModel);

        // set view prop
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->verticalHeader()->hide();
        tableView->horizontalHeader()->setStretchLastSection(true);

        tableView->setSortingEnabled(true);

        // connect(tableView->selectionModel(),
                // SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
                // this, SIGNAL(selectionChanged(QItemSelection)));

        addTab(tableView, str);
    }
}
