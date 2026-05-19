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

    int getChoosenRoomNumber() const;
    void setChoosenRoomNumber(int _choosenRoomNumber);

    QString getTypedCustomerName() const;
    void setTypedCustomerName(const QString &newTypedCustomerName);

private slots:
    void on_pushButtonOkay_clicked();

    void fillRoomButtonColors(int _roomNumber, QPushButton* pushButton);

    void on_pushButtonRoom101_clicked();

private:
    Ui::CheckInDialog *ui;

    int choosenRoomNumber;
    QString typedCustomerName;
};

#endif // CHECKINDIALOG_H
