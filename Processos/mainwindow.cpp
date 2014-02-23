#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sobre.h"


using namespace std;

int timePassed;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pai("pai.png");
    QPixmap filho("filho.png");
    QPixmap neto("crianca.png");

    ui->Pai->setPixmap(pai);
    ui->Filho1->setPixmap(filho);
    ui->Filho2->setPixmap(filho);
    ui->Neto1->setPixmap(neto);
    ui->Neto2->setPixmap(neto);

    ui->Pai->hide();
    ui->Filho1->hide();
    ui->Filho2->hide();
    ui->Neto1->hide();
    ui->Neto2->hide();

    p = new QProcess();
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(updateText()));
    connect(p, SIGNAL(finished(int)), this, SLOT(stopClock()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateClock()));
}

void MainWindow::updateClock() {
    timePassed += timer->interval() / 1000;
    ui->lcdNumber->display(timePassed);
}

void MainWindow::stopClock() {
    timer->stop();
    ui->pushButton->setDisabled(false);
}

void MainWindow::updateText() {
    QString teste = (p->readAllStandardOutput());
    if (teste.contains('0')) {
       goAdicionar(0);
    }
    else if (teste.contains('1')) {
       goAdicionar(1);
    }
    else if (teste.contains('2')) {
       goAdicionar(2);
    }
    else if (teste.contains('3')) {
       goAdicionar(3);
    }
    else if (teste.contains('4')) {
       goAdicionar(4);
    }
    else if (teste.contains('5')) {
       goAdicionar(5);
    }
    else if (teste.contains('6')) {
       goAdicionar(6);
    }
    else if (teste.contains('7')) {
       goAdicionar(7);
    }
    else if (teste.contains('8')) {
       goAdicionar(8);
    }
    else if (teste.contains('9')) {
       goAdicionar(9);
    }
}

void MainWindow::on_pushButton_clicked()
{
    timePassed = 0;
    p->start("./processo");
    timer->start(1000);
    ui->pushButton->setDisabled(true);
}

void MainWindow::goAdicionar(int number)
{
    switch(number) {
    case 0:
        ui->Pai->show();
        break;
    case 1:
        ui->Filho1->show();
        break;
    case 2:
        ui->Filho2->show();
        break;
    case 3:
        ui->Neto1->show();
        break;
    case 4:
        ui->Neto2->show();
        break;
    case 5:
        ui->Pai->hide();
        break;
    case 6:
        ui->Filho1->hide();
        break;
    case 7:
        ui->Filho2->hide();
        break;
    case 8:
        ui->Neto1->hide();
        break;
    case 9:
        ui->Neto2->hide();
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
