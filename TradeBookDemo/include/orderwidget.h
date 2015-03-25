#ifndef ORDERWIDGET_H_
#define ORDERWIDGET_H_

#include "singleordertab.h"

#include <QWidget>

class QListWidget;
class QListWidgetItem;
class QStackedLayout;

// 订单主控件，管理各种类型的订单Tab
class OrderWidget : public QWidget
{
    Q_OBJECT

    public:
        OrderWidget(QWidget *parent = 0);

    private slots:
        void changePage(QListWidgetItem *current, QListWidgetItem *previous);

    private:
        void createButtonsWidget();
        void createLayout();
        void initWidgetStatus();

        SingleOrderTab *singleOrderTab;
        // BasketOrderTab *basketOrderTab;
        QListWidgetItem *btnSingleOrder;
        QListWidgetItem *btnBasketOrder;

        QListWidget *buttonsWidget;
        QStackedLayout *tabLayout;
};

#endif // ORDERWIDGET_H_
