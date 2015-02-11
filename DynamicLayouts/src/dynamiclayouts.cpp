#include <QtWidgets>

#include "dynamiclayouts.h"

#define HELP_TEXT "This example shows how to change layouts dynamically."

DynamicLayouts::DynamicLayouts(QWidget *parent)
    : QDialog(parent)
{
    createOptionsGroupBox();
    createButtonBox();
    createRotableGroupBox();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(rotableGroupBox, 0, 0);
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

    // 将控件从布局上移除
    foreach (QWidget *widget, rotableWidgets)
        rotableLayout->removeWidget(widget);

    rotableWidgets.enqueue(rotableWidgets.dequeue());

    // 将控件从新加入到布局中
    const int n = rotableWidgets.count();
    for (int i = 0; i < n / 2; ++i) {
        rotableLayout->addWidget(rotableWidgets[n - i - 1], 0, i);
        rotableLayout->addWidget(rotableWidgets[i], 1, i);
    }
}

void DynamicLayouts::help() {
    QMessageBox::information(this, tr("Dynamic Layouts Help"),
            tr(HELP_TEXT));
}

void DynamicLayouts::createRotableGroupBox() {
    rotableGroupBox = new QGroupBox(tr("Rotable Widgets"));

    rotableWidgets.enqueue(new QSpinBox);
    rotableWidgets.enqueue(new QSlider);
    rotableWidgets.enqueue(new QDial);
    rotableWidgets.enqueue(new QProgressBar);

    for (int i = 0; i < 4; ++i) {
        connect(rotableWidgets[i], SIGNAL(valueChanged(int)),
                rotableWidgets[(i + 1) % 4], SLOT(setValue(int)));
    }

    rotableLayout = new QGridLayout;
    rotableGroupBox->setLayout(rotableLayout);

    rotateWidgets();
}

void DynamicLayouts::createOptionsGroupBox() {
    // 控件组的框框
    optionsGroupBox = new QGroupBox(tr("Options"));

    buttonsOrientationLabel = new QLabel(tr("Orientation of buttons:"));

    // 下拉列表
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
    // 对话框的标准按钮
    buttonBox = new QDialogButtonBox;

    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
    helpButton = buttonBox->addButton(QDialogButtonBox::Help);
    rotateWidgetsButton = buttonBox->addButton(tr("Rotate &Widgets"), QDialogButtonBox::ActionRole);

    connect(rotateWidgetsButton, SIGNAL(clicked()), this, SLOT(rotateWidgets()));
    connect(helpButton, SIGNAL(clicked()), this, SLOT(help()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}
