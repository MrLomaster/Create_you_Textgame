#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buff.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Buff a;
    a.ID_PQ = ui->IDEdit->text().toInt();
    a.TextQ = ui->TextEdit->text();
    a.d1TextQ = ui->ViborText1Edit->text();
    a.d2TextQ = ui->ViborText2Edit->text();
    a.d1Dash = ui->DashVibor1Edit->text().toInt();
    a.d2Dash = ui->DashVibor2Edit->text().toInt();
    a.DiedBuff = ui->checkBox->isChecked();
    a.WriteFromDB();
}
