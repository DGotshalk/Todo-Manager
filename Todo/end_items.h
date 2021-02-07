#ifndef END_ITEMS_H
#define END_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include "csvHandler.h"
#include <utility>

class End_items : public QListWidget
{
    const End_items* cur_parent;
    Q_OBJECT
    csvHandler history;
	std::vector<std::pair<QString,bool>> format_data_for_csv();
	QListWidgetItem *previousSelection = NULL;
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
	void Item_Edited();
	void listItemClicked(QListWidgetItem *item);
};

#endif // END_ITEMS_H
