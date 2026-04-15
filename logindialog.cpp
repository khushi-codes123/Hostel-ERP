#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "forgotpassworddialog.h"




LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonCancel_clicked()
{
    close();
}

void LoginDialog::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text().trimmed();
    QString password = ui->lineEditPassword->text().trimmed();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Enter username and password");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username=? AND password=?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (query.exec() && query.next())
    {
        accept();   // LOGIN SUCCESS
    }
    else
    {
        QMessageBox::critical(this, "Login Failed", "Invalid credentials");
    }
}
void LoginDialog::on_pushButtonForgot_clicked()
{
    ForgotPasswordDialog f(this);
    f.exec();
}
