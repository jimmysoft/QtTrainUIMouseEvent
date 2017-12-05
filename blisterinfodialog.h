#ifndef BLISTERINFODIALOG_H
#define BLISTERINFODIALOG_H

#include <QDialog>

namespace Ui {
class BlisterInfoDialog;
}

class BlisterInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BlisterInfoDialog(QWidget *parent = 0);
    ~BlisterInfoDialog();
    int width = 50;
    int height = 50;
    void changeBlisterSize(int, int);
    void changeSpinValue(int, int);
    int getBlisterLabelWidth();
    int getBlisterLabelHeight();

private slots:
    void on_spinBoxWidth_valueChanged(int arg1);

    void on_spinBoxHeight_valueChanged(int arg1);

private:
    Ui::BlisterInfoDialog *ui;
};

#endif // BLISTERINFODIALOG_H
