#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::on_radioButton_clicked(bool checked)
{
    if (checked)
    {
        ui->radioButton->setText("Dark");
        emit  changedDark();
    }
    else
    {
        ui->radioButton->setText("Light");
        emit  changedLight();
    }
}
