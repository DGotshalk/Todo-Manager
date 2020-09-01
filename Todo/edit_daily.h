#ifndef EDIT_DAILY_H
#define EDIT_DAILY_H

#include <QDialog>

namespace Ui {
class Edit_daily;
}

class Edit_daily : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_daily(QWidget *parent = nullptr);
	void Load_listwidget();
	void add_data();
	void remove_data();
	~Edit_daily();

private:
    Ui::Edit_daily *ui;
};

#endif // EDIT_DAILY_H
