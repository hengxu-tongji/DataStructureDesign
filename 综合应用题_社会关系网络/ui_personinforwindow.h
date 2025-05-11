/********************************************************************************
** Form generated from reading UI file 'personinforwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINFORWINDOW_H
#define UI_PERSONINFORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonInforWindow
{
public:
    QPushButton *exit;
    QPushButton *back;
    QTextBrowser *testBrowser;

    void setupUi(QWidget *PersonInforWindow)
    {
        if (PersonInforWindow->objectName().isEmpty())
            PersonInforWindow->setObjectName(QString::fromUtf8("PersonInforWindow"));
        PersonInforWindow->resize(819, 476);
        exit = new QPushButton(PersonInforWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(670, 200, 61, 31));
        back = new QPushButton(PersonInforWindow);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(670, 150, 61, 31));
        testBrowser = new QTextBrowser(PersonInforWindow);
        testBrowser->setObjectName(QString::fromUtf8("testBrowser"));
        testBrowser->setGeometry(QRect(510, 260, 281, 191));

        retranslateUi(PersonInforWindow);

        QMetaObject::connectSlotsByName(PersonInforWindow);
    } // setupUi

    void retranslateUi(QWidget *PersonInforWindow)
    {
        PersonInforWindow->setWindowTitle(QCoreApplication::translate("PersonInforWindow", "Form", nullptr));
        exit->setText(QCoreApplication::translate("PersonInforWindow", "\351\200\200\345\207\272", nullptr));
        back->setText(QCoreApplication::translate("PersonInforWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonInforWindow: public Ui_PersonInforWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINFORWINDOW_H
