#ifndef DAILY_ITEMS_H
#define DAILY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>

class Daily_items : public QListWidget
{
    QListWidget* mylist;
    Q_OBJECT
public:
    explicit Daily_items(QListWidget *parent = nullptr): mylist{parent} {}
    void push_back(QString detail);
    bool check_repeat(QString name);
    bool isempty();
signals:

public slots:

};

#endif // DAILY_ITEMS_H
