/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <daily_items.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCalendarWidget *calendarWidget;
    QLabel *Dailylabel;
    Daily_items *dailylistWidget;
    QPushButton *addtolistButton;
    Daily_items *weeklylistWidget;
    Daily_items *endlistWidget;
    QLabel *EndGoals;
    QLabel *WeeklyGoal;
    QPushButton *removefromlistButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1142, 540);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 501, 301));
        Dailylabel = new QLabel(centralWidget);
        Dailylabel->setObjectName(QStringLiteral("Dailylabel"));
        Dailylabel->setGeometry(QRect(190, 310, 91, 21));
        dailylistWidget = new Daily_items(centralWidget);
        dailylistWidget->setObjectName(QStringLiteral("dailylistWidget"));
        dailylistWidget->setGeometry(QRect(0, 330, 491, 161));
        addtolistButton = new QPushButton(centralWidget);
        addtolistButton->setObjectName(QStringLiteral("addtolistButton"));
        addtolistButton->setGeometry(QRect(140, 490, 96, 27));
        weeklylistWidget = new Daily_items(centralWidget);
        weeklylistWidget->setObjectName(QStringLiteral("weeklylistWidget"));
        weeklylistWidget->setGeometry(QRect(550, 330, 491, 161));
        endlistWidget = new Daily_items(centralWidget);
        endlistWidget->setObjectName(QStringLiteral("endlistWidget"));
        endlistWidget->setGeometry(QRect(550, 50, 491, 221));
        EndGoals = new QLabel(centralWidget);
        EndGoals->setObjectName(QStringLiteral("EndGoals"));
        EndGoals->setGeometry(QRect(750, 30, 91, 21));
        WeeklyGoal = new QLabel(centralWidget);
        WeeklyGoal->setObjectName(QStringLiteral("WeeklyGoal"));
        WeeklyGoal->setGeometry(QRect(740, 310, 111, 21));
        removefromlistButton = new QPushButton(centralWidget);
        removefromlistButton->setObjectName(QStringLiteral("removefromlistButton"));
        removefromlistButton->setGeometry(QRect(250, 490, 96, 27));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Dailylabel->setText(QApplication::translate("MainWindow", "Daily Tasks", nullptr));
        addtolistButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        EndGoals->setText(QApplication::translate("MainWindow", "Final Goals", nullptr));
        WeeklyGoal->setText(QApplication::translate("MainWindow", "Weekly Goals", nullptr));
        removefromlistButton->setText(QApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
