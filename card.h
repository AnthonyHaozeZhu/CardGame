#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include "photopass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Card; }
QT_END_NAMESPACE

class Card : public QMainWindow
{
    Q_OBJECT

public:
    Card(QWidget *parent = nullptr);
    ~Card();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_01_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_03_clicked();

    void on_pushButton_04_clicked();

    void on_pushButton_05_clicked();

    void on_pushButton_06_clicked();

    void on_pushButton_07_clicked();

    void on_pushButton_08_clicked();

    void on_pushButton_09_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::Card *ui;
    photopass *p=new photopass;
};
#endif // CARD_H
