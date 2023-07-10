#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralWidget()->setStyleSheet("background:lemonchiffon;");
    ui->pushButton->setStyleSheet("*{padding:10px; border-radius:10px; background-color:whitesmoke; border:3px outset gainsboro;}"
                                     ":pressed {background-color:gainsboro; color:black; border-style:inset;}");
    QPixmap boy("/home/user/Qt/num/shigototyu.png");
    int w = ui->pix_label->width();
    int h = ui->pix_label->height();
    ui->pix_label->setPixmap(boy.scaled(w,h,Qt::KeepAspectRatio));
    ui->spinBox->setRange(1,100);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    num = arg1;
}

void MainWindow::on_pushButton_released()
{
//    auto current_page = ui->stackedWidget->currentIndex();
//    ui->stackedWidget->setCurrentIndex(++current_page);
}
