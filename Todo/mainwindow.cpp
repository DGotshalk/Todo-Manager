#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    current_day = new Daily_items;
    current_day->push_back("memes");
    current_day->push_back("i cant believe its not butter");
    ui->dailylistWidget->Load(*current_day);
    QObject::connect(ui->addtolistButton,SIGNAL(clicked()),this, SLOT(AddItemDaily()));

    QObject::connect(ui->removefromlistButton,SIGNAL(clicked()),this, SLOT(RemoveItemDaily()));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AddItemDaily()
{

    ui->dailylistWidget->push_back("newitem");
    std::cout << "Add Daily item clicked" <<std::endl;
}

void MainWindow::RemoveItemDaily()
{
    std::cout << "Remove Daily item clicked" <<std::endl;
}
