#ifndef SINGLEORDERFORM_H_
#define SINGLEORDERFORM_H_

#include <QWidget>
#include "type.h"

class QFormLayout;
class QLineEdit;
class QComboBox;

class SingleOrderForm : public QWidget
{
    Q_OBJECT

    public:
        SingleOrderForm(QWidget *parent = 0);

        Order_t getCurrentOrder();

    private:
        void createFormLayout();

        QFormLayout *formLayout;

        QLineEdit *edtSymbol;   // symbol
        QComboBox *combDirect;  // direct: buy, sell
        QLineEdit *edtPrice;    // price
        QLineEdit *edtQty;      // quatity
};

#endif // SINGLEORDERFORM_H_
