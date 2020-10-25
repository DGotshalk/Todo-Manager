#ifndef DAILY_ITEMS_H
#define DAILY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include <string>
class Daily_items : public QListWidget
{
    const Daily_items* cur_parent;

    QDate date;
    Q_OBJECT

public:
    explicit Daily_items(QWidget *parent = nullptr): QListWidget(parent) {}
    void push_back(QString detail);
    bool check_repeat(QString name);
    bool isempty();
    QDate getdate(){ return date;}
    void Load(Daily_items& list);
    void Remove_Selected(QList<QListWidgetItem*> selecteditems);
    std::string Dump_To_CSV();
signals:

public slots:

};

#endif // DAILY_ITEMS_H
