#ifndef ADDFEE_H
#define ADDFEE_H

#include <QDialog>

namespace Ui {
class AddFee;
}

class AddFee : public QDialog
{
    Q_OBJECT

public:
    explicit AddFee(QWidget *parent = nullptr);
    ~AddFee();

private slots:
    void on_pushButtonSaveFee_clicked();
    void on_pushButtonCancelFee_clicked();

private:
    Ui::AddFee *ui;
};

#endif // ADDFEE_H
