#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "daily_items.h"
#include "weekly_items.h"
#include "end_items.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: 
    void AddItemDaily();
    void RemoveItemDaily();
    void AddItemWeekly();
    void RemoveItemWeekly();
    void AddItemEnd();
    void RemoveItemEnd();
    void Selected_Date(const QDate &date);
//	void ItemSelection(QListWidgetItem *item);
	void ItemClickedLogic(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
    Daily_items *current_day;
    Weekly_items *current_week;
    void Daily_items_Connections();
};

#endif // MAINWINDOW_H
