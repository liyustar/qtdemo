#include "singleorderformdialog.h"

#include <QtWidgets>

SingleOrderFormDialog::SingleOrderFormDialog(QWidget *parent)
{
    createFormLayout();

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
            | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
}

void SingleOrderFormDialog::createFormLayout()
{
    edtSymbol = new QLineEdit;
    combDirect = new QComboBox;
    sdbPrice = new QDoubleSpinBox;
    spbQty = new QSpinBox;

    formLayout = new QFormLayout;
    formLayout->addRow(new QLabel("Symbol:"), edtSymbol);
    formLayout->addRow(new QLabel("Direct:"), combDirect);
    formLayout->addRow(new QLabel("Price:"), sdbPrice);
    formLayout->addRow(new QLabel("Quatity:"), spbQty);
}
