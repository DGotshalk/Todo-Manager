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
private:
    Ui::MainWindow *ui;
    Daily_items *current_day;
};

#endif // MAINWINDOW_H
