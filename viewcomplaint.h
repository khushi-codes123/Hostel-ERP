#ifndef VIEWCOMPLAINT_H
#define VIEWCOMPLAINT_H

#include <QDialog>

namespace Ui {
class ViewComplaint;
}

class ViewComplaint : public QDialog
{
    Q_OBJECT

public:
    explicit ViewComplaint(QWidget *parent = nullptr);
    ~ViewComplaint();

private:
    Ui::ViewComplaint *ui;

    void loadComplaints();
};

#endif // VIEWCOMPLAINT_H
