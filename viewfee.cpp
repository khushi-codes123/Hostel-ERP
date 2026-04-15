#include "viewfee.h"
#include "ui_viewfee.h"

#include <QSqlQuery>
#include <QTableWidgetItem>

ViewFee::ViewFee(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewFee)
{
    ui->setupUi(this);
    loadFees();
}

ViewFee::~ViewFee()
{
    delete ui;
}

void ViewFee::loadFees()
{
    ui->tableWidgetFees->setRowCount(0);

    QSqlQuery query("SELECT id, student_id, amount, fee_type, fee_date FROM fees");

    int row = 0;
    while (query.next())
    {
        ui->tableWidgetFees->insertRow(row);

        for (int col = 0; col < 5; col++)
        {
            ui->tableWidgetFees->setItem(
                row, col,
                new QTableWidgetItem(query.value(col).toString())
                );
        }
        row++;
    }
}
