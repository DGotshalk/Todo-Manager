#include "weekly_items.h"
#include <algorithm>
#include <QCheckBox>
bool Weekly_items::isempty(){
    if (this->count() == 0){
        return true;
    }
    return false;
};

bool Weekly_items::check_repeat(QString name){
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

void Weekly_items::push_back(QString details){
    if (check_repeat(details)){
        QListWidgetItem* newitem = new QListWidgetItem(details);
        this->addItem(newitem);
        newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDragEnabled});
        newitem->setCheckState(Qt::Unchecked);
    }
};


void Weekly_items::Load(Weekly_items &list){
    this->clear();
    cur_parent = &list;
    int total = list.count();
    for (int i =0; i < total; ++i){
        this->addItem(list.takeItem(0));
    }
};

void Weekly_items::Remove_Selected(QList<QListWidgetItem*> selecteditems){
    for (auto item: selecteditems){
       int row = this->row(item);
       delete this->takeItem(row);
    }
};

void Weekly_items::Date_Selected(const QDate &date){
    if (date  == cur_date){
        return;
    }
    else {			//need extra logic for deciding weeks
        //write out the data in the field
        QDateTime old_day(cur_date);
        old_day.setTimeSpec(Qt::UTC);


        cur_date = date;
        QDateTime current_day(date);
        current_day.setTimeSpec(Qt::UTC);

    }
};

std::vector<std::pair<std::string,bool>> Weekly_items::format_data_for_csv(){
//iterate through items in the current list
//put them in to a std::vector<std::pair<std::string,bool>> vector;
//return that vector
};
