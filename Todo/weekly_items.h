#ifndef WEEKLY_ITEMS_H
#define WEEKLY_ITEMS_H

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
#include <QMouseEvent>

class Weekly_items : public QListWidget
	{
	private:
		const Weekly_items* cur_parent;
		QDate cur_date;
		Q_OBJECT
		csvHandler history;
		std::vector<std::pair<QString,bool>> format_data_for_csv();
		bool check_repeat(QString name);
		bool isempty();
		void Load(std::vector<std::pair<QString,bool>> list);
		QString QDate_To_Week();
		QListWidgetItem *previousSelection = NULL;
	
	public:
		explicit Weekly_items(QWidget *parent = nullptr): QListWidget(parent), history("weekly.csv") {}
		QDate getdate(){ return cur_date;}
		void push_back(QString detail);
		void Date_Selected(const QDate & date);
		void Remove_Selected(QList<QListWidgetItem*> selecteditems);
		void Start_Date(const QDate & date);

	signals:

	public slots:
		void Item_Edited();
		void listItemClicked(QListWidgetItem *item);
	protected:
		void mousePressEvent(QMouseEvent *event) override;
};

#endif // WEEKLY_ITEMS_H
