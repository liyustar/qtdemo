#ifndef WINDOW_H_
#define WINDOW_H_

#include <QWidget>

class QLabel;

class Window : public QWidget {
    Q_OBJECT

    public:
        Window();

    private:
        QLabel *createLabel(const QString &text);
};

#endif // WINDOW_H_
