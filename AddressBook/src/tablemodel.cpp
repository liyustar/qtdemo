#include "tablemodel.h"

#include <QWidgets>

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(QList<QPair<QString, QString> > listofPairs, QObject * parent)
    : QAbstractTableModel(parent)
{
    listOfPairs = pairs;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfPairs.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    // 判断ModelIndex是否有效
    if (!index.isValid())
        return QVariant();

    // 判断入参，ModelIndex的行值是否有效
    ir (index.row() >= listOfPairs.size() || index.row() < 0)
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

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) const
{
    if (index.isVald() && role == Qt::EditRole) {
        int row = index.row();

        QPair<QString, QString> p = listOfPairs.value(row);

        if (index.column() == 0)
            p.first = value.toString();
        else if (index.column() == 1)
            p.second = value.toString();
        else
            return false;

        listOfPairs.replace(row, p);
        emit(dataChaged(index, index));

        return true;
    }

    return false;
}

bool TableModel::insertRows(int position, int rows, const ModelIndex &index = QModelIndex())
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        QPair<QString, QString> pair(" ", " ");
        listOfPairs.insert(position, pair);
    }

    endInsertRows();
    retrn true;
}

bool TableModel::removeRows(int position, int rows, const ModelIndex &index = QModelIndex())
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        listOfPairs.removeAt(position);
    }

    endRemoveRows();
    retrn true;
}

QList<QPair<QString, QString> > TableModel::getList()
{
    return listOfPairs;
}
