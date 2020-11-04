#ifndef WEEKLY_ITEMS_H
#define WEEKLY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include <string>
#include "csvHandler.h"
#include <utility>

class Weekly_items : public QListWidget
{
    const Weekly_items* cur_parent;

    QDate cur_date;
    Q_OBJECT
    csvHandler history;
    void Date_Selected(const QDate & date);
    std::vector<std::pair<std::string,bool>> format_data_for_csv();

public:
    explicit Weekly_items(QWidget *parent = nullptr): QListWidget(parent), history("weekly.csv") {}
    void push_back(QString detail);
    bool check_repeat(QString name);
    bool isempty();
    QDate getdate(){ return cur_date;}
    void Load(Weekly_items& list);
    void Remove_Selected(QList<QListWidgetItem*> selecteditems);

signals:

public slots:

};

#endif // WEEKLY_ITEMS_H
