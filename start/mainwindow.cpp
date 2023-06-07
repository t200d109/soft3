#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(++current_page);
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked){
        timer->start(10);
    }
    else{
        timer->stop();
    }
}

void MainWindow::updateTime()
{
    if(time10>0){
        --time10;
        ui->timelabel->setText("残り"+QString::number(time10/100.0,'f',0)+"秒");
    }else {
        ui->timelabel->setText("タイムアップ");//画面遷移にする
    }
}
