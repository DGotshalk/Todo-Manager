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
    QObject::connect(ui->dailylistWidget, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(Deselect(QListWidgetItem*)));
}



void MainWindow::Deselect(QListWidgetItem *item){
    (item->isSelected())?item->setSelected(false):item->setSelected(true);
}
void MainWindow::AddItemDaily(){
    ui->dailylistWidget->push_back("newitem");
    std::cout << "Add Daily item clicked" <<std::endl;
}

void MainWindow::RemoveItemDaily(){
    std::cout << "Remove Daily item clicked" <<std::endl;
}
