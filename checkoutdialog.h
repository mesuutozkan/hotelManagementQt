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

private:
    Ui::CheckOutDialog *ui;

    int totalDays;
};

#endif // CHECKOUTDIALOG_H
