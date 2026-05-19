#ifndef ROOMCLICKEDFORCHECKINDIALOG_H
#define ROOMCLICKEDFORCHECKINDIALOG_H

#include <QDialog>

#include "checkindialog.h"

namespace Ui {
class RoomClickedForCheckInDialog;
}

class RoomClickedForCheckInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomClickedForCheckInDialog(QWidget *parent = nullptr);
    ~RoomClickedForCheckInDialog();

private slots:
    void on_pushButtonOkay_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::RoomClickedForCheckInDialog *ui;
    CheckInDialog* parentDialogPtr;
};

#endif // ROOMCLICKEDFORCHECKINDIALOG_H
