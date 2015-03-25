#ifndef ORDERWIDGET_H_
#define ORDERWIDGET_H_

#include "singleordertab.h"

#include <QTabWidget>

// 订单主控件，管理各种类型的订单Tab
class OrderWidget : public QTabWidget
{
    Q_OBJECT

    public:
        OrderWidget(QWidget *parent = 0);

    private:
        SingleOrderTab *singleOrderTab;
        // BasketOrderTab *basketOrderTab;
};

#endif // ORDERWIDGET_H_
