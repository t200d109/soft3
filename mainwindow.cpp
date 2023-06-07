#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    //ui->imagelabel1->setPixmap(QPixmap::fromImage(QImage(QFileDialog::getOpenFileName())));
//    cv::Mat src,dst;        //
//    src = cv::imread(QPixmap::fromImage(QImage(QFileDialog::getOpenFileName())));
//    cv::cvtColor(src,dst,cv::COLOR_RGB2BGR);
//    QImage img(dst.data,dst.cols,dst.rows,QImage::Format_RGB888);
}
