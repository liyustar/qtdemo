#ifndef SINGLEORDERTAB_H_
#define SINGLEORDERTAB_H_

#include <QWidget>

class QTableView;
class QPushButton;

class SingleOrderForm;
class SingleOrderTableModel;

class SingleOrderTab : public QWidget
{
    Q_OBJECT

    public:
        SingleOrderTab(QWidget *parent = 0);

        void createLayout();

    private slots:
        void addOrder();
        void editOrder();
        void sendOrder();

    private:
        SingleOrderForm *orderForm;

        SingleOrderTableModel *tableModel;
        QTableView *tableView;
        QPushButton *btnAdd;
        QPushButton *btnEdit;
        QPushButton *btnOrder;
};

#endif // SINGLEORDERTAB_H_
