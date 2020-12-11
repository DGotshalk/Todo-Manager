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
        newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDragEnabled});
        newitem->setCheckState(Qt::Unchecked);
    }
};




// Change load to take a vector<pair<String,bool>>, and add that item as well as the check state to the list
void Daily_items::Load(std::vector<std::pair<std::string,bool>> list){
    this->clear();
    int total = list.size();
    for (int i =0; i < total; ++i){
        QString details(list[i].first.c_str());
        QListWidgetItem* newitem = new QListWidgetItem(details);
        this->addItem(newitem);
        newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDragEnabled});
        if (list[i].second){
            newitem->setCheckState(Qt::Checked);
        }
        else{
            newitem->setCheckState(Qt::Unchecked);
        }
    }
};



void Daily_items::Remove_Selected(QList<QListWidgetItem*> selecteditems){
    for (auto item: selecteditems){
       int row = this->row(item);
       delete this->takeItem(row);
    }
};

//if the date has changed, then you want it save the current data into the csv
// and then load the date is has changed to from the csv into the list using Load()
void Daily_items::Date_Selected(const QDate &date){
    if (date  == cur_date){
        return;
    }
    else {			//need extra logic for deciding weeks
        //write out the data in the field
        QDateTime old_day(cur_date);
        old_day.setTimeSpec(Qt::UTC);
        history.writeOut(old_day.toString().toStdString(),this->format_data_for_csv());

        cur_date = date;
        QDateTime current_day(date);
        current_day.setTimeSpec(Qt::UTC);
        std::cout << "loading new day" << std::endl;
        this->Load(history.readIn(current_day.toString().toStdString()));
    }
};

std::vector<std::pair<std::string,bool>> Daily_items::format_data_for_csv(){
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
