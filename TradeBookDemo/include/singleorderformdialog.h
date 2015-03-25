#ifndef SINGLEORDERFORMDIALOG_H_
#define SINGLEORDERFORMDIALOG_H_

#include <QDialog>

class QFormLayout;
class QLineEdit;
class QComboBox;
class QDoubleSpinBox;
class QSpinBox;

class SingleOrderFormDialog : public QDialog
{
    Q_OBJECT

    public:
        SingleOrderFormDialog(QWidget *parent = 0);

    private:
        void createFormLayout();

        QFormLayout *formLayout;

        QLineEdit *edtSymbol;   // symbol
        QComboBox *combDirect;  // direct: buy, sell
        QDoubleSpinBox *sdbPrice;   // price
        QSpinBox *spbQty;       // quatity
};

#endif // SINGLEORDERFORMDIALOG_H_
