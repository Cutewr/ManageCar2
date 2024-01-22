/********************************************************************************
** Form generated from reading UI file 'chargedetail.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEDETAIL_H
#define UI_CHARGEDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_chargeDetail
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *chargeDetail)
    {
        if (chargeDetail->objectName().isEmpty())
            chargeDetail->setObjectName("chargeDetail");
        chargeDetail->resize(292, 305);
        textBrowser = new QTextBrowser(chargeDetail);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 271, 231));
        pushButton = new QPushButton(chargeDetail);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 250, 111, 31));
        label = new QLabel(chargeDetail);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 151, 21));
        label->setStyleSheet(QString::fromUtf8("font: 500 14pt \"aakar\";"));
        label_2 = new QLabel(chargeDetail);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 51, 151, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 500 14pt \"aakar\";"));
        label_3 = new QLabel(chargeDetail);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 72, 151, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 500 14pt \"aakar\";"));
        label_4 = new QLabel(chargeDetail);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 110, 151, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 500 14pt \"aakar\";"));

        retranslateUi(chargeDetail);

        QMetaObject::connectSlotsByName(chargeDetail);
    } // setupUi

    void retranslateUi(QDialog *chargeDetail)
    {
        chargeDetail->setWindowTitle(QCoreApplication::translate("chargeDetail", "\346\224\266\350\264\271\350\257\246\346\203\205", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("chargeDetail", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\345\201\234\350\275\246\346\227\266\351\227\264\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\345\216\237\344\273\267\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\344\274\230\346\203\240\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\346\234\200\347\273\210\344\273\267\346\240\274\357\274\232</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("chargeDetail", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("chargeDetail", "3\346\227\26623\345\210\206\351\222\2370\347\247\222", nullptr));
        label_2->setText(QCoreApplication::translate("chargeDetail", "9\345\205\203", nullptr));
        label_3->setText(QCoreApplication::translate("chargeDetail", "\346\227\240", nullptr));
        label_4->setText(QCoreApplication::translate("chargeDetail", "95\345\205\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chargeDetail: public Ui_chargeDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEDETAIL_H
