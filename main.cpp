#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

#include "logindialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // DATABASE
    QString dbPath = QDir::currentPath() + "/hostelERP.db";
    qDebug() << "DB PATH =" << dbPath;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open())
    {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return -1;
    }

    QSqlQuery q;



    // STUDENTS
    q.exec(
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "roll TEXT UNIQUE,"
        "gender TEXT)"
        );

    // FEES
    q.exec(
        "CREATE TABLE IF NOT EXISTS fees ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "student_id TEXT,"
        "amount REAL,"
        "fee_type TEXT,"
        "fee_date TEXT)"
        );

    // COMPLAINTS
    q.exec(
        "CREATE TABLE IF NOT EXISTS complaints ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "student_id TEXT,"
        "type TEXT,"
        "description TEXT,"
        "date TEXT,"
        "status TEXT)"
        );

    // ✅ ROOMS TABLE (YAHI PE HONA CHAHIYE)
    q.exec(
        "CREATE TABLE rooms ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "room_no TEXT UNIQUE,"
        "room_type TEXT,"
        "capacity INTEGER,"
        "status TEXT)"
        );



    // LOGIN
    LoginDialog login;
    if (login.exec() != QDialog::Accepted)
        return 0;

    MainWindow w;
    w.show();

    return a.exec();
}
