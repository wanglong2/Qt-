#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QVector"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int num = 0;
    QString t[3][3] = {{"-","-","-"},{"-","-","-"},{"-","-","-"}};
    void whoWin(QString s);
    void init();
private slots:

    void on_toolButton_11_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_21_clicked();

    void on_toolButton_22_clicked();

    void on_toolButton_23_clicked();

    void on_toolButton_31_clicked();

    void on_toolButton_32_clicked();

    void on_toolButton_33_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
