#include "daily_items.h"
#include <algorithm>

bool Daily_items::isempty(){
    if (mylist.size() == 0){
        return true;
    }
    return false;
};

bool Daily_items::check_repeat(QString name){
    for (int i = 0; i < mylist.size(); ++i){
        if (mylist[i] == name){
            return false;
        }
    }
        return true;
};

void Daily_items::push_back(QString details){
    if (check_repeat(details)&& isempty()){
        mylist.push_back(details);
        widgetlist->addItem(details);
    }
};
