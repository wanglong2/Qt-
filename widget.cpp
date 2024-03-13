#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QFont"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置字体 颜色
    QFont font("Arial",30);

    ui->toolButton_11->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_11->setFont(font);

    ui->toolButton_12->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_12->setFont(font);

    ui->toolButton_13->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_13->setFont(font);

    ui->toolButton_21->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_21->setFont(font);

    ui->toolButton_22->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_22->setFont(font);

    ui->toolButton_23->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_23->setFont(font);

    ui->toolButton_31->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_31->setFont(font);

    ui->toolButton_32->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_32->setFont(font);

    ui->toolButton_33->setStyleSheet("QToolButton{color:red}");
    ui->toolButton_33->setFont(font);
    //初始化
    init();

}

Widget::~Widget()
{
    delete ui;
}
//判断谁会赢
void Widget::whoWin(QString s)
{
    // 如果某行 某列 或 斜对角 内容相同，则获胜
    if((t[0][0] == s&& t[0][1] == s && t[0][2] == s) || (t[1][0] == s&&t[1][1]==s&&t[1][2]==s) || (t[2][0] == s && t[2][1]==s && t[2][2]==s) || (t[0][0] == s&&t[1][0]==s&&t[2][0]==s)  || (t[0][1] == s&&t[1][1]==s&&t[2][1]==s) || (t[0][2] == s&&t[1][2]==s&&t[2][2]==s) || (t[0][0] == s && t[1][1]==s && t[2][2]==s)  || (t[0][2] == s&&t[1][1]==s&&t[2][0]==s))
    {
        QMessageBox::information(this,"游戏结束",QString("%1胜利").arg(s));
        init();
    }
    // 初始化 时 三行三列 二维数组 初始内容为 -，如果都不是-，则平局 然后初始化
    if(t[0][0] != "-" && t[0][1] != "-"&& t[0][2] != "-"&& t[1][0] != "-"&&t[1][1] != "-" && t[1][2] != "-"  && t[2][0] != "-"&&t[2][1] != "-" && t[2][2] != "-")
    {
        QMessageBox::information(this,"游戏结束","平局");
        init();
    }

}

//初始化 将toolbutton设置为可以点击 ，将t（二维数组）设置为- ，将toolbutton内容置空
void Widget::init()
{
    num = 0;
    for(int i = 0; i < 3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            t[i][j] = "-";
        }
    }
    ui->toolButton_11->setEnabled(true);
    ui->toolButton_12->setEnabled(true);
    ui->toolButton_13->setEnabled(true);
    ui->toolButton_21->setEnabled(true);
    ui->toolButton_22->setEnabled(true);
    ui->toolButton_23->setEnabled(true);
    ui->toolButton_31->setEnabled(true);
    ui->toolButton_32->setEnabled(true);
    ui->toolButton_33->setEnabled(true);

    ui->toolButton_11->setText("");
    ui->toolButton_12->setText("");
    ui->toolButton_13->setText("");
    ui->toolButton_21->setText("");
    ui->toolButton_22->setText("");
    ui->toolButton_23->setText("");
    ui->toolButton_31->setText("");
    ui->toolButton_32->setText("");
    ui->toolButton_33->setText("");
}



//9个toolbutton按钮 按照点击的次序， 如果单击的次数为偶数，则toolbutton设置为O,否则设置为x;
//点击一次，num加一次，然后判断是否符合胜利的条件。 点击完后设置toolbutton为不可点击。
void Widget::on_toolButton_11_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_11->setText("o");
        t[0][0] = "o";
        num++;
        whoWin("o");
    }
    else
    {
        num++;
        t[0][0] = "x";
        ui->toolButton_11->setText("x");
        whoWin("x");
    }
    ui->toolButton_11->setEnabled(false);
}


void Widget::on_toolButton_12_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_12->setText("o");
        t[0][1] = "o";
        num++;
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_12->setText("x");
        t[0][1] = "x";
        whoWin("x");
    }
    ui->toolButton_12->setEnabled(false);
}


void Widget::on_toolButton_13_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_13->setText("o");
        num++;
        t[0][2] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_13->setText("x");
        t[0][2] = "x";
        whoWin("x");
    }
    ui->toolButton_13->setEnabled(false);
}


void Widget::on_toolButton_21_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_21->setText("o");
        num++;
        t[1][0] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_21->setText("x");
        t[1][0] = "x";
        whoWin("x");
    }
    ui->toolButton_21->setEnabled(false);
}


void Widget::on_toolButton_22_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_22->setText("o");
        num++;
        t[1][1] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_22->setText("x");
        t[1][1] = "x";
        whoWin("x");
    }
    ui->toolButton_22->setEnabled(false);
}


void Widget::on_toolButton_23_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_23->setText("o");
        num++;
        t[1][2] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_23->setText("x");
        t[1][2] = "x";
        whoWin("x");
    }
    ui->toolButton_23->setEnabled(false);
}


void Widget::on_toolButton_31_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_31->setText("o");
        num++;
        t[2][0] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_31->setText("x");
        t[2][0] =  "x";
        whoWin("x");
    }
    ui->toolButton_31->setEnabled(false);
}


void Widget::on_toolButton_32_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_32->setText("o");
        num++;
        t[2][1] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_32->setText("x");
        t[2][1] = "x";
        whoWin("x");
    }
    ui->toolButton_32->setEnabled(false);
}


void Widget::on_toolButton_33_clicked()
{
    if(num % 2 == 0)
    {

        ui->toolButton_33->setText("o");
        num++;
        t[2][2] = "o";
        whoWin("o");
    }
    else
    {
        num++;
        ui->toolButton_33->setText("x");
        t[2][2] = "x";
        whoWin("x");
    }
    ui->toolButton_33->setEnabled(false);
}

//按钮功能，初始化

void Widget::on_pushButton_clicked()
{
    init();
}

