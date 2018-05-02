#include "dialog.h"
#include <QApplication>
#include "handle.h"
Ui::Dialog *s;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedSize(800, 600);
    w.setWindowFlags(Qt::WindowCloseButtonHint);
    s = w.ui;
    w.show();

    return a.exec();
}

Ui::Dialog *returnobject()
{
    return s;
}
