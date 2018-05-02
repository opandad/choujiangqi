#include "dialog.h"
#include "ui_dialog.h"
#include "handle.h"
HANDLE adadadad_;
DWORD _adadadad;
QSound *startsound = new QSound("../NAchoujiang/start.wav");
int flag, startmusic = 2;

DWORD WINAPI adadadad(LPVOID Wparam)
{
    int startnum = returnobject() -> num -> text().toInt();

    srand(time(0));

    int x;

    std::random_device rd;

    std::mt19937 gen(rd());

    while(flag == 1)
    {
        std::uniform_int_distribution<> dis(1, startnum);

        x = dis(gen);

        QString out = QString::number(x, 10);

        returnobject() -> result -> display(x);

        Sleep(20 + returnobject() -> sleep -> text().toInt());
    }

    return 0;
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_start_clicked()
{
    int num = returnobject() -> num -> text().toInt();

    if(num > 0 && num < 100000 && flag == 0)
    {
            startmusic = 1;

            sound();

            flag = 1;

            ui -> start -> setText("STOP");

            adadadad_ = CreateThread(0, 0, adadadad, 0, 0, &_adadadad);
    }

    else if(flag == 1)
    {
        flag = 2;

        startmusic = 0;

        ui -> start -> setText("重置显示");

        sound();
    }

    else if(flag == 2)
    {
        returnobject() -> result -> display(0);

        flag = 0;

        ui -> start -> setText("START");
    }


   else
   {
        QMessageBox::about(this, tr("错误信息"), tr("抽奖人数必须是大于0，小于100000的正整数，否则开始抽奖"));
   }
}

void Dialog::sound()
{
    if(startmusic == 1)
    {
        startsound -> play();

        startmusic = 2;
    }

    else if(startmusic == 0)
    {
        startsound -> stop();

        startmusic = 2;
    }
}
