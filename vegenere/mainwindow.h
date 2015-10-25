#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_codeButton_clicked();

    void on_decodeButton_clicked();

    void on_genButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
