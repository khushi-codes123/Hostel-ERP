#include "addfee.h"
#include "ui_addfee.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

AddFee::AddFee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFee)
{
    ui->setupUi(this);
    setWindowTitle("Add Fee");
    ui->dateEditFee->setDate(QDate::currentDate());
}

AddFee::~AddFee()
{
    delete ui;
}

void AddFee::on_pushButtonCancelFee_clicked()
{
    close();
}

void AddFee::on_pushButtonSaveFee_clicked()
{
    QString studentID = ui->lineEditStudentID->text().trimmed();
    QString amount = ui->lineEditAmount->text().trimmed();
    QString feeType = ui->comboBoxFeeType->currentText();
    QString date = ui->dateEditFee->date().toString("yyyy-MM-dd");

    if(studentID.isEmpty() || amount.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO fees (student_id, amount, fee_type, fee_date) "
                  "VALUES (:sid, :amt, :type, :date)");

    query.bindValue(":sid", studentID);
    query.bindValue(":amt", amount.toDouble());
    query.bindValue(":type", feeType);
    query.bindValue(":date", date);

    if(query.exec()) {
        QMessageBox::information(this, "Success", "Fee added successfully");
        close();
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}
