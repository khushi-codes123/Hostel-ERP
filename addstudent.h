#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>

namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

    void setData(QString id, QString name, QString roll, QString gender);  // 👈 EDIT support

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::AddStudent *ui;
    QString studentId;   // 👈 used for UPDATE
};

#endif // ADDSTUDENT_H
