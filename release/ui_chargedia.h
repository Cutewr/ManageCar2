/********************************************************************************
** Form generated from reading UI file 'chargedia.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEDIA_H
#define UI_CHARGEDIA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chargeDia
{
public:
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QLabel *label_11;
    QPushButton *pushButton;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label;
    QWidget *widget_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_13;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *chargeDia)
    {
        if (chargeDia->objectName().isEmpty())
            chargeDia->setObjectName("chargeDia");
        chargeDia->resize(415, 533);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-utilities")));
        chargeDia->setWindowIcon(icon);
        chargeDia->setStyleSheet(QString::fromUtf8("#chargeDia {border:1px solid rgb(211,211,211); border-radius:7px}"));
        widget = new QWidget(chargeDia);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 371, 381));
        widget->setStyleSheet(QString::fromUtf8("#widget {border:1px solid rgb(211,211,211); border-radius:5px}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 51, 17));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 50, 71, 17));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 80, 71, 17));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 110, 71, 17));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 140, 71, 17));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 170, 71, 17));
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 200, 71, 17));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 230, 71, 21));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(110, 230, 221, 25));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 260, 71, 21));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(110, 260, 221, 25));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 300, 71, 21));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 300, 41, 21));
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 330, 71, 21));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 330, 41, 21));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(110, 330, 121, 31));
        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(120, 16, 191, 31));
        label_15 = new QLabel(widget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(120, 50, 141, 21));
        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(120, 80, 141, 21));
        label_17 = new QLabel(widget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(120, 100, 221, 41));
        label_18 = new QLabel(widget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(120, 200, 141, 21));
        label_19 = new QLabel(widget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(120, 140, 141, 21));
        label_20 = new QLabel(widget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(120, 170, 141, 21));
        label_21 = new QLabel(widget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(110, 290, 161, 41));
        label = new QLabel(chargeDia);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 67, 20));
        widget_2 = new QWidget(chargeDia);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 420, 371, 51));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {border:1px solid rgb(211,211,211); border-radius:5px}"));
        checkBox = new QCheckBox(widget_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 20, 92, 21));
        checkBox_2 = new QCheckBox(widget_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(90, 20, 92, 21));
        label_13 = new QLabel(chargeDia);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 410, 67, 20));
        pushButton_3 = new QPushButton(chargeDia);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 490, 111, 25));
        pushButton_4 = new QPushButton(chargeDia);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(140, 490, 91, 25));
        pushButton_5 = new QPushButton(chargeDia);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(240, 490, 71, 25));
        pushButton_6 = new QPushButton(chargeDia);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(320, 490, 71, 25));

        retranslateUi(chargeDia);

        QMetaObject::connectSlotsByName(chargeDia);
    } // setupUi

    void retranslateUi(QDialog *chargeDia)
    {
        chargeDia->setWindowTitle(QCoreApplication::translate("chargeDia", "\345\201\234\350\275\246\346\224\266\350\264\271", nullptr));
        label_2->setText(QCoreApplication::translate("chargeDia", "\350\275\246\347\211\214\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("chargeDia", "\345\205\245\345\234\272\346\227\266\345\210\273\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("chargeDia", "\345\207\272\345\234\272\346\227\266\345\210\273\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("chargeDia", "\345\201\234\350\275\246\346\227\266\351\225\277\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("chargeDia", "\345\205\245\345\234\272\351\200\232\351\201\223\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("chargeDia", "\345\207\272\345\234\272\351\200\232\351\201\223\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("chargeDia", "\350\277\233\345\207\272\347\261\273\345\236\213\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("chargeDia", "\350\275\246\350\276\206\347\261\273\345\210\253\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("chargeDia", "\350\275\246\350\276\206\347\261\273\345\236\213\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("chargeDia", "\346\224\266\350\264\271\351\207\221\351\242\235\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("chargeDia", "\350\257\246\346\203\205", nullptr));
        label_12->setText(QCoreApplication::translate("chargeDia", "\344\274\230\346\203\240\345\210\270\347\240\201\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("chargeDia", "\350\257\246\346\203\205", nullptr));
        label_14->setText(QCoreApplication::translate("chargeDia", "\351\204\202A2311", nullptr));
        label_15->setText(QCoreApplication::translate("chargeDia", "TextLabel", nullptr));
        label_16->setText(QCoreApplication::translate("chargeDia", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("chargeDia", "2\345\260\217\346\227\26613\345\210\206\351\222\23714\347\247\222", nullptr));
        label_18->setText(QCoreApplication::translate("chargeDia", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("chargeDia", "\345\215\227\344\270\200\351\227\250", nullptr));
        label_20->setText(QCoreApplication::translate("chargeDia", "\345\215\227\344\272\214\351\227\250", nullptr));
        label_21->setText(QCoreApplication::translate("chargeDia", "6\345\205\203", nullptr));
        label->setText(QCoreApplication::translate("chargeDia", "\346\224\266\350\264\271\344\277\241\346\201\257", nullptr));
        checkBox->setText(QCoreApplication::translate("chargeDia", "\345\274\200\351\227\270", nullptr));
        checkBox_2->setText(QCoreApplication::translate("chargeDia", "\346\211\223\345\215\260", nullptr));
        label_13->setText(QCoreApplication::translate("chargeDia", "\345\205\266\344\273\226\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("chargeDia", "\344\277\256\346\224\271\350\275\246\347\211\214\345\217\267\346\265\213\350\257\225", nullptr));
        pushButton_4->setText(QCoreApplication::translate("chargeDia", "\350\257\255\351\237\263\346\217\220\347\244\272", nullptr));
        pushButton_5->setText(QCoreApplication::translate("chargeDia", "\346\224\266\350\264\271", nullptr));
        pushButton_6->setText(QCoreApplication::translate("chargeDia", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chargeDia: public Ui_chargeDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEDIA_H
