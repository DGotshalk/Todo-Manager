#include "edit_daily.h"
#include "ui_edit_daily.h"

Edit_daily::Edit_daily(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_daily)
{
    ui->setupUi(this);
}

Edit_daily::~Edit_daily()
{
    delete ui;
}
