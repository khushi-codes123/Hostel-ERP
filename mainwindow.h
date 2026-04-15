#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButtonAddStudent_clicked();
    void on_pushButtonViewStudents_clicked();
    void on_pushButtonAddFee_clicked();
    void on_pushButtonViewFee_clicked();
    void on_pushButtonAddComplaint_clicked();
    void on_pushButtonViewComplaint_clicked();
    void on_pushButtonLogout_clicked();
    void on_pushButtonAddRoom_clicked();
    void on_pushButtonViewRoom_clicked();









private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
