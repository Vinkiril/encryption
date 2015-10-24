#include "mainwindow.h"
#include "ui_mainwindow.h"
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

static QString alphabet="abcdefghijklmnopqrstuvwxyz0123456789";
int** sqrVegenere(QString alf){
    int **n =new int*[alf.length()]; //создание массива указателей
    for(int i=0;i<alf.length();i++){
        n[i]=new int[alf.length()];
    }
   // for (int i=0;i<;)
    for (int i=0;i<alf.length();i++){
        for(int j=0;j<alf.length();j++){
            if(j+1==alf.length())
                n[i][j]=5;
        }
    }
    return n;
}

void delArr(int **arr,int n){
    for(int i=0;i<n;i++){
        delete arr[i];
    }
    delete[] arr;
}

/*
QString* sqr_vegenere(QString alf){

    QString sqrVeg[]="";
    for(int i=0;i<alf.length();i++){
        for (int j=0;j<alf.length();j++){

            if ((j+1)==alf.length())
                sqrVeg[j][i]=alf[0];
            else
                sqrVeg[j][i]=alf[j+1];
        }
    }
    return sqrVeg;
}*/


void MainWindow::on_codeButton_clicked()
{
    //ui->codeEdit->setText(sqr_vegenere(albhabet));

}
