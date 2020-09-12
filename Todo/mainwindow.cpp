#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Daily_items_Connections();
    current_day = new Daily_items;
    current_day->push_back("memes");
    current_day->push_back("i cant believe its not butter");
    ui->dailylistWidget->Load(*current_day);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Daily_items_Connections(){
    //Buttons
    QObject::connect(ui->addtolistButton,SIGNAL(clicked()),this, SLOT(AddItemDaily()));
    QObject::connect(ui->removefromlistButton,SIGNAL(clicked()),this, SLOT(RemoveItemDaily()));
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
