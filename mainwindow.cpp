#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addstudent.h"
#include "viewstudents.h"
#include "addfee.h"
#include "viewfee.h"
#include "addcomplaint.h"
#include "viewcomplaint.h"
#include "logindialog.h"
#include "addroom.h"
#include "viewroom.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonAddFee, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonAddFee_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddStudent_clicked()
{
    AddStudent a(this);
    a.exec();
}

void MainWindow::on_pushButtonViewStudents_clicked()
{
    ViewStudents v(this);
    v.exec();
}

void MainWindow::on_pushButtonAddFee_clicked()
{
    AddFee f(this);
    f.exec();
}

void MainWindow::on_pushButtonViewFee_clicked()
{
    ViewFee v(this);
    v.exec();
}

void MainWindow::on_pushButtonAddComplaint_clicked()
{
    AddComplaint c(this);
    c.exec();
}

void MainWindow::on_pushButtonViewComplaint_clicked()
{
    ViewComplaint v(this);
    v.exec();
}

void MainWindow::on_pushButtonLogout_clicked()
{
    this->close();

    LoginDialog login;
    if (login.exec() == QDialog::Accepted)
        this->show();
}

void MainWindow::on_pushButtonAddRoom_clicked()
{
    AddRoom a(this);
    a.exec();
}

void MainWindow::on_pushButtonViewRoom_clicked()
{
    ViewRoom v(this);   // OR viewroom v(this) depending on class name
    v.exec();
}
