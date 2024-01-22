/********************************************************************************
** Form generated from reading UI file 'qhmaskwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHMASKWIDGET_H
#define UI_QHMASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qhmaskwidget
{
public:

    void setupUi(QWidget *qhmaskwidget)
    {
        if (qhmaskwidget->objectName().isEmpty())
            qhmaskwidget->setObjectName("qhmaskwidget");
        qhmaskwidget->resize(400, 300);

        retranslateUi(qhmaskwidget);

        QMetaObject::connectSlotsByName(qhmaskwidget);
    } // setupUi

    void retranslateUi(QWidget *qhmaskwidget)
    {
        qhmaskwidget->setWindowTitle(QCoreApplication::translate("qhmaskwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qhmaskwidget: public Ui_qhmaskwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHMASKWIDGET_H
