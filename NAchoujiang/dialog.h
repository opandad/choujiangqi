#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSound>
#include "windows.h"
#include "time.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *ui;

private slots:
    void on_start_clicked();

    void sound();

private:

};

#endif // DIALOG_H
