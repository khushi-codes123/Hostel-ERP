#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H

#include <QDialog>

namespace Ui {
class ViewStudents;
}

class ViewStudents : public QDialog
{
    Q_OBJECT

public:
    explicit ViewStudents(QWidget *parent = nullptr);
    ~ViewStudents();

private slots:
    void on_pushButtonDelete_clicked();
    void on_pushButtonEdit_clicked();

private:
    Ui::ViewStudents *ui;
    void loadStudents();   // function to load data
};

#endif // VIEWSTUDENTS_H
