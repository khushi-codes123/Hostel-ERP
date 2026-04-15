#ifndef VIEWFEE_H
#define VIEWFEE_H

#include <QDialog>

namespace Ui {
class ViewFee;
}

class ViewFee : public QDialog
{
    Q_OBJECT

public:
    explicit ViewFee(QWidget *parent = nullptr);
    ~ViewFee();

private:
    void loadFees();
    Ui::ViewFee *ui;
};

#endif // VIEWFEE_H
