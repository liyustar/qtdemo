#include "orderwidget.h"

#include <QtWidgets>

OrderWidget::OrderWidget(QWidget *parent)
    : QTabWidget(parent)
{
    singleOrderTab = new SingleOrderTab();

    addTab(singleOrderTab, "Single Order");
    // addTab(basketordertab, "Basket Order");
}
