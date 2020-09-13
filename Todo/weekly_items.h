#ifndef WEEKLY_ITEMS_H
#define WEEKLY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include <string>
class Weekly_items : public QListWidget
{
    const Weekly_items* cur_parent;

    QDate date;
    Q_OBJECT

public:
    explicit Weekly_items(QWidget *parent = nullptr): QListWidget(parent) {}
    void push_back(QString detail);
    bool check_repeat(QString name);
    bool isempty();
    QDate getdate(){ return date;}
    void Load(Weekly_items& list);
    void Remove_Selected(QList<QListWidgetItem*> selecteditems);
signals:

public slots:

};

#endif // WEEKLY_ITEMS_H
