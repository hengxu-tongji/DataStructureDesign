/********************************************************************************
** Form generated from reading UI file 'network.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_H
#define UI_NETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetWork
{
public:
    QTextBrowser *testBrowser;
    QPushButton *exit;
    QPushButton *back;
    QPushButton *tableOut;
    QPushButton *addNodeButton;
    QPushButton *DeInfo;

    void setupUi(QWidget *NetWork)
    {
        if (NetWork->objectName().isEmpty())
            NetWork->setObjectName(QString::fromUtf8("NetWork"));
        NetWork->resize(888, 483);
        testBrowser = new QTextBrowser(NetWork);
        testBrowser->setObjectName(QString::fromUtf8("testBrowser"));
        testBrowser->setGeometry(QRect(600, 270, 281, 181));
        exit = new QPushButton(NetWork);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(800, 130, 61, 31));
        back = new QPushButton(NetWork);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(800, 80, 61, 31));
        tableOut = new QPushButton(NetWork);
        tableOut->setObjectName(QString::fromUtf8("tableOut"));
        tableOut->setGeometry(QRect(610, 80, 171, 31));
        addNodeButton = new QPushButton(NetWork);
        addNodeButton->setObjectName(QString::fromUtf8("addNodeButton"));
        addNodeButton->setGeometry(QRect(610, 140, 171, 31));
        DeInfo = new QPushButton(NetWork);
        DeInfo->setObjectName(QString::fromUtf8("DeInfo"));
        DeInfo->setGeometry(QRect(610, 200, 171, 31));

        retranslateUi(NetWork);

        QMetaObject::connectSlotsByName(NetWork);
    } // setupUi

    void retranslateUi(QWidget *NetWork)
    {
        NetWork->setWindowTitle(QCoreApplication::translate("NetWork", "Form", nullptr));
        exit->setText(QCoreApplication::translate("NetWork", "\351\200\200\345\207\272", nullptr));
        back->setText(QCoreApplication::translate("NetWork", "\350\277\224\345\233\236", nullptr));
        tableOut->setText(QCoreApplication::translate("NetWork", "\345\233\276\344\277\241\346\201\257\350\276\223\345\207\272", nullptr));
        addNodeButton->setText(QCoreApplication::translate("NetWork", "\346\267\273\345\212\240\347\273\223\347\202\271", nullptr));
        DeInfo->setText(QCoreApplication::translate("NetWork", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetWork: public Ui_NetWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_H
