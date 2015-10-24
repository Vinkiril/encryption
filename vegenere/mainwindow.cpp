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
QString coder(QString alf,QString text,QString key){
    QString result="";
    int k[text.length()];
    int l[key.length()];
    if(key.length()>text.length())
        return result="Длина ключа больше сообщения";

    for(int i=0;i<key.length();i++)
        l[i]=alf.indexOf(key.at(i));

    int j=0;
    for(int i=0;i<text.length();i++){
        k[i]=alf.indexOf(text.at(i));
        if (j==key.length())
            j=0;
        result+=alf[(k[i]+l[j])%alf.length()];
        j++;
    }
    return result;
}

QString decoder(QString alf,QString text,QString key){
    QString result="";
    int k[text.length()];
    int l[key.length()];
    if(key.length()>text.length())
        return result="Длина ключа больше сообщения";

    for(int i=0;i<key.length();i++)
        l[i]=alf.indexOf(key.at(i));

    int j=0;
    for(int i=0;i<text.length();i++){
        k[i]=alf.indexOf(text.at(i));
        if (j==key.length())
            j=0;
        result+=alf[(k[i]-l[j]+alf.length())%alf.length()];
        j++;
    }
    return result;
}

void MainWindow::on_codeButton_clicked()
{
  ui->codeEdit->setText(coder(alphabet,ui->decodeEdit->text(),ui->keyEdit->text()));

}

void MainWindow::on_decodeButton_clicked()
{
    ui->decodeEdit->setText(decoder(alphabet,ui->codeEdit->text(),ui->keyEdit->text()));
}
