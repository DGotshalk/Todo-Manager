#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daily_items.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Daily_items ItemList(ui->daily_items);
}
MainWindow::~MainWindow()
{
    delete ui;
}

