#ifndef VIEWROOM_H
#define VIEWROOM_H

#include <QDialog>

namespace Ui {
class ViewRoom;
}

class ViewRoom : public QDialog
{
    Q_OBJECT

public:
    explicit ViewRoom(QWidget *parent = nullptr);
    ~ViewRoom();

private:
    Ui::ViewRoom *ui;
    void loadRooms();
};

#endif // VIEWROOM_H
