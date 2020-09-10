#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "daily_items.h"

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
    void Deselect(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
    Daily_items *current_day;
    void Daily_items_Connections();
};

#endif // MAINWINDOW_H
