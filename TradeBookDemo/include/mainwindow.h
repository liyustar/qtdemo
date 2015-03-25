#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

#include "orderwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private:
        void createMenus();

        OrderWidget *orderWidget;   // 主控件

        QMenu *fileMenu;
        QAction *exitAct;
};

#endif // MAINWINDOW_H_
