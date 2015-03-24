#ifndef ADDRESSWIDGET_H_
#define ADDRESSWIDGET_H_

// #include "newaddresstab.h"
#include "tablemodel.h"

#include <QItemSelection>
#include <QTabWidget>

class QSortFilterProxyModel;
class QItemSelectionModel;

class AddressWidget : public QTabWidget
{
    Q_OBJECT

    public:
        AddressWidget(QWidget *parent = 0);
        void readFromFile(const QString &fileName);
        void writeToFile(const QString &fileName);

    public slots:
        void addEntry();
        void addEntry(QString name, QString address);
        void editEntry();
        void removeEntry();

    signals:
        void selectionChanged(const QItemSelection &selected);

    private:
        void setupTabs();

        TableModel *table;
        QTabWidget *tab;
        // NewAddressTab *newAddressTab;
        QSortFilterProxyModel *proxyModel;
};

#endif // ADDRESSWIDGET_H_
