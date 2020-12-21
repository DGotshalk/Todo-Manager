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
    std::vector<std::pair<std::string,bool>> format_data_for_csv();
    bool check_repeat(QString name);
    bool isempty();
    void Load(std::vector<std::pair<std::string,bool>> list);
    std::string QDate_To_Week();

    public:
        explicit Weekly_items(QWidget *parent = nullptr): QListWidget(parent), history("weekly.csv") {}
        QDate getdate(){ return cur_date;}
        void push_back(QString detail);
        void Date_Selected(const QDate & date);
        void Remove_Selected(QList<QListWidgetItem*> selecteditems);
        void Start_Date(const QDate & date);

signals:

public slots:

};

#endif // WEEKLY_ITEMS_H
