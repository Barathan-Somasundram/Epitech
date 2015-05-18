//
// ui_plazza.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:19:02 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:19:05 2015 SOMASUNDRAM Barathan
//

#ifndef UI_PLAZZA_H
#define UI_PLAZZA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plazza
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionNew_command;
    QAction *actionVersion;
    QAction *actionAbout_2;
    QWidget *centralWidget;
    QLabel *label;
    QFrame *line;
    QLabel *label_3;
    QLabel *kitchenName;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QListWidget *kitchenList;
    QListWidget *processingOrdersList;
    QListWidget *finishedOrdersList;
    QLabel *label_4;
    QTableWidget *ingredientsTable;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *frame;
    QMenuBar *menuBar;
    QMenu *menuPlazza;
    QMenu *menuNew_command;

    void setupUi(QMainWindow *Plazza)
    {
        if (Plazza->objectName().isEmpty())
            Plazza->setObjectName(QString::fromUtf8("Plazza"));
        Plazza->resize(630, 588);
        actionAbout = new QAction(Plazza);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQuit = new QAction(Plazza);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionNew_command = new QAction(Plazza);
        actionNew_command->setObjectName(QString::fromUtf8("actionNew_command"));
        actionNew_command->setEnabled(true);
        actionVersion = new QAction(Plazza);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        actionAbout_2 = new QAction(Plazza);
        actionAbout_2->setObjectName(QString::fromUtf8("actionAbout_2"));
        centralWidget = new QWidget(Plazza);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, 20, 20, 321));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 20, 111, 16));
        kitchenName = new QLabel(centralWidget);
        kitchenName->setObjectName(QString::fromUtf8("kitchenName"));
        kitchenName->setGeometry(QRect(310, 20, 271, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 60, 131, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(420, 60, 131, 16));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(200, 40, 791, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        kitchenList = new QListWidget(centralWidget);
        kitchenList->setObjectName(QString::fromUtf8("kitchenList"));
        kitchenList->setGeometry(QRect(10, 30, 161, 301));
        processingOrdersList = new QListWidget(centralWidget);
        processingOrdersList->setObjectName(QString::fromUtf8("processingOrdersList"));
        processingOrdersList->setGeometry(QRect(210, 80, 171, 251));
        finishedOrdersList = new QListWidget(centralWidget);
        finishedOrdersList->setObjectName(QString::fromUtf8("finishedOrdersList"));
        finishedOrdersList->setGeometry(QRect(420, 80, 171, 251));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 350, 131, 21));
        ingredientsTable = new QTableWidget(centralWidget);
        ingredientsTable->setObjectName(QString::fromUtf8("ingredientsTable"));
        ingredientsTable->setGeometry(QRect(10, 380, 161, 171));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(390, 50, 20, 291));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 340, 631, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(199, 379, 411, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Plazza->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Plazza);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 24));
        menuPlazza = new QMenu(menuBar);
        menuPlazza->setObjectName(QString::fromUtf8("menuPlazza"));
        menuNew_command = new QMenu(menuBar);
        menuNew_command->setObjectName(QString::fromUtf8("menuNew_command"));
        Plazza->setMenuBar(menuBar);

        menuBar->addAction(menuNew_command->menuAction());
        menuBar->addAction(menuPlazza->menuAction());
        menuPlazza->addAction(actionVersion);
        menuPlazza->addAction(actionAbout_2);
        menuPlazza->addSeparator();
        menuNew_command->addAction(actionNew_command);
        menuNew_command->addSeparator();
        menuNew_command->addAction(actionQuit);

        retranslateUi(Plazza);

        QMetaObject::connectSlotsByName(Plazza);
    } // setupUi

    void retranslateUi(QMainWindow *Plazza)
    {
        Plazza->setWindowTitle(QApplication::translate("Plazza", "Plazza", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Plazza", "About", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("Plazza", "Quit", 0, QApplication::UnicodeUTF8));
        actionNew_command->setText(QApplication::translate("Plazza", "New command", 0, QApplication::UnicodeUTF8));
        actionVersion->setText(QApplication::translate("Plazza", "version", 0, QApplication::UnicodeUTF8));
        actionAbout_2->setText(QApplication::translate("Plazza", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Plazza", "Kitchens :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Plazza", "Kitchen Name : ", 0, QApplication::UnicodeUTF8));
        kitchenName->setText(QApplication::translate("Plazza", "Undefined", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Plazza", "Processing orders :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Plazza", "Finished orders :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Plazza", "Ingredients :", 0, QApplication::UnicodeUTF8));
        menuPlazza->setTitle(QApplication::translate("Plazza", "About", 0, QApplication::UnicodeUTF8));
        menuNew_command->setTitle(QApplication::translate("Plazza", "Plazza", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Plazza: public Ui_Plazza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAZZA_H
