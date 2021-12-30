#ifndef PHOTOPASS_H
#define PHOTOPASS_H

#include <QDialog>
#include <QString>

static QString thepassname;

namespace Ui {
class photopass;
}

class photopass : public QDialog
{
    Q_OBJECT

public:
    explicit photopass(QWidget *parent = nullptr);
    ~photopass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::photopass *ui;
};

#endif // PHOTOPASS_H
