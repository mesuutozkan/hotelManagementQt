#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>

namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDialog(QWidget *parent = nullptr);
    ~CheckOutDialog();

    int getTotalDays() const;
    void setTotalDays(int newTotalDays);

    int getCurrentRoomNumber() const;
    void setCurrentRoomNumber(int newCurrentRoomNumber);

private slots:
    void on_pushButtonCalculateFee_clicked();

    void on_pushButtonCheckOut_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::CheckOutDialog *ui;

    int totalDays;
    int currentRoomNumber;
};

#endif // CHECKOUTDIALOG_H
