//
// ui_order.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:18:47 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:18:48 2015 SOMASUNDRAM Barathan
//

#ifndef UI_ORDER_H
#define UI_ORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Order
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QSpinBox *spinBox;
    QLabel *label_4;
    QComboBox *comboBox_3;

    void setupUi(QDialog *Order)
    {
        if (Order->objectName().isEmpty())
            Order->setObjectName(QString::fromUtf8("Order"));
        Order->resize(275, 214);
        buttonBox = new QDialogButtonBox(Order);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 170, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Order);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        label_2 = new QLabel(Order);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 101, 16));
        label_3 = new QLabel(Order);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 40, 81, 16));
        comboBox_2 = new QComboBox(Order);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(160, 60, 71, 31));
        spinBox = new QSpinBox(Order);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(80, 120, 131, 31));
        spinBox->setMinimum(1);
        label_4 = new QLabel(Order);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 100, 81, 16));
        comboBox_3 = new QComboBox(Order);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 60, 121, 31));

        retranslateUi(Order);
        QObject::connect(buttonBox, SIGNAL(accepted()), Order, SLOT(valid()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Order, SLOT(cancel()));

        QMetaObject::connectSlotsByName(Order);
    } // setupUi

    void retranslateUi(QDialog *Order)
    {
        Order->setWindowTitle(QApplication::translate("Order", "Pizza Order", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Order", "New pizza order :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Order", "Pizza Name :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Order", "Pizza size :", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Order", "S", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "L", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "XL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "XXL", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Order", "Quantity :", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Order", "Regina", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "Margeritta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "Americaine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Order", "Fantasia", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Order: public Ui_Order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
