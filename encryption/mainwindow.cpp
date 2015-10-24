#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vegenere.h"
#include "ui_vegenere.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    vegenere* veg=new vegenere;
    veg->show();
    this->hide();

}
