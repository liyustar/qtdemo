#ifndef SINGLEORDERTABLEMODEL_H_
#define SINGLEORDERTABLEMODEL_H_

#include <QAbstractTableModel>
#include <QList>
#include <QPair>

class SingleOrderTableModel : public QAbstractTableModel {
    Q_OBJECT

    public:
        SingleOrderTableModel(QObject *parent = 0);
        SingleOrderTableModel(QList<QPair<QString, QString> > listofPairs, QObject * parent = 0);

        int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
        Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
        bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
        bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
        QList<QPair<QString, QString> > getList();

    private:
        QList<QPair<QString, QString> > listOfPairs;
};

#endif // SINGLEORDERTABLEMODEL_H_
