#ifndef SINGLE_H
#define SINGLE_H

#include <QDialog>

namespace Ui {
class Single;
}

class Single : public QDialog
{
    Q_OBJECT

public:
    explicit Single(QWidget *parent = nullptr);
    ~Single();

private:
    Ui::Single *ui;
};

#endif // SINGLE_H
