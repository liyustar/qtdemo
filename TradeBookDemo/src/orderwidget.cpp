#include "orderwidget.h"

#include <QtWidgets>

OrderWidget::OrderWidget(QWidget *parent)
    : QWidget(parent)
{
    createButtonsWidget();
    createLayout();
    initWidgetStatus();
}

void OrderWidget::createButtonsWidget()
{
    buttonsWidget = new QListWidget;

    btnSingleOrder = new QListWidgetItem(buttonsWidget);
    btnBasketOrder = new QListWidgetItem(buttonsWidget);
}

void OrderWidget::createLayout()
{
    singleOrderTab = new SingleOrderTab();
    // basketOrderTab = new BasketOrderTab();

    tabLayout = new QStackedLayout;
    tabLayout->addWidget(singleOrderTab);
    // tabLayout->addWidget(basketOrderTab);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(buttonsWidget);
    mainLayout->addLayout(tabLayout);

    // Set Layout
    setLayout(mainLayout);
}

void OrderWidget::initWidgetStatus()
{
    // Set Connect
    connect(buttonsWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*, QListWidgetItem*)));

    // Other Setting
    btnSingleOrder->setText(tr("Single Order"));
    btnBasketOrder->setText(tr("Basket Order"));

    btnBasketOrder->setFlags(btnBasketOrder->flags() & ~Qt::ItemIsEnabled);

    btnSingleOrder->setTextAlignment(Qt::AlignHCenter);
    btnBasketOrder->setTextAlignment(Qt::AlignHCenter);

    buttonsWidget->setViewMode(QListView::IconMode);
    buttonsWidget->setMovement(QListView::Static);
    buttonsWidget->setIconSize(QSize(96, 128));
    buttonsWidget->setMaximumWidth(128);
    buttonsWidget->setMinimumWidth(128);
    buttonsWidget->setSpacing(12);
}

void OrderWidget::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    tabLayout->setCurrentIndex(buttonsWidget->row(current));
}
