#ifndef DELEGATE_H_
#define DELEGATE_H_

#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    public:
        SpinBoxDelegate(QObject *parent = 0);

        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                const QModelIndex &index) const Q_DECL_OVERRIDE;

        void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
        void setModelData(QWidget *editor, QAbstractItemModel *model,
                const QModelIndex &index) const Q_DECL_OVERRIDE;

        void updateEditorGeometry(QWidget *editor,
                const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // DELEGATE_H_
