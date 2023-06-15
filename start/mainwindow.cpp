#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    QPixmap pix("/home/user/Qt/start/software_logo_half3.png");//間違い撲滅委員会ロゴ
    QPixmap img1("/home/user/Qt/start/test1.png");//image1
    QPixmap img2("/home/user/Qt/start/test2.png");//image2//
    QPixmap comp("/home/user/Qt/start/comp.png");//クリア画面
//    QPixmap ans("/home/user/Qt/start/Result.png");//結果画像
//    ans = ans.scaled(ui->imagelabel2->width(),ui->imagelabel2->height(),Qt::KeepAspectRatio);//結果画像の大きさを調節
//    QImage ansimg = ans.toImage();
        //connect(this,&MainWindow::mousePressEvent);
    centralWidget()->setStyleSheet("background:lemonchiffon;");//背景色
    ui->startbutton->setStyleSheet("background-color:gainsboro;");//スタートボタン色
    ui->giveupbutton->setStyleSheet("background-color:gainsboro;");//ギブアップボタン色
    ui->clearbutton->setStyleSheet("background-color:gainsboro;");
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
    //クリア画面を表示
    int w3 = ui->clearlabel->width();
    int h3 = ui->clearlabel->height();
    ui->clearlabel->setPixmap(comp.scaled(w3,h3,Qt::KeepAspectRatio));
    //ui->clearlabel->setPixmap(img2.scaled(w3,h3,Qt::KeepAspectRatio));
    //間違いの残りの個数
    ui->allnumlabel->setText("全部で"+QString::number(num)+"こ");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startbutton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(++current_page);
}

void MainWindow::on_radioButton_clicked(bool checked)//timerstart/stop
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
        for(QLabel* label : imageLabels){//丸を消去
            label->deleteLater();
        }
        imageLabels.clear();
        ui->timelabel->setText("タイムアップ");//画面遷移にする
    }
}


void MainWindow::on_giveupbutton_released()//ギブアップボタン
{
    for(QLabel* label : imageLabels){//丸を消す
        label->deleteLater();
    }
    imageLabels.clear();
    auto current_page = ui->stackedWidget->currentIndex();//本当は結果表示画面に行かないといけない
    ui->stackedWidget->setCurrentIndex(++current_page);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint p = ui->imagelabel2->mapFromGlobal(QCursor::pos());
    QPoint pos = this->mapFromGlobal(QCursor::pos());
    //qDebug() << "press:" << p;
    int x = p.x();
    int y = p.y();
    //85~88は本当は上でやりたい、、とりあえず保留。。ほりゅうできなくなりましたよ〜
    QPixmap ans("/home/user/Qt/start/Result.png");//結果画像
    ans = ans.scaled(ui->imagelabel2->width(),ui->imagelabel2->height(),Qt::KeepAspectRatio);//結果画像の大きさを調節
    QImage ansimg = ans.toImage();
    QColor color = ansimg.pixelColor(x,y);
    qDebug() << ansimg.pixelColor(x,y);
    int red = color.red();
    if(red == 255){//正解だったとき
        num--;
        for(int i=-2;i<3;i++){
            for(int j=-2;j<3;j++){
                QRgb pixel = ansimg.pixel(x,y);
                pixel = qRgb(0,qGreen(pixel),qBlue(pixel));
                ansimg.setPixel(x,y,pixel);
            }
        }
        //正解した箇所に丸を表示
        QLabel* imageLabel = new QLabel(this);
        QPixmap cir("/home/user/Qt/start/cir.jpg");
        imageLabel->setPixmap(cir);
        imageLabel->move(pos.x()-20,pos.y()-20);//ーの値考える。
        imageLabel->show();
        imageLabels.append(imageLabel);//keep
        if(num == 0){
            for(QLabel* label : imageLabels){
                label->deleteLater();
            }
            imageLabels.clear();
            auto current_page = ui->stackedWidget->currentIndex();
            ui->stackedWidget->setCurrentIndex(++current_page);

        }
        ui->kosulabel->setText("あと"+QString::number(num)+"こ");
    }
    //qDebug() << "red" << red;
}

void MainWindow::on_clearbutton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(current_page=0);//ゲームクリア後スタートへ戻る
}
