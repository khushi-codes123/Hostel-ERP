#include "addstudent.h"
#include "ui_addstudent.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

AddStudent::AddStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStudent)
{
    ui->setupUi(this);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_pushButtonCancel_clicked()
{
    close();
}
void AddStudent::setData(QString id, QString name, QString roll, QString gender)
{
    studentId = id;

    ui->lineEditName->setText(name);
    ui->lineEditRoll->setText(roll);
    ui->comboBoxGender->setCurrentText(gender);
}

void AddStudent::on_pushButtonSave_clicked()
{
    QString name = ui->lineEditName->text().trimmed();
    QString roll = ui->lineEditRoll->text().trimmed();
    QString gender = ui->comboBoxGender->currentText().trimmed();

    if (name.isEmpty() || roll.isEmpty() || gender.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    QSqlQuery query;

    // Use positional placeholders to avoid parameter mismatch
    query.prepare("INSERT INTO students (name, roll, gender) VALUES (?, ?, ?)");

    query.addBindValue(name);
    query.addBindValue(roll);
    query.addBindValue(gender);

    if (!query.exec())
    {
        QMessageBox::critical(this,
                              "Database Error",
                              query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Student added successfully!");
    close();
}
