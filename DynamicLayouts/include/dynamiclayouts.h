#ifndef DYNAMICLAYOUTS_H
#define DYNAMICLAYOUTS_H

#include <QDialog>
#include <QQueue>

class QComboBox;
class QDialogButtonBox;
class QGridLayout;
class QGroupBox;
class QLabel;
class QPushButton;

class DynamicLayouts : public QDialog
{
    Q_OBJECT

public:
    DynamicLayouts(QWidget *parent = 0);
    ~DynamicLayouts();

private slots:
    void buttonsOrientationChanged(int index);
    void rotateWidgets();
    void help();

private:
    void createRotableGroupBox();
    void createOptionsGroupBox();
    void createButtonBox();

    QGroupBox *rotableGroupBox;
    QQueue<QWidget *> rotableWidgets;

    QGroupBox *optionsGroupBox;
    QLabel *buttonsOrientationLabel;
    QComboBox *buttonsOrientationComboBox;

    QDialogButtonBox *buttonBox;
    QPushButton *closeButton;
    QPushButton *helpButton;
    QPushButton *rotateWidgetsButton;

    QGridLayout *mainLayout;
    QGridLayout *rotableLayout;
    QGridLayout *optionsLayout;
};

#endif // DYNAMICLAYOUTS_H
