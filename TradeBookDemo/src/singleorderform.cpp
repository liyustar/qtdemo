#include "singleorderform.h"

#include <QtWidgets>

SingleOrderForm::SingleOrderForm(QWidget *parent)
    : QWidget(parent)
{
    createFormLayout();

    setLayout(formLayout);
}

void SingleOrderForm::createFormLayout()
{
    edtSymbol = new QLineEdit;
    combDirect = new QComboBox;
    edtPrice = new QLineEdit;
    edtQty = new QLineEdit;

    formLayout = new QFormLayout;
    formLayout->addRow(new QLabel("Symbol:"), edtSymbol);
    formLayout->addRow(new QLabel("Direct:"), combDirect);
    formLayout->addRow(new QLabel("Price:"), edtPrice);
    formLayout->addRow(new QLabel("Quatity:"), edtQty);

    setMaximumWidth(230);
}

Order_t SingleOrderForm::getCurrentOrder()
{
    Order_t order;
    order.symbol = edtSymbol->text();
    order.price = edtPrice->text().toDouble();
    order.quantity = edtQty->text().toInt();
    return order;
}
