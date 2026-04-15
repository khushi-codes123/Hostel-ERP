#include "addroom.h"
#include "ui_addroom.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

AddRoom::AddRoom(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddRoom)
{
    ui->setupUi(this);

    // Optional: default values
    ui->spinBoxCapacity->setMinimum(1);
    ui->spinBoxCapacity->setMaximum(10);

    // Room type items (ensure they exist)
    if (ui->comboBoxRoomType->count() == 0)
    {
        ui->comboBoxRoomType->addItem("Single");
        ui->comboBoxRoomType->addItem("Double");
        ui->comboBoxRoomType->addItem("Triple");
    }
}

AddRoom::~AddRoom()
{
    delete ui;
}

void AddRoom::on_pushButtonSave_clicked()
{
    QString roomNo = ui->lineEditRoomNo->text().trimmed();
    QString roomType = ui->comboBoxRoomType->currentText();
    int capacity = ui->spinBoxCapacity->value();
    QString status = ui->comboBoxStatus->currentText();

    if (roomNo.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Enter room number");
        return;
    }

    QSqlQuery query;

    query.prepare(
        "INSERT INTO rooms (room_no, room_type, capacity, status) "
        "VALUES (?, ?, ?, ?)"
        );

    query.addBindValue(roomNo);
    query.addBindValue(roomType);
    query.addBindValue(capacity);
    query.addBindValue(status);

    if (!query.exec())
    {
        QMessageBox::critical(this, "DB Error", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Room added successfully");
    close();
}


void AddRoom::on_pushButtonCancel_clicked()
{
    close();
}
