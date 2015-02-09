#include <QtWidgets>

#include "basiclayouts.h"
#include <iostream>

#define SAMPLE_TEXT "This widget takes up all the remaining " \
    "space in the top-level layout."

BasicLayouts::BasicLayouts(QWidget *parent)
    : QDialog(parent)
{
    // [0]
    createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
    createFormGroupBox();

    /*
    // [1]
    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr(SAMPLE_TEXT));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
            | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    */
    // [2]
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(formGroupBox);
    /*
    mainLayout->addWidget(buttonBox);

    */
    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}

BasicLayouts::~BasicLayouts()
{

}

void BasicLayouts::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void BasicLayouts::createHorizontalGroupBox() {
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    if (layout == NULL)
        std::cout << "layout error" << std::endl;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        if (buttons[i] == NULL)
            std::cout << "error" << std::endl;
        else
            layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}

void BasicLayouts::createGridGroupBox() {
    gridGroupBox = new QGroupBox(tr("Grid layout"));
    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr("Line %1:").arg(i + i));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1, 1);
    }

    smallEditor = new QTextEdit;
    smallEditor->setPlainText(tr(SAMPLE_TEXT));
    layout->addWidget(smallEditor, 0, 2, 4, 1);

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);
}

void BasicLayouts::createFormGroupBox() {
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel("Line 1:"), new QLineEdit);
    layout->addRow(new QLabel("Line 2, long text:"), new QComboBox);
    layout->addRow(new QLabel("Line 3:"), new QSpinBox);
    formGroupBox->setLayout(layout);
}
