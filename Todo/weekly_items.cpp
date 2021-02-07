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
		newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDropEnabled});
		newitem->setCheckState(Qt::Unchecked);
		this->addItem(newitem);
    }
};

QString Weekly_items::QDate_To_Week(){
	QString week = QString::number(cur_date.weekNumber());
	QString year = QString::number(cur_date.year());
	if (cur_date.weekNumber() < 10)
		return year+".0"+week;
	else 
		return year+"."+week;
}


void Weekly_items::Start_Date(const QDate &date){
   cur_date=date;
	this->Load(history.readIn(QDate_To_Week()));
}

// Change load to take a vector<pair<String,bool>>, and add that item as well as the check state to the list
void Weekly_items::Load(std::vector<std::pair<QString,bool>> list){
    this->clear();
    int total = list.size();
    for (int i =0; i < total; ++i){
		QString details(list[i].first);
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

void Weekly_items::Remove_Selected(QList<QListWidgetItem*> selecteditems){
    for (auto item: selecteditems){
       int row = this->row(item);
       delete this->takeItem(row);
    }
};

//if the date has changed, then you want it save the current data into the csv
// and then load the date is has changed to from the csv into the list using Load()
// change the format of the date here to be in weeks instead of the daaay
void Weekly_items::Date_Selected(const QDate &date){ 
	QString actual_date;	
	QString week = QString::number(date.weekNumber());
	QString year = QString::number(date.year());
	if (cur_date.weekNumber() < 10)
		 actual_date= year+".0"+week;
	else 
		actual_date = year+"."+week;
    
	if (actual_date  ==	QDate_To_Week() ){
        return;
    }
    else {			//need extra logic for deciding weeks
		history.writeOut(QDate_To_Week(),format_data_for_csv());

        cur_date = date;
		Load(history.readIn(QDate_To_Week()));
    }
};

std::vector<std::pair<QString,bool>> Weekly_items::format_data_for_csv(){
//iterate through items in the current list
//put them in to a std::vector<std::pair<QString,bool>> vector;
//return that vector
    int total = this->count();
	std::vector<std::pair<QString,bool>> listitems;
    for (int i=0; i < total; ++i){
        QString information = this->item(i)->text();
        bool checked;
        if (this->item(i)->checkState() == Qt::Checked){
            checked = true;
        }
        else{
            checked = false;
        }
		listitems.push_back({information,checked});
    }
    return listitems;
};

// SLOTS
void Weekly_items::Item_Edited(){
	history.writeOut(QDate_To_Week(),format_data_for_csv());
}

void Weekly_items::listItemClicked(QListWidgetItem *item){
	if ( previousSelection != NULL ) {
	  if ( item->text() == previousSelection->text() )  {
		previousSelection = NULL;
		this->clearSelection();
		this->clearFocus();
		return;
	  }
	}
	previousSelection = item;
}

void Weekly_items::mousePressEvent(QMouseEvent *event){
	if (this->QListWidget::itemAt(event->pos())){
		this->QListWidget::mousePressEvent(event);
		return;
	}
	else{
		this->clearSelection();
		this->clearFocus();
		return;
	}
}
