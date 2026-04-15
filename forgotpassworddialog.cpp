#include "forgotpassworddialog.h"
#include "ui_forgotpassworddialog.h"

#include <QSqlQuery>
#include <QMessageBox>

ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ForgotPasswordDialog)
{
    ui->setupUi(this);
}

ForgotPasswordDialog::~ForgotPasswordDialog()
{
    delete ui;
}

void ForgotPasswordDialog::on_pushButtonCancel_clicked()
{
    close();
}

void ForgotPasswordDialog::on_pushButtonReset_clicked()
{
    QString username = ui->lineEditUsername->text().trimmed();
    QString newPassword = ui->lineEditNewPassword->text().trimmed();

    if (username.isEmpty() || newPassword.isEmpty())
    {
        QMessageBox::warning(this, "Error", "All fields required");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE users SET password=? WHERE username=?");
    query.addBindValue(newPassword);
    query.addBindValue(username);

    if (query.exec() && query.numRowsAffected() > 0)
    {
        QMessageBox::information(this, "Success", "Password updated");
        accept();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Username not found");
    }
}
