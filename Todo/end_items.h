#ifndef END_ITEMS_H
#define END_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include <string>
#include "csvHandler.h"

class End_items : public QListWidget
{
    const End_items* cur_parent;
    Q_OBJECT
    csvHandler history;
    std::vector<std::pair<std::string,bool>> format_data_for_csv();

public:
    explicit End_items(QWidget *parent = nullptr): QListWidget(parent), history("end.csv") {
       //put the loading here, we dont need dates for end_items
    }
    void push_back(QString detail);
    bool check_repeat(QString name);
    bool isempty();
    void Load();
    void Remove_Selected(QList<QListWidgetItem*> selecteditems);

signals:

public slots:

};

#endif // END_ITEMS_H
