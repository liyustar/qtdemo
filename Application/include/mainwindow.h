#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class QAction;
class QMenu;
class QPlainTextEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private:
        void createActions();
        void createMenus();
        void createToolBars();
        void createStatusBar();

        QPlainTextEdit *textEdit;

        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *helpMenu;
        QToolBar *fileToolBar;
        QToolBar *editToolBar;
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;
        QAction *saveAsAct;
        QAction *exitAct;
        QAction *cutAct;
        QAction *copyAct;
        QAction *pasteAct;
        QAction *aboutAct;
        QAction *aboutQtAct;
};

#endif // MAINWINDOW_H_
