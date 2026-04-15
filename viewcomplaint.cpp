#include "viewcomplaint.h"
#include "ui_viewcomplaint.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>

ViewComplaint::ViewComplaint(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ViewComplaint)
{
    ui->setupUi(this);

    // Load complaints when dialog opens
    loadComplaints();
}

ViewComplaint::~ViewComplaint()
{
    delete ui;
}

void ViewComplaint::loadComplaints()
{
    // Prepare table
    ui->tableWidgetComplaints->clear();
    ui->tableWidgetComplaints->setRowCount(0);
    ui->tableWidgetComplaints->setColumnCount(6);

    ui->tableWidgetComplaints->setHorizontalHeaderLabels(
        {"ID", "Student ID", "Type", "Description", "Date", "Status"}
        );

    // Check database
    if (!QSqlDatabase::database().isOpen())
    {
        qDebug() << "❌ Database not open";
        return;
    }

    QSqlQuery query;
    if (!query.exec("SELECT id, student_id, type, description, date, status FROM complaints"))
    {
        qDebug() << "❌ Query failed:" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next())
    {
        ui->tableWidgetComplaints->insertRow(row);

        ui->tableWidgetComplaints->setItem(row, 0,
                                           new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidgetComplaints->setItem(row, 1,
                                           new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidgetComplaints->setItem(row, 2,
                                           new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidgetComplaints->setItem(row, 3,
                                           new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidgetComplaints->setItem(row, 4,
                                           new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidgetComplaints->setItem(row, 5,
                                           new QTableWidgetItem(query.value(5).toString()));

        row++;
    }

    // Auto resize columns
    ui->tableWidgetComplaints->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);
}
