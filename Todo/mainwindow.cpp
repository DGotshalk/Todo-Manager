#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"
#include "weekly_items.h"
#include "end_items.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Daily_items_Connections();
    current_day = new Daily_items;
    current_day->push_back("finish weekly list");
    current_week = new Weekly_items;
    current_week->push_back("finish Todo app");
    //ui->dailylistWidget->Load(*current_day);
    //ui->weeklylistWidget->Load(*current_week);
}
MainWindow::~MainWindow()
{
    delete ui;
}

// add the Date Selected functions from weekly and daily into the mix
// have to make it so that whenver an item is added, or removed, or edited
// in the end list, it gets written out to that list

void MainWindow::Daily_items_Connections(){
    //Buttons
    QObject::connect(ui->addtodailylistButton,SIGNAL(clicked()),this, SLOT(AddItemDaily()));
    QObject::connect(ui->removefromdailylistButton,SIGNAL(clicked()),this, SLOT(RemoveItemDaily()));
    QObject::connect(ui->addtoweeklistButton,SIGNAL(clicked()),this, SLOT(AddItemWeekly()));
    QObject::connect(ui->removefromweeklistButton,SIGNAL(clicked()),this, SLOT(RemoveItemWeekly()));
    QObject::connect(ui->addtoendlistButton,SIGNAL(clicked()),this, SLOT(AddItemEnd()));
    QObject::connect(ui->removefromendlistButton,SIGNAL(clicked()),this, SLOT(RemoveItemEnd()));
    //change the selected date function from being inside this class to being inside the other classes. I want to pass the info appropriatly
    QObject::connect(ui->calendarWidget,SIGNAL(clicked(const QDate&)),this,SLOT(Selected_Date(const QDate&)));

}



void MainWindow::AddItemDaily(){
    ui->dailylistWidget->push_back("new item");
    ui->dailylistWidget->editItem(ui->dailylistWidget->item(ui->dailylistWidget->count()-1));
}

void MainWindow::RemoveItemDaily(){
    ui->dailylistWidget->Remove_Selected(ui->dailylistWidget->selectedItems());

}

void MainWindow::AddItemWeekly(){
    ui->weeklylistWidget->push_back("new item");
    ui->weeklylistWidget->editItem(ui->weeklylistWidget->item(ui->weeklylistWidget->count()-1));
}

void MainWindow::RemoveItemWeekly(){
    ui->weeklylistWidget->Remove_Selected(ui->weeklylistWidget->selectedItems());
}

void MainWindow::AddItemEnd(){
    ui->endlistWidget->push_back("new item");
    ui->endlistWidget->editItem(ui->endlistWidget->item(ui->endlistWidget->count()-1));
}

void MainWindow::RemoveItemEnd(){
    ui->endlistWidget->Remove_Selected(ui->endlistWidget->selectedItems());
}

void MainWindow::Selected_Date(const QDate &date){
    /* used for getting the day of the year (365) and the week number (1-52)
    std::cout << date.toString().toStdString() << std::endl;
    std::cout << "day: " << date.dayOfYear() << std::endl;
    std::cout << "Week: " << date.weekNumber() << std::endl;
    */
    QDateTime current_day(date);
    if (date  == ui->dailylistWidget->getdate()){
        return;
    }
    else {			//need extra logic for deciding weeks
       // csvHandler.writeout(ui->dailylistWidget);
       // csvHandler.read(ui->dailylistWidget);
    }

    // can do this in the csv handler file
    current_day.setTimeSpec(Qt::UTC);
    std::cout << current_day.toString().toStdString() << std::endl;

}
