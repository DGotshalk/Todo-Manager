#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Daily_items newitem;
    newitem.push_back("memes");
    newitem.push_back("i cant believe its not butter");
    ui->dailylistWidget->Load(newitem);
    QObject::connect(ui->editlistButton,SIGNAL(clicked()),
            this, SLOT(OpenEditDialogue()));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OpenEditDialogue()
{
    std::cout << "open dialogue" <<std::endl;
}
