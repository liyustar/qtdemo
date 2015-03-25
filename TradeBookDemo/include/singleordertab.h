#ifndef SINGLEORDERTAB_H_
#define SINGLEORDERTAB_H_

#include "singleordertablemodel.h"

#include <QWidget>

// class QTabWidget;
class QTableView;
class QPushButton;

class SingleOrderTab : public QWidget
{
    Q_OBJECT

    public:
        SingleOrderTab(QWidget *parent = 0);

        void createLayout();

    private:
        SingleOrderTableModel *tableModel;
        QTableView *tableView;
        QPushButton *btnAdd;
        QPushButton *btnEdit;
        QPushButton *btnOrder;
};

#endif // SINGLEORDERTAB_H_
