#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"
#include "weekly_items.h"

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
    ui->dailylistWidget->Load(*current_day);
    ui->weeklylistWidget->Load(*current_week);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Daily_items_Connections(){
    //Buttons
    QObject::connect(ui->addtodailylistButton,SIGNAL(clicked()),this, SLOT(AddItemDaily()));
    QObject::connect(ui->removefromdailylistButton,SIGNAL(clicked()),this, SLOT(RemoveItemDaily()));
    QObject::connect(ui->addtoweeklistButton,SIGNAL(clicked()),this, SLOT(AddItemWeekly()));
    QObject::connect(ui->removefromweeklistButton,SIGNAL(clicked()),this, SLOT(RemoveItemWeekly()));
    //Widgets Items
    //QObject::connect(ui->dailylistWidget, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT(Deselect(QListWidgetItem*)));
}


// not useful so far
void MainWindow::Deselect(QListWidgetItem *item){
    (item->isSelected())?item->setSelected(false):item->setSelected(true);
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
