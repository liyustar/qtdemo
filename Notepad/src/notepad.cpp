#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_quitButton_clicked()
{
    qApp->quit();
}

void Notepad::on_actionOpen_triggered()
{

}

void Notepad::on_actionSave_triggered()
{

}
