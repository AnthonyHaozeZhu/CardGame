#include "single.h"
#include "ui_single.h"
#include "card.h"
#include "card.cpp"

Single::Single(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Single)
{
    ui->setupUi(this);
}

Single::~Single()
{
    delete ui;
}
