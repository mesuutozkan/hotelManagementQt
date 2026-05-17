#ifndef CHECKINDIALOG_H
#define CHECKINDIALOG_H

#include <QDialog>

namespace Ui {
class CheckInDialog;
}

class CheckInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInDialog(QWidget *parent = nullptr);
    ~CheckInDialog();

private slots:
    void on_pushButtonOkay_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::CheckInDialog *ui;
};

#endif // CHECKINDIALOG_H
