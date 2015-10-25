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

static QString alphabet="abcdefghijklmnopqrstuvwxyz0123456789 ";

// нахер  я мозги себе взрывал если все так просто
QString coder(QString text,QString key){
    QString result="";
    int k[text.length()];
    int l[key.length()];
    if(key.length()>text.length())
        return result="error";

    for(int i=0;i<key.length();i++)
        l[i]=alphabet.indexOf(key.at(i));

    int j=0;
    for(int i=0;i<text.length();i++){
        k[i]=alphabet.indexOf(text.at(i));
        if (j==key.length())
            j=0;
        result+=alphabet[(k[i]+l[j])%alphabet.length()];
        j++;
    }
    return result;
}

QString decoder(QString text,QString key){
    QString result="";
    int k[text.length()];
    int l[key.length()];
    if(key.length()>text.length())
        return result="error";

    for(int i=0;i<key.length();i++)
        l[i]=alphabet.indexOf(key.at(i));

    int j=0;
    for(int i=0;i<text.length();i++){
        k[i]=alphabet.indexOf(text.at(i));
        if (j==key.length())
            j=0;
        result+=alphabet[(k[i]-l[j]+alphabet.length())%alphabet.length()];
        j++;
    }
    return result;
}

QString genkey(int n){
    QString result="";
    if(n<=0)
        return result="error";
    int i = 1+rand()% n;
    for(int j=0;j<i;j++)
        result+=alphabet[rand()%alphabet.length()];
    return result;
}

void MainWindow::on_codeButton_clicked()
{
  ui->codeEdit->setText(coder(ui->decodeEdit->text(),ui->keyEdit->text()));

}

void MainWindow::on_decodeButton_clicked()
{
    ui->decodeEdit->setText(decoder(ui->codeEdit->text(),ui->keyEdit->text()));
}

void MainWindow::on_genButton_clicked()
{
    ui->keyEdit->setText(genkey(ui->decodeEdit->text().length()));
}
