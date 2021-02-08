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
		newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDropEnabled});
		newitem->setCheckState(Qt::Unchecked);
		this->addItem(newitem);
    }
};


void End_items::Load(){
	std::vector<std::pair<QString,bool>> list = history.readIn("0");
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

/* Instead of a Date_Selected function I need a function that writes to the csv whenever
 * Ive made a change to the items in the end list (updated an item, added an item, removed an item)
 * the load funciton above should load all the items currently in the list
 * and ill have to call it on startup
 * note: the date for the end list is 0
 */

void End_items::Remove_Selected(QList<QListWidgetItem*> selecteditems){
    for (auto item: selecteditems){
       int row = this->row(item);
	   if(previousSelection == item){
		  previousSelection = NULL;
	   }
	   delete this->takeItem(row);
    }
};


std::vector<std::pair<QString,bool>> End_items::format_data_for_csv(){
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
void End_items::Item_Edited(){
	history.writeOut("0",format_data_for_csv());
}
void End_items::listItemClicked(QListWidgetItem *item){
	if ( previousSelection != NULL ) {
	  if ( item == previousSelection)  {
		previousSelection = NULL;
		this->clearSelection();
		this->clearFocus();
		return;
	  }
	}
	previousSelection = item;
}

void End_items::mousePressEvent(QMouseEvent *event){
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
