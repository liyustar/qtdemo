#include "delegate.h"

#include <QtWidgets>

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) {
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
        const QStyleOptionViewItem &option, /* option */
        const QModelIndex &index) const
{
    qDebug() << "createEditor" << index;
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0);
    editor->setMaximum(100);

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    qDebug() << "setEditorData" << index;
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor,
        QAbstractItemModel *model,
        const QModelIndex &index) const
{
    qDebug() << "setModelData" << index;
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    qDebug() << "updateEditor: " << option.rect;
    editor->setGeometry(option.rect);
}
