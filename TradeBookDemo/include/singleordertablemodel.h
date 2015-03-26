#ifndef SINGLEORDERTABLEMODEL_H_
#define SINGLEORDERTABLEMODEL_H_

#include <QAbstractTableModel>
#include <QList>

#include "type.h"

class SingleOrderTableModel : public QAbstractTableModel {
    Q_OBJECT

    public:
        SingleOrderTableModel(QObject *parent = 0);
        SingleOrderTableModel(QList<Order_t> listofOrder, QObject * parent = 0);

        int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
        Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
        bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
        bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
        QList<Order_t> getList();

        // add Order to Model, return true when success
        bool addOrder(const Order_t &order);

    private:
        QList<Order_t> listOfOrder;
};

#endif // SINGLEORDERTABLEMODEL_H_
