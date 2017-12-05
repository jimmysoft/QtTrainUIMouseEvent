#include "blisterinfodialog.h"
#include "ui_blisterinfodialog.h"

BlisterInfoDialog::BlisterInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlisterInfoDialog)
{
    ui->setupUi(this);
    ui->labelWhite->setStyleSheet("QLabel { background-color : white; }");
    changeBlisterSize(this->width, this->height);
}

BlisterInfoDialog::~BlisterInfoDialog()
{
    delete ui;
}

void BlisterInfoDialog::on_spinBoxWidth_valueChanged(int width)
{
    this->width = width;
    changeBlisterSize(width, this->height);
}

void BlisterInfoDialog::on_spinBoxHeight_valueChanged(int height)
{
    this->height = height;
    changeBlisterSize(this->width, height);
}

void BlisterInfoDialog::changeBlisterSize(int width, int height)
{
//    ui->labelBlister->setFixedWidth(width);
//    ui->labelBlister->setFixedHeight(height);

//    int x = ((ui->labelWhite->width())-width)/2+30;
//    int y = ((ui->labelWhite->height())-height)/2+30;
    int x = 30;
    int y = 50;

    ui->labelBlister->setGeometry(QRect(x, y, width, height));
}

void BlisterInfoDialog::changeSpinValue(int width, int height)
{
    ui->spinBoxWidth->setValue(width);
    ui->spinBoxHeight->setValue(height);
}

int BlisterInfoDialog::getBlisterLabelWidth()
{
    int absoluteWidth = ui->labelBlister->width();
    return absoluteWidth;
}

int BlisterInfoDialog::getBlisterLabelHeight()
{
    int absoluteHeight = ui->labelBlister->height();
    return absoluteHeight;
}
