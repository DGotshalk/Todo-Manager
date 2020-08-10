#include "daily_items.h"
#include <algorithm>
#include <QCheckBox>
bool Daily_items::isempty(){
    if (mylist->count() == 0){
        return true;
    }
    return false;
};

bool Daily_items::check_repeat(QString name){
    for (int i = 0; i < mylist->count(); ++i){
        if (mylist->item(i)->text() == name){
            return false;
        }
    }
        return true;
};

void Daily_items::push_back(QString details){
    if (check_repeat(details)&& isempty()){
        QListWidgetItem* newitem = new QListWidgetItem;
        mylist->addItem(newitem);
        newitem->setFlags(Qt::ItemIsUserCheckable);
        mylist->setItemWidget(newitem, new QCheckBox(details));
    }
};
