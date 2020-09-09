#include "daily_items.h"
#include <algorithm>
#include <QCheckBox>
bool Daily_items::isempty(){
    if (this->count() == 0){
        return true;
    }
    return false;
};

bool Daily_items::check_repeat(QString name){
    if(isempty()){
        return true;
    }
    else{
    for (int i = 0; i < this->count(); ++i){
        if (this->item(i)->text() == name){
            return false;
        }
    }
        return true;
    }
};

void Daily_items::push_back(QString details){
    if (check_repeat(details)){
        QListWidgetItem* newitem = new QListWidgetItem(details);
        this->addItem(newitem);
        newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable});
        newitem->setCheckState(Qt::Unchecked);
    }
};


void Daily_items::Load(Daily_items &list){
    this->clear();
    cur_parent = &list;
    int total = list.count();
    for (int i =0; i < total; ++i){
        this->addItem(list.takeItem(0));
    }
}

