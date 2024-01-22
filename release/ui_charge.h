/********************************************************************************
** Form generated from reading UI file 'charge.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGE_H
#define UI_CHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_charge
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *charge)
    {
        if (charge->objectName().isEmpty())
            charge->setObjectName("charge");
        charge->resize(664, 431);
        pushButton = new QPushButton(charge);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 180, 89, 25));

        retranslateUi(charge);

        QMetaObject::connectSlotsByName(charge);
    } // setupUi

    void retranslateUi(QWidget *charge)
    {
        charge->setWindowTitle(QCoreApplication::translate("charge", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("charge", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class charge: public Ui_charge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGE_H
