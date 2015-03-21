#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class QTableView;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private:
        void createMainLayout();

        QWidget *mainWidget;

        QTableView *tableView;
        QPushButton *btnAdd;
        QPushButton *btnRemove;
        QLineEdit *edtSearch;
};

#endif // MAINWINDOW_H_
