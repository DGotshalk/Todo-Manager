#ifndef DAILY_ITEMS_H
#define DAILY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>

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
signals:

public slots:

};

#endif // DAILY_ITEMS_H
