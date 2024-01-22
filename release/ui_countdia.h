/********************************************************************************
** Form generated from reading UI file 'countdia.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDIA_H
#define UI_COUNTDIA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_countdia
{
public:
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_16;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_7;
    QWidget *widget_2;
    QTableWidget *counttable;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_5;

    void setupUi(QDialog *countdia)
    {
        if (countdia->objectName().isEmpty())
            countdia->setObjectName("countdia");
        countdia->resize(651, 425);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("face-smile")));
        countdia->setWindowIcon(icon);
        countdia->setStyleSheet(QString::fromUtf8("#countdia {border:1px solid  rgb(211, 211, 222); border-radius:7px}\n"
""));
        widget = new QWidget(countdia);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 611, 91));
        widget->setStyleSheet(QString::fromUtf8("#widget {border:1px solid rgb(211,211,211); border-radius:5px}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 61, 17));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 20, 71, 17));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 50, 71, 21));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(320, 50, 71, 21));
        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(400, 50, 141, 21));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 141, 21));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 50, 41, 21));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 20, 61, 17));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(400, 20, 71, 17));
        widget_2 = new QWidget(countdia);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 140, 611, 241));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {border:1px solid rgb(211,211,211); border-radius:5px}"));
        counttable = new QTableWidget(widget_2);
        counttable->setObjectName("counttable");
        counttable->setGeometry(QRect(10, 20, 591, 211));
        label_4 = new QLabel(countdia);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 130, 71, 17));
        label_6 = new QLabel(countdia);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 10, 71, 17));
        pushButton_5 = new QPushButton(countdia);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(540, 390, 89, 25));
        widget_2->raise();
        label_4->raise();
        label_6->raise();
        pushButton_5->raise();
        widget->raise();

        retranslateUi(countdia);

        QMetaObject::connectSlotsByName(countdia);
    } // setupUi

    void retranslateUi(QDialog *countdia)
    {
        countdia->setWindowTitle(QCoreApplication::translate("countdia", "\345\275\223\347\217\255\347\273\237\350\256\241", nullptr));
        label_2->setText(QCoreApplication::translate("countdia", "\346\223\215\344\275\234\345\221\230\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("countdia", "\345\262\227\344\272\255\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("countdia", "\346\216\245\347\217\255\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("countdia", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("countdia", "label_16", nullptr));
        label->setText(QCoreApplication::translate("countdia", "label", nullptr));
        pushButton->setText(QCoreApplication::translate("countdia", "\344\277\256\346\224\271", nullptr));
        label_5->setText(QCoreApplication::translate("countdia", "\346\261\252\347\235\277", nullptr));
        label_7->setText(QCoreApplication::translate("countdia", "\345\215\227\344\272\214\351\227\250", nullptr));
        label_4->setText(QCoreApplication::translate("countdia", "\347\273\237\350\256\241\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("countdia", "\345\275\223\347\217\255\347\273\237\350\256\241", nullptr));
        pushButton_5->setText(QCoreApplication::translate("countdia", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class countdia: public Ui_countdia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDIA_H
