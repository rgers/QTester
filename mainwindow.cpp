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

void MainWindow::on_pushButton_clicked()
{
    srw = new Serwer();
    srw->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    kl = new klient();
    connect(kl, SIGNAL(newMsg(QString*)), this, SLOT(kl_newMsg(QString*)));
  kl->start();
}

void MainWindow::kl_newMsg(QString* msg)
{
    ui->msgrcvbox->document()->setPlainText(*msg);
}

void MainWindow::on_pushButton_3_clicked()
{
   kl->wyslij("co slychac?");
}

void MainWindow::on_msgsendbtn_clicked()
{
  kl->wyslij(ui->msgsendbox->document()->toPlainText().toAscii().constData());
}
