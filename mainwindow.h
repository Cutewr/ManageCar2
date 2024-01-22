#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<chargedia.h>
#include<countdia.h>
//摄像头
#include<QCamera>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include<QImage>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void chargeSignal(const QString &text);

public slots:
    void on_pushButton_4_clicked();
    void read_ack(QNetworkReply*);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    chargeDia* mycharge;
    countdia* mycount;
    QString lastSavedResult;  // 上一次保存的结果

    //创建两个摄像头对象
    QCamera *ca;
    cv::Mat capturedFrame;  // 存储捕获到的帧
    bool focusComplete;     // 标志对焦是否完成
    cv::Mat focusedImage;
    cv::VideoCapture* capture;  // 修改成指针
    QTimer* timer;  // 修改成指针
    void readFrame();
    void handlePlate(QString text);
    void saveResult(const QString &result);

public:
    QNetworkAccessManager *httpmanager;
    QMap<QString, QString> countFee(QString type,QString payw);
};
#endif // MAINWINDOW_H
