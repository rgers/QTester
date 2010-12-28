#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "klient.h"
#include "serwer.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    klient* kl;
    Serwer* srw;


private slots:
    void on_msgsendbtn_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void kl_newMsg(QString* msg);
};

#endif // MAINWINDOW_H
