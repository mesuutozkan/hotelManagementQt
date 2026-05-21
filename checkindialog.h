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

    void on_pushButtonRoom102_clicked();

    void on_pushButtonRoom103_clicked();

    void on_pushButtonRoom104_clicked();

    void on_pushButtonRoom201_clicked();

    void on_pushButtonRoom202_clicked();

    void on_pushButtonRoom203_clicked();

    void on_pushButtonRoom301_clicked();

    void on_pushButtonRoom302_clicked();

private:
    Ui::CheckInDialog *ui;

    int choosenRoomNumber;

    QString typedCustomerName;

    void setStatusRoomButtons(int _roomNumber, QPushButton *pushButton);

};

#endif // CHECKINDIALOG_H
