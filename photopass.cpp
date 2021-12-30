#include "photopass.h"
#include "ui_photopass.h"
#include <QFileDialog>

photopass::photopass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::photopass)
{
    ui->setupUi(this);
    ui->lineEdit_1->setText(thepassname);
}

photopass::~photopass()
{
    delete ui;
}

void photopass::on_pushButton_clicked()
{
    QString PathName = QFileDialog::getExistingDirectory(this, tr("Open Directory"));
    PathName.replace("/","\\");
    thepassname=PathName;
    ui->lineEdit_1->setText(thepassname);
}
