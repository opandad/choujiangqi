#include "dialog.h"
#include "ui_dialog.h"
#include "handle.h"
HANDLE adadadad_;
DWORD _adadadad;

QSound *startsound = new QSound("../NAchoujiang/start.wav");
QSound *bgm = new QSound("../NAchoujiang/bgm.wav");
int flag, bgmControl = 1, music = 0;

DWORD WINAPI adadadad(LPVOID Wparam)
{
    ll startnum = returnobject() -> num -> text().toInt();

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
    bgm -> play();
    bgm -> setLoops(-1);
    startsound -> setLoops(-1);
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    bgm -> stop();
    startsound -> stop();
    delete ui;
}

void Dialog::on_start_clicked()
{
    ll startnum = returnobject() -> num -> text().toInt();

    if(startnum > 0 && startnum < 100000 && flag == 0)
    {
            flag = 1;

            ui -> start -> setText("STOP");

            adadadad_ = CreateThread(0, 0, adadadad, 0, 0, &_adadadad);
    }

    else if(flag == 1)
    {
        flag = 2;

        ui -> start -> setText("重置显示");
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

void Dialog::on_music_clicked()
{
    if(bgmControl == 1)
    {
        ui -> music -> setText("切换为抽奖音乐");

        bgm -> stop();

        startsound -> play();

        bgmControl = 2;
    }

    else if(bgmControl == 2)
    {
         ui -> music -> setText("切换为颁奖音乐");

         startsound -> stop();

         bgm -> play();

        bgmControl = 1;
    }
}

void Dialog::on_radioButton_clicked()
{
    if(music == 0)
    {
        ui -> music -> hide();

        bgm -> stop();

        startsound -> stop();

        music = 1;
    }

    else if(music == 1)
    {
        ui -> music -> show();

        bgm -> play();

        ui -> music -> setText("切换为颁奖音乐");

        bgmControl = 1;

        music = 0;
    }
}
