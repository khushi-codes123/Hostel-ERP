#include "viewstudents.h"
#include "ui_viewstudents.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "addstudent.h"
#include "ui_addstudent.h"

ViewStudents::ViewStudents(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewStudents)
{
    ui->setupUi(this);
    loadStudents();   // load data when window opens
}

ViewStudents::~ViewStudents()
{
    delete ui;
}
void ViewStudents::on_pushButtonDelete_clicked()
{
    int row = ui->tableWidgetStudents->currentRow();

    if(row < 0) {
        QMessageBox::warning(this, "Error", "Select a student");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm",
                                  "Are you sure you want to delete?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No)
        return;

    QString id = ui->tableWidgetStudents->item(row, 0)->text();

    QSqlQuery query;
    query.prepare("DELETE FROM students WHERE id = ?");
    query.addBindValue(id);

    if(query.exec()) {
        QMessageBox::information(this, "Success", "Deleted successfully");
        loadStudents();
    } else {
        QMessageBox::warning(this, "Error", "Delete failed");
    }
}
void ViewStudents::on_pushButtonEdit_clicked()
{
    int row = ui->tableWidgetStudents->currentRow();

    if(row < 0) {
        QMessageBox::warning(this, "Error", "Select a student");
        return;
    }

    QString id = ui->tableWidgetStudents->item(row, 0)->text();
    QString name = ui->tableWidgetStudents->item(row, 1)->text();
    QString roll = ui->tableWidgetStudents->item(row, 2)->text();
    QString gender = ui->tableWidgetStudents->item(row, 3)->text();

    AddStudent a(this);
    a.setData(id, name, roll, gender);
    a.exec();

    loadStudents();
}
void ViewStudents::loadStudents()
{
    ui->tableWidgetStudents->setRowCount(0);

    QSqlQuery query("SELECT * FROM students");

    int row = 0;

    while(query.next())
    {
        ui->tableWidgetStudents->insertRow(row);

        ui->tableWidgetStudents->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidgetStudents->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidgetStudents->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidgetStudents->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));

        row++;
    }

    // ✅ ERROR CHECK yahi hona chahiye
    if(query.lastError().isValid())
    {
        QMessageBox::critical(this, "Database Error",
                              query.lastError().text());
    }
}
