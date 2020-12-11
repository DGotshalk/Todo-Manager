#include "end_items.h"
#include <algorithm>
#include <QCheckBox>
bool End_items::isempty(){
    if (this->count() == 0){
        return true;
    }
    return false;
};

bool End_items::check_repeat(QString name){
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

void End_items::push_back(QString details){
    if (check_repeat(details)){
        QListWidgetItem* newitem = new QListWidgetItem(details);
        this->addItem(newitem);
        newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDragEnabled});
        newitem->setCheckState(Qt::Unchecked);
    }
};


void End_items::Load(End_items &list){
    this->clear();
    cur_parent = &list;
    int total = list.count();
    for (int i =0; i < total; ++i){
        this->addItem(list.takeItem(0));
    }
};

void End_items::Remove_Selected(QList<QListWidgetItem*> selecteditems){
    for (auto item: selecteditems){
       int row = this->row(item);
       delete this->takeItem(row);
    }
};


std::vector<std::pair<std::string,bool>> End_items::format_data_for_csv(){
//iterate through items in the current list
//put them in to a std::vector<std::pair<std::string,bool>> vector;
//return that vector
    int total = this->count();
    std::vector<std::pair<std::string,bool>> listitems;
    for (int i=0; i < total; ++i){
        QString information = this->item(i)->text();
        bool checked;
        if (this->item(i)->checkState() == Qt::Checked){
            checked = true;
        }
        else{
            checked = false;
        }
        listitems.push_back({information.toStdString(),checked});
    }
    return listitems;
};
