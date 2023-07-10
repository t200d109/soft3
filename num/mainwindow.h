#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_released();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    int num;
};
#endif // MAINWINDOW_H
