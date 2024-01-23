#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectionData.h"
#include <QSqlError>
#include <vector>
#include <QProcess>
#include <Python.h>
#include <QDir>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSet>
static QStringList recentResults;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    focusComplete(false),
    capture(nullptr),
    timer(new QTimer(this))  // 初始化为 false
{

    ui->setupUi(this);
    createConnection();

    mycharge =new chargeDia(this);
    connect(ui->pushButton,&QPushButton::clicked,mycharge,&chargeDia::open);
    connect(this,SIGNAL(chargeSignal(const QString &)),mycharge,SLOT(chargeSlot(const QString &)));

    mycount= new countdia(this);
    connect(ui->pushButton_2,&QPushButton::clicked,mycount,&countdia::open);

    // 初始化摄像头捕获
    // 在 MainWindow 类的构造函数中的初始化列表中添加
    capture = new cv::VideoCapture(0,cv::CAP_V4L2);  // 0表示默认摄像头，可以根据实际情况修改
    if (!capture->isOpened()) {
        qDebug() << "Error: Could not open camera.";
    }
    // 初始化定时器
    timer = new QTimer(this);
    // 连接定时器的超时信号到处理槽
    connect(timer, &QTimer::timeout, this, &MainWindow::readFrame);
    // 设置定时器间隔，单位毫秒
    timer->start(500);  // 30帧每秒，可以根据需要调整

    httpmanager = new QNetworkAccessManager;
    connect(httpmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(read_ack(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
    // 释放摄像头资源
    if (capture) {
        capture->release();
        delete capture;
    }
    // 停止和销毁定时器
    if (timer) {
        timer->stop();
        delete timer;
    }
}

void MainWindow::readFrame()
{
    cv::Mat frame;
    *capture >> frame;  // 从摄像头读取帧
    if (frame.empty()) {
        qDebug() << "Error: Could not read frame.";
        return;
    }

    // 显示摄像头帧在第一个 QLabel 上
    QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image.rgbSwapped());
    ui->label->setPixmap(pixmap);

    // 将实时视频帧数据传递给 Python 脚本
    QByteArray imageData(reinterpret_cast<const char*>(frame.data), frame.total());
    // 设置 Python 脚本路径
    QString scriptPath = "/home/wr/PycharmProjects/pythonProject3/test03.py";
    // 构建 Python 解释器路径
    QString pythonInterpreter = "/home/wr/anaconda3/envs/pytorch/bin/python";
    // 获取当前工作目录
    QString currentDir = QDir::currentPath();
    // 设置 Python 脚本运行的工作目录
    QDir::setCurrent(QFileInfo(scriptPath).absolutePath());

    // 构建命令行参数
    QStringList arguments;
    arguments << scriptPath;

    // 启动 Python 脚本
    QProcess process;
    process.setProgram(pythonInterpreter);
    process.setArguments(arguments);

    // 启动进程并等待它开始
    process.start();

    if (!process.waitForStarted()) {
        qDebug() << "Error: Could not start Python process.";
        return;
    }

    // 将图像数据保存为 JPEG 格式
    // Convert QByteArray to std::vector<uchar>
    std::vector<uchar> imageDataVector(imageData.begin(), imageData.end());

    // Save the frame as JPEG using imencode
    cv::imencode(".jpg", frame, imageDataVector);

    process.write(reinterpret_cast<const char*>(imageDataVector.data()), imageDataVector.size());

    // 关闭标准输入流，通知 Python 程序已经传递完毕
    process.closeWriteChannel();

    // 等待进程完成
    process.waitForFinished();

    // 恢复当前工作目录
    QDir::setCurrent(currentDir);
    // 用于存储最近三帧的脚本输出结果

    // 获取 Python 脚本输出
    QByteArray result = process.readAllStandardOutput();
    QByteArray error = process.readAllStandardError();

    // 将结果转换为 QString
    QString resultString = QString::fromUtf8(result).trimmed();
    qDebug()<<resultString;
    // 使用正则表达式提取目标字符串
    static QRegularExpression regex("\\['(.*?)'");
    QRegularExpressionMatch match = regex.match(resultString);
    QString extractedString;
    if (match.hasMatch()) {
        extractedString = match.captured(1);
        qDebug() << "Extracted String:" << extractedString;
    } else {
        extractedString="";
        qDebug() << "Pattern not found.";
    }
    if (recentResults.size() < 3 && extractedString!=""&&extractedString!=lastSavedResult) {
        recentResults << extractedString;
    }

    QSet<QString> uniqueElements2(recentResults.begin(),recentResults.end());
    if(recentResults.size()>=2&&uniqueElements2.size()!=1){
        recentResults.removeFirst();
    }

    QString tempString;
    QSet<QString> uniqueElements(recentResults.begin(),recentResults.end());
    if (recentResults.size() == 3 && uniqueElements.size() == 1) {
        qDebug() << "Python Script Output: " << extractedString;
        lastSavedResult=extractedString;
        tempString=extractedString;
        handlePlate(tempString);

        // 将帧显示在第二个 QLabel 上
        QImage processedImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        QPixmap processedPixmap = QPixmap::fromImage(processedImage.rgbSwapped());
        ui->focusedLabel->setPixmap(processedPixmap);

        // 在字符串中搜索匹配的部分
        QString positionString;
        QRegularExpression regex3("\\[(\\d+,\\s*\\d+,\\s*\\d+,\\s*\\d+)\\]");
        QRegularExpressionMatch match3 = regex3.match(resultString);
        // 提取匹配的部分
        if (match3.hasMatch()) {
            positionString = match3.captured(1);
            qDebug() << "position:" << positionString;

            // 将 QString 转换为 std::vector<int>
            QStringList coordList = positionString.split(", ");
            std::vector<int> coords;
            for (const QString& coord : coordList) {
                coords.push_back(coord.toInt());
            }

            // 定义坐标
            int x = coords[0];
            int y = coords[1];
            int width = coords[2] - x;
            int height = coords[3] - y;

            // 截取区域
            cv::Rect roi(x, y, width, height);
            cv::Mat croppedFrame = frame(roi).clone();  // 使用clone()来复制图像

            QImage croppedImage(croppedFrame.data, croppedFrame.cols, croppedFrame.rows, croppedFrame.step, QImage::Format_RGB888);
            QPixmap croppedPixmap = QPixmap::fromImage(croppedImage.rgbSwapped());
            ui->label_2->setPixmap(croppedPixmap);
        } else {
            qDebug() << "No position.";
        }
        recentResults.clear();
    }
}

void MainWindow::saveResult(const QString &result)
{
    QString resultFilePath = "/home/wr/plateresult/test.txt";
    QFile resultFile(resultFilePath);
    if (resultFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&resultFile);
        stream << result << "\n";
    }
    resultFile.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    std::vector<QMap<QString, QString>> vectorOfMaps;
    vectorOfMaps.push_back(countFee("Internal","wechat"));
    vectorOfMaps.push_back(countFee("Internal","alipay"));
    vectorOfMaps.push_back(countFee("Internal","cash"));
    vectorOfMaps.push_back(countFee("Visitor","wechat"));
    vectorOfMaps.push_back(countFee("Visitor","alipay"));
    vectorOfMaps.push_back(countFee("Visitor","cash"));
    mycount->processData(vectorOfMaps);
}

QMap<QString, QString> MainWindow::countFee(QString type,QString payw){
    QSqlDatabase db= QSqlDatabase::database("DISK");
    QSqlQuery query(db);
    QString numberOfVehicles;
    QString totalAmount;
    QString queryStr = QString("SELECT COUNT(*) AS NumberOfVehicles, IFNULL(SUM(FeeAmount), 0) AS TotalAmount FROM ParkingFee WHERE PayWay = '%1' AND VehicleType = '%2' AND DATE(ExitTime) = CURDATE();").arg(payw).arg(type);
    query.exec(queryStr);
    if (query.next()){
        numberOfVehicles = query.value("NumberOfVehicles").toString();
        totalAmount = query.value("TotalAmount").toString();
    } else {
        // 查询执行失败，获取错误信息
        QSqlError error = query.lastError();
        qDebug() << "MySQL Error: " << error.text();
    }
    QMap<QString, QString> resultMap;
    resultMap[numberOfVehicles] = totalAmount;
    return resultMap;
}

void MainWindow::on_pushButton_3_clicked()
{
    // 设置Python脚本路径
    QString scriptPath = "/home/wr/PycharmProjects/pythonProject3/test03.py";
    // 构建Python解释器路径
    QString pythonInterpreter = "/usr/bin/python3.10";

    // 获取当前工作目录
    QString currentDir = QDir::currentPath();

    // 设置Python脚本运行的工作目录
    QDir::setCurrent(QFileInfo(scriptPath).absolutePath());

    // 构建命令行参数
    QStringList arguments;
    arguments << scriptPath;

    // 启动Python脚本
    QProcess process;
    process.setProgram(pythonInterpreter);
    process.setArguments(arguments);

    // 启动进程
    process.start();
    process.waitForFinished();

    // 恢复当前工作目录
    QDir::setCurrent(currentDir);

    // 获取Python脚本输出
    QByteArray result = process.readAllStandardOutput();
    QByteArray error = process.readAllStandardError();

    // 输出结果
    qDebug() << "Python Script Output: " << result;
    if(error!=""){
        qDebug() << "Python Script Error: " << error;
    }
    handlePlate(result);
}


void MainWindow::on_pushButton_4_clicked()
{
    //向百度发送一个二维码识别请求（HTTP）
    QNetworkRequest myrequset;// = new QNetworkRequest;
    //填充请求url
    myrequset.setUrl(QUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/license_plate?"
                          "access_token=24.a55e7c0f141f4e8fbfc721e4dde21ea7.2592000.1708238641.282335-47439299"));
    //填充header
    myrequset.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //填充请求的body
    QString le_path="/home/wr/PycharmProjects/pythonProject/image/focused_image.jpg";
    //1.挖出照片内容
    QFile file(le_path);
    file.open(QIODevice::ReadOnly);
    QByteArray buf = file.readAll();
    //2.转成base64及urlcode
    QByteArray buf64 = buf.toBase64().toPercentEncoding();
    QByteArray body = "image="+buf64;
    //发送完整的一次识别请求
    httpmanager->post(myrequset, body);
}

void MainWindow::read_ack(QNetworkReply* r)
{
    //提取json格式的返回
    QByteArray buf = r->readAll();
    //qDebug() << buf;
    //提取json中的感兴趣的内容
    QJsonDocument myjson = QJsonDocument::fromJson(buf);
    QJsonObject node = myjson.object();
    QJsonObject arr = node.value("words_result").toObject();
    QString text = arr.value("number").toString();
    qDebug() << text;
    handlePlate(text);
}

void MainWindow::handlePlate(QString text){
    QSqlDatabase db= QSqlDatabase::database("DISK");
    QSqlQuery query(db);
    QString queryStr = QString("SELECT COUNT(*) FROM vehicle WHERE vehicle_id='%1'").arg(text);
    query.exec(queryStr);
    if (query.next()) {
        int countResult = query.value(0).toInt();
        if (countResult == 1) {
            QMessageBox::information(NULL, "车牌识别", "校内车，直接抬杆");
            qDebug() << "校内车，直接抬杆";
        } else {
            qDebug() << "校外车辆，弹出收费界面";
            emit chargeSignal(text);
        }
    } else {
        // 查询执行失败，获取错误信息
        QSqlError error = query.lastError();
        qDebug() << "MySQL Error: " << error.text();
    }
}


