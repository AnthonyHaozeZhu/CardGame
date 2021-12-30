#include "card.h"
#include "ui_card.h"
#include <QPainter>
#include "photopass.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDir>
#include <QProcess>
#include <QVector>
#include <QTextCursor>
#include <QFileDialog>
#include <QLabel>

class thecardnum
{
public:
    int card_num;
    bool ischoose=false;
};
thecardnum cardclass[300];
QVector<int>vec;//容器
int picturenum;//文件个数
Card::Card(QWidget *parent): QMainWindow(parent), ui(new Ui::Card)
{
    ui->setupUi(this);
    this->setGeometry(QRect(110,0,1200,800));//设置幕布的大小
    for(int i=0;i<300;i++)
    {
            cardclass[i].card_num=i;
    }
    for(int i=0;i<300;i++)
    {
        vec.push_back(i);//初始化容器
    }
    QDir *dir=new QDir(":/images/测试实况足球所用文件夹");
    QStringList filter;
    QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
    int count=fileInfo->count();
    picturenum=count-2;
}

Card::~Card()
{
    delete ui;
}

void Card::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //画游戏的背景
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::gray);//设置填充颜色
    painter.drawRect(0,0,1200,800);
    painter.drawPixmap(0,0,1200,800,QPixmap(":/images/timg.jpeg"));
    //painter.drawLine()
}

void Card::on_pushButton_1_clicked()//点击设置图片路径后的操作
{
    p =new photopass;
    p->show();
}

void Card::on_pushButton_2_clicked()//点击洗牌后的操作
{
    QMessageBox::information(NULL,"洗牌成功","洗牌已成功");
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}

int Drawmode=1;//设置抽奖模式，1为单抽，2为十连抽，默认为1

void Card::on_radioButton_1_clicked()
{
    Drawmode=1;
}

void Card::on_radioButton_2_clicked()
{
    Drawmode=2;
}


void Card::on_pushButton_01_clicked()
{
    //判断Drawmode的值决定是单抽还是十连抽
    if(Drawmode==1)
    {
        //int card;
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        //QMessageBox msg;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        //msg.setText(show);
        //msg.exec();
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        //QMessageBox msg;
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
            //Temp=Temp+temp[i]+" ";
        }
        //msg.setText(Temp);
        //msg.exec();
    }
    //算法设置，弹出对话框显示抽奖结果
    ui->pushButton_01->hide();
}


void Card::on_pushButton_02_clicked()
{
    //判断Drawmode的值决定是单抽还是十连抽
    if(Drawmode==1)
    {
        //int card;
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        //QMessageBox msg;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        //msg.setText(show);
        //msg.exec();
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        //QMessageBox msg;
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
            //Temp=Temp+temp[i]+" ";
        }
        //msg.setText(Temp);
        //msg.exec();
    }
    //算法设置，弹出对话框显示抽奖结果
    ui->pushButton_02->hide();
}

void Card::on_pushButton_03_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_03->hide();
}

void Card::on_pushButton_04_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_04->hide();
}

void Card::on_pushButton_05_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_05->hide();
}

void Card::on_pushButton_06_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_06->hide();
}


void Card::on_pushButton_07_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_07->hide();
}

void Card::on_pushButton_08_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_08->hide();
}

void Card::on_pushButton_09_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_09->hide();
}

void Card::on_pushButton_10_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_10->hide();
}

void Card::on_pushButton_11_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_11->hide();
}

void Card::on_pushButton_12_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_12->hide();
}

void Card::on_pushButton_13_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_13->hide();
}

void Card::on_pushButton_14_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_14->hide();
}

void Card::on_pushButton_15_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_15->hide();
}

void Card::on_pushButton_16_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_16->hide();
}

void Card::on_pushButton_17_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_17->hide();
}

void Card::on_pushButton_18_clicked()
{
    if(Drawmode==1)
    {
     l1:int a=0,b=picturenum-1;
        srand((unsigned)time(NULL));
        int n=a+rand()%(b-a+1);
        if(cardclass[n].ischoose==true)
        {
            goto l1;
        }
        cardclass[n].ischoose=true;
        QString temp = QString::number(n, 10);      // s == "63"
        QString show = ":/images/测试实况足球所用文件夹/"+temp+".jpg";
        QImage *image=new QImage(show);
        QDialog *dialog =new QDialog();
        QLabel *label=new QLabel();
        label->setParent(dialog);
        label->setPixmap(QPixmap(show));
        label->setGeometry(0,0,708,993);
        label->setPixmap(QPixmap::fromImage(*image));
        label->show();
        dialog->exec();
    }
    if(Drawmode==2)
    {
        int cardall[10];
        int a=0,b=picturenum-1;
        for(int i=0;i<10;i++)
        {
         l2:int n=a+rand()%(b-a+1);
            if(cardclass[n].ischoose==true)
            {
                goto l2;
            }
            cardall[i]=n;
            cardclass[n].ischoose=true;
        }
        for(int i=0;i<10;i++)
        {
            for(int q=i+1;q<10;q++)
            {
                if(cardall[i]>cardall[q])
                {
                    int t=cardall[i];
                    cardall[i]=cardall[q];
                    cardall[q]=t;
                }
            }
        }
        QString temp[10],Temp;
        for(int i=0;i<10;i++)
        {
            temp[i] = QString::number(cardall[i], 10);
            QString show = ":/images/测试实况足球所用文件夹/"+temp[i]+".jpg";
            QImage *image=new QImage(show);
            QDialog *dialog =new QDialog();
            QLabel *label=new QLabel();
            label->setParent(dialog);
            label->setPixmap(QPixmap(show));
            label->setGeometry(0,0,708,993);
            label->setPixmap(QPixmap::fromImage(*image));
            label->show();
            dialog->exec();
        }
    }
    ui->pushButton_18->hide();
}
