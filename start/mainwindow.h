#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QFileDialog>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QMouseEvent>
#include <QPixmap>
#include <QtCore/QDebug>
#include <QLabel>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_startbutton_released();
    void updateTime();
    void on_radioButton_clicked(bool checked);
    void on_giveupbutton_released();
    void mousePressEvent(QMouseEvent *event);

    void on_clearbutton_released();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int num = 10;//間違いの個数
    unsigned long int time10 = 1000; //制限時間1000=10秒、間違いの個数、難易度によって変化？
    QList<QLabel*> imageLabels;
    QPixmap ans;//結果画像
    QImage ansimg;//ansをQImageに変換
};
#endif // MAINWINDOW_H
