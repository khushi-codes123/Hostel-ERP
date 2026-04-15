#include "viewroom.h"
#include "ui_viewroom.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>

ViewRoom::ViewRoom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewRoom)
{
    ui->setupUi(this);
    loadRooms();
}

ViewRoom::~ViewRoom()
{
    delete ui;
}

void ViewRoom::loadRooms()
{
    ui->tableWidgetRooms->setRowCount(0);

    QSqlQuery query;
    if (!query.exec("SELECT id, room_no, room_type, capacity, status FROM rooms"))
    {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next())
    {
        ui->tableWidgetRooms->insertRow(row);

        ui->tableWidgetRooms->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidgetRooms->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidgetRooms->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidgetRooms->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidgetRooms->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));

        row++;
    }

    ui->tableWidgetRooms->resizeColumnsToContents();
}
