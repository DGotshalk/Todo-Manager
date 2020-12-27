#ifndef DAILY_ITEMS_H
#define DAILY_ITEMS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QString>
#include <iostream>
#include <QDate>
#include "csvHandler.h"
#include <utility>
#include <algorithm>
#include <QCheckBox>
#include <QCoreApplication>
class Daily_items : public QListWidget
{
    const Daily_items* cur_parent;

    QDate cur_date;
    Q_OBJECT
    csvHandler history;
	   std::vector<std::pair<QString,bool>> format_data_for_csv();
	bool isempty();
	bool check_repeat(QString name);
	void Load(std::vector<std::pair<QString,bool>> list);
	QString QDate_To_Day();

	public:
		explicit Daily_items(QWidget *parent = nullptr): QListWidget(parent), history("daily.csv") {}
		QDate getdate(){ return cur_date;}
		void push_back(QString detail);
		void Date_Selected(const QDate & date);
		void Remove_Selected(QList<QListWidgetItem*> selecteditems);
		void Start_Date(const QDate & date);

signals:

public slots:

};

#endif // DAILY_ITEMS_H
