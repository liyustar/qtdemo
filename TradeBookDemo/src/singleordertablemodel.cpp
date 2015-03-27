#include "singleordertablemodel.h"

#include <QtWidgets>

SingleOrderTableModel::SingleOrderTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

SingleOrderTableModel::SingleOrderTableModel(QList<Order_t> orders, QObject * parent)
    : QAbstractTableModel(parent)
{
    listOfOrder = orders;
}

int SingleOrderTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfOrder.size();
}

int SingleOrderTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant SingleOrderTableModel::data(const QModelIndex &index, int role) const
{
    // 判断ModelIndex是否有效
    if (!index.isValid())
        return QVariant();

    // 判断入参，ModelIndex的行值是否有效
    if (index.row() >= listOfOrder.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        Order_t order = listOfOrder.at(index.row());

        if (index.column() == 0)
            return order.symbol;
        else if (index.column() == 1) {
            if (Constant::ORDER_BUY == order.direct)
                return QString("Buy");
            else if (Constant::ORDER_SELL == order.direct)
                return QString("Sell");
            else
                return QString("[Unknow]");
        }
        else if (index.column() == 2)
            return QString().setNum(order.price, 'g', 16);
        else if (index.column() == 3)
            return order.quantity;
    }
    return QVariant();
}

QVariant SingleOrderTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Symbol");

            case 1:
                return tr("Direct");

            case 2:
                return tr("Price");

            case 3:
                return tr("Quantiry");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags SingleOrderTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool SingleOrderTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "setData";
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        Order_t p = listOfOrder.value(row);

        if (index.column() == 0)
            p.symbol = value.toString();
        else if (index.column() == 1)
            p.direct = static_cast<Constant::ORDER_DIRECT>(value.toInt());
        else if (index.column() == 2)
            p.price = value.toDouble();
        else if (index.column() == 3)
            p.quantity = value.toInt();
        else
            return false;

        listOfOrder.replace(row, p);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

bool SingleOrderTableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    qDebug() << "insertRows: " << rows;
    for (int row = 0; row < rows; ++row) {
        Order_t order;
        listOfOrder.insert(position, order);
    }

    endInsertRows();
    return true;
}

bool SingleOrderTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    qDebug() << "removeRows: " << rows;
    for (int row = 0; row < rows; ++row) {
        listOfOrder.removeAt(position);
    }

    endRemoveRows();
    return true;
}

QList<Order_t> SingleOrderTableModel::getList()
{
    return listOfOrder;
}

bool SingleOrderTableModel::addOrder(const Order_t& order)
{
    qDebug() << "addOrder";
    beginInsertRows(QModelIndex(), 0, 0);
    listOfOrder.insert(0, order);
    endInsertRows();

    QModelIndex indexa = index(0, 0, QModelIndex());
    QModelIndex indexb = index(0, 3, QModelIndex());
    emit(dataChanged(indexa, indexb));

    /*
    insertRows(0, 1, QModelIndex());

    QModelIndex idx = index(0, 0, QModelIndex());
    setData(idx, order.symbol, Qt::EditRole);
    idx = index(0, 1, QModelIndex());
    setData(idx, order.direct, Qt::EditRole);
    idx = index(0, 2, QModelIndex());
    setData(idx, order.price, Qt::EditRole);
    idx = index(0, 3, QModelIndex());
    setData(idx, order.quantity, Qt::EditRole);
    */

    return true;
}
