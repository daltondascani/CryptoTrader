#ifndef SWAP_H
#define SWAP_H

#include <QDialog>

namespace Ui {
class swap;
}

class swap : public QDialog
{
    Q_OBJECT

public:
    explicit swap(QWidget *parent = nullptr);
    ~swap();

private:
    Ui::swap *ui;
};

#endif // SWAP_H
