#include <QtWidgets>

#include "dynamiclayouts.h"

#define HELP_TEXT "This widget takes up all the remaining " \
    "space in the top-level layout."

DynamicLayouts::DynamicLayouts(QWidget *parent)
    : QDialog(parent)
{
    createOptionsGroupBox();
    createButtonBox();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(optionsGroupBox, 1, 0);
    mainLayout->addWidget(buttonBox, 2, 0);
    setLayout(mainLayout);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    setWindowTitle(tr("Dynamic Layouts"));
}

DynamicLayouts::~DynamicLayouts()
{

}

void DynamicLayouts::buttonsOrientationChanged(int index) {
    // TODO: 不知道干嘛
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    setMinimumSize(0, 0);

    Qt::Orientation orientation = Qt::Orientation(
            buttonsOrientationComboBox->itemData(index).toInt());

    // 和按钮组的方向对比
    if (orientation == buttonBox->orientation())
        return;

    int spacing = mainLayout->spacing();

    QSize oldSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);
    // 让按钮组旋转
    buttonBox->setOrientation(orientation);
    QSize newSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);

    if (orientation == Qt::Horizontal) {
        mainLayout->addWidget(buttonBox, 2, 0);
        resize(size() + QSize(-oldSizeHint.width(), newSizeHint.height()));
    }
    else {
        mainLayout->addWidget(buttonBox, 0, 3, 2, 1);
        resize(size() + QSize(newSizeHint.width(), -oldSizeHint.height()));
    }

    // TODO: 也不知道干嘛
    mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
}

void DynamicLayouts::rotateWidgets() {
}

void DynamicLayouts::help() {
}

void DynamicLayouts::createRotableGroupBox() {

}

void DynamicLayouts::createOptionsGroupBox() {
    optionsGroupBox = new QGroupBox(tr("Options"));

    buttonsOrientationLabel = new QLabel(tr("Orientation of buttons:"));

    buttonsOrientationComboBox = new QComboBox;
    buttonsOrientationComboBox->addItem(tr("Horizontal"), Qt::Horizontal);
    buttonsOrientationComboBox->addItem(tr("Vertical"), Qt::Vertical);

    connect(buttonsOrientationComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(buttonsOrientationChanged(int)));

    optionsLayout = new QGridLayout;
    optionsLayout->addWidget(buttonsOrientationLabel, 0, 0);
    optionsLayout->addWidget(buttonsOrientationComboBox, 0, 1);
    optionsLayout->setColumnStretch(2, 1);
    optionsGroupBox->setLayout(optionsLayout);
}

void DynamicLayouts::createButtonBox() {
    buttonBox = new QDialogButtonBox;

    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
    helpButton = buttonBox->addButton(QDialogButtonBox::Help);
    rotateWidgetsButton = buttonBox->addButton(tr("Rotate &Widgets"), QDialogButtonBox::ActionRole);

    // add connect
}
