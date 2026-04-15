#include "addcomplaint.h"
#include "ui_addcomplaint.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

AddComplaint::AddComplaint(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddComplaint)
{
    ui->setupUi(this);
}

AddComplaint::~AddComplaint()
{
    delete ui;
}

void AddComplaint::on_pushButtonSave_clicked()
{
    QString studentId   = ui->lineEditStudentID->text().trimmed();
    QString type        = ui->comboBoxType->currentText();
    QString description = ui->textEditDescription->toPlainText().trimmed();
    QString date        = ui->dateEditComplaint->date().toString("yyyy-MM-dd");
    QString status      = "Pending";

    // 🔴 STRONG VALIDATION
    if (studentId.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Student ID cannot be empty");
        ui->lineEditStudentID->setFocus();
        return;
    }

    if (description.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Description cannot be empty");
        ui->textEditDescription->setFocus();
        return;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO complaints "
        "(student_id, type, description, date, status) "
        "VALUES (?, ?, ?, ?, ?)"
        );

    query.addBindValue(studentId);
    query.addBindValue(type);
    query.addBindValue(description);
    query.addBindValue(date);
    query.addBindValue(status);

    if (!query.exec())
    {
        QMessageBox::critical(this, "DB Error", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Complaint saved successfully");
    close();
}


void AddComplaint::on_pushButtonCancel_clicked()
{
    close();
}
