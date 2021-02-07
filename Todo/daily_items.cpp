#include "daily_items.h"
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
		newitem->setFlags({Qt::ItemIsUserCheckable, Qt::ItemIsSelectable, Qt::ItemIsEditable, Qt::ItemIsEnabled, Qt::ItemIsDragEnabled, Qt::ItemIsDropEnabled});
		newitem->setCheckState(Qt::Unchecked);
		this->addItem(newitem);
    }
};

QString Daily_items::QDate_To_Day(){
	QString day = QString::number(cur_date.dayOfYear());
	QString year = QString::number(cur_date.year());
	if (cur_date.dayOfYear() < 10)
		return year +".0"+day;
	else
		return year+"."+day;
}


void Daily_items::Start_Date(const QDate &date){
	cur_date=date;	
	this->Load(history.readIn(QDate_To_Day()));
}

// Change load to take a vector<pair<String,bool>>, and add that item as well as the check state to the list
void Daily_items::Load(std::vector<std::pair<QString,bool>> list){
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
	else {
		history.writeOut(QDate_To_Day(),format_data_for_csv());
        cur_date = date; 

		Load(history.readIn(QDate_To_Day()));
    }
};


//iterate through items in the current list
//put them in to a std::vector<std::pair<std::string,bool>> vector;
//return that vector

/* NO LONGER NEED TO DO QSTRING CONVERSION
 */

std::vector<std::pair<QString,bool>> Daily_items::format_data_for_csv(){
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
void Daily_items::Item_Edited(){
	history.writeOut(QDate_To_Day(),format_data_for_csv());
}

void Daily_items::listItemClicked(QListWidgetItem *item){
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

void Daily_items::mousePressEvent(QMouseEvent *event){
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
