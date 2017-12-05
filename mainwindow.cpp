#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blisterinfodialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BlisterInfoDialog* blisterInfoDialogui;
    blisterInfoDialogui = new BlisterInfoDialog();
    blisterInfoDialogui->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
