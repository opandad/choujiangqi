#include "dialog.h"
#include "ui_dialog.h"
#include "handle.h"


Dialog::Tips(QWidget *tip) :
    QDialog(tip),
    tipswindow(new Ui::Tips)
{
    tipswindow->setupUi(this);
}


Dialog::~Tips()
{
    delete tipswindow;
}
