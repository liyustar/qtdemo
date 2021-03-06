#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private:
        void createMainLayout();
        void createTreeListFileView();
        void createExampleModel();

        QWidget *mainWidget;
};

#endif // MAINWINDOW_H_
