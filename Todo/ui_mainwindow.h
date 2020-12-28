/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <end_items.h>
#include <weekly_items.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCalendarWidget *calendarWidget;
    QLabel *Dailylabel;
    Daily_items *dailylistWidget;
    QPushButton *addtodailylistButton;
    Weekly_items *weeklylistWidget;
    End_items *endlistWidget;
    QLabel *EndGoals;
    QLabel *WeeklyGoal;
    QPushButton *removefromdailylistButton;
    QPushButton *addtoweeklistButton;
    QPushButton *removefromweeklistButton;
    QPushButton *addtoendlistButton;
    QPushButton *removefromendlistButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1008, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 491, 261));	
		Dailylabel = new QLabel(centralWidget);
        Dailylabel->setObjectName(QString::fromUtf8("Dailylabel"));
        Dailylabel->setGeometry(QRect(190, 270, 91, 21));
        dailylistWidget = new Daily_items(centralWidget);
        dailylistWidget->setObjectName(QString::fromUtf8("dailylistWidget"));
        dailylistWidget->setGeometry(QRect(0, 290, 491, 161));
        addtodailylistButton = new QPushButton(centralWidget);
        addtodailylistButton->setObjectName(QString::fromUtf8("addtodailylistButton"));
        addtodailylistButton->setGeometry(QRect(140, 450, 96, 27));
        weeklylistWidget = new Weekly_items(centralWidget);
        weeklylistWidget->setObjectName(QString::fromUtf8("weeklylistWidget"));
        weeklylistWidget->setGeometry(QRect(520, 290, 491, 161));
        endlistWidget = new End_items(centralWidget);
        endlistWidget->setObjectName(QString::fromUtf8("endlistWidget"));
        endlistWidget->setGeometry(QRect(520, 40, 491, 191));
        EndGoals = new QLabel(centralWidget);
        EndGoals->setObjectName(QString::fromUtf8("EndGoals"));
        EndGoals->setGeometry(QRect(720, 20, 91, 21));
        WeeklyGoal = new QLabel(centralWidget);
        WeeklyGoal->setObjectName(QString::fromUtf8("WeeklyGoal"));
        WeeklyGoal->setGeometry(QRect(710, 270, 111, 21));
        removefromdailylistButton = new QPushButton(centralWidget);
        removefromdailylistButton->setObjectName(QString::fromUtf8("removefromdailylistButton"));
        removefromdailylistButton->setGeometry(QRect(250, 450, 96, 27));
        addtoweeklistButton = new QPushButton(centralWidget);
        addtoweeklistButton->setObjectName(QString::fromUtf8("addtoweeklistButton"));
        addtoweeklistButton->setGeometry(QRect(660, 450, 96, 27));
        removefromweeklistButton = new QPushButton(centralWidget);
        removefromweeklistButton->setObjectName(QString::fromUtf8("removefromweeklistButton"));
        removefromweeklistButton->setGeometry(QRect(770, 450, 96, 27));
        addtoendlistButton = new QPushButton(centralWidget);
        addtoendlistButton->setObjectName(QString::fromUtf8("addtoendlistButton"));
        addtoendlistButton->setGeometry(QRect(650, 230, 96, 27));
        removefromendlistButton = new QPushButton(centralWidget);
        removefromendlistButton->setObjectName(QString::fromUtf8("removefromendlistButton"));
        removefromendlistButton->setGeometry(QRect(760, 230, 96, 27));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Dailylabel->setText(QCoreApplication::translate("MainWindow", "Daily Tasks", nullptr));
        addtodailylistButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        EndGoals->setText(QCoreApplication::translate("MainWindow", "Final Goals", nullptr));
        WeeklyGoal->setText(QCoreApplication::translate("MainWindow", "Weekly Goals", nullptr));
        removefromdailylistButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        addtoweeklistButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removefromweeklistButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        addtoendlistButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removefromendlistButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
