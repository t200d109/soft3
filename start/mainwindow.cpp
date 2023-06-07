#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    QPixmap pix("/home/user/Qt/start/software_logo_half3.png");//間違い撲滅委員会
    QPixmap img1("/home/user/Qt/start/test1.png");//image1
    QPixmap img2("/home/user/Qt/start/test2.png");//image2
    //スタート画面にロゴを表示
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //1つ目の画像を表示
    int w1 = ui->imagelabel1->width();
    int h1 = ui->imagelabel1->height();
    ui->imagelabel1->setPixmap(img1.scaled(w1,h1,Qt::KeepAspectRatio));
    //2つ目の画像を表示
    int w2 = ui->imagelabel2->width();
    int h2 = ui->imagelabel2->height();
    ui->imagelabel2->setPixmap(img2.scaled(w2,h2,Qt::KeepAspectRatio));
    //間違いの残りの個数
//    int num=10;
//    ui->kosulabel->setText("あと"+num+"コ");
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
