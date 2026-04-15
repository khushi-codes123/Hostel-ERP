#ifndef ADDCOMPLAINT_H
#define ADDCOMPLAINT_H

#include <QDialog>

namespace Ui {
class AddComplaint;
}

class AddComplaint : public QDialog
{
    Q_OBJECT

public:
    explicit AddComplaint(QWidget *parent = nullptr);
    ~AddComplaint();

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::AddComplaint *ui;
};

#endif // ADDCOMPLAINT_H
