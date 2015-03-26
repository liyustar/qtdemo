#ifndef SINGLEORDERTAB_H_
#define SINGLEORDERTAB_H_

#include <QWidget>
#include <QTabWidget>

class QTableView;
class QPushButton;

class SingleOrderForm;
class SingleOrderTableModel;

class SingleOrderTab_DMA;
class SingleOrderTab_Algo;

/**
 * Single order tab layout manager
 */
class SingleOrderTab : public QTabWidget
{
    Q_OBJECT

    public:
        SingleOrderTab(QWidget *parent = 0);

    private:
        SingleOrderTab_DMA *tabDMA;
        SingleOrderTab_Algo *tabAlgo;
};

/**
 * Display single order tab ui, for DMA order
 */
class SingleOrderTab_DMA : public QWidget
{
    Q_OBJECT

    public:
        SingleOrderTab_DMA(QWidget *parent = 0);

    private slots:
        void addOrder();
        void editOrder();
        void cancelOrder();
        void sendOrder();

    private:
        void createLayout();

        SingleOrderForm *orderForm;

        SingleOrderTableModel *tableModel;
        QTableView *tableView;
        QPushButton *btnAdd;
        QPushButton *btnEdit;
        QPushButton *btnCancel;
        QPushButton *btnOrder;
};

/**
 * Display single order tab ui, for Algorithm order
 */
class SingleOrderTab_Algo : public QWidget
{
    Q_OBJECT

    public:
        SingleOrderTab_Algo(QWidget *parent = 0);

    private:
        void createLayout();
};

#endif // SINGLEORDERTAB_H_
