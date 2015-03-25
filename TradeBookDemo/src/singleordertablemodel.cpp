#include "singleordertablemodel.h"

#include <QtWidgets>

SingleOrderTableModel::SingleOrderTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

SingleOrderTableModel::SingleOrderTableModel(QList<QPair<QString, QString> > pairs, QObject * parent)
    : QAbstractTableModel(parent)
{
    listOfPairs = pairs;
}

int SingleOrderTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfPairs.size();
}

int SingleOrderTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant SingleOrderTableModel::data(const QModelIndex &index, int role) const
{
    // 判断ModelIndex是否有效
    if (!index.isValid())
        return QVariant();

    // 判断入参，ModelIndex的行值是否有效
    if (index.row() >= listOfPairs.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        QPair<QString, QString> pair = listOfPairs.at(index.row());

        if (index.column() == 0)
            return pair.first;
        else if (index.column() == 1)
            return pair.second;
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
                return tr("Name");

            case 1:
                return tr("Address");

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
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        QPair<QString, QString> p = listOfPairs.value(row);

        if (index.column() == 0)
            p.first = value.toString();
        else if (index.column() == 1)
            p.second = value.toString();
        else
            return false;

        listOfPairs.replace(row, p);
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
        QPair<QString, QString> pair(" ", " ");
        listOfPairs.insert(position, pair);
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
        listOfPairs.removeAt(position);
    }

    endRemoveRows();
    return true;
}

QList<QPair<QString, QString> > SingleOrderTableModel::getList()
{
    return listOfPairs;
}
