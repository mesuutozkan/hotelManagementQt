#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include "checkindialog.h"
#include "hotel.h"
#include "room.h"

#include <QMessageBox>

CheckOutDialog::CheckOutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);

    CheckInDialog* parentDialog = dynamic_cast <CheckInDialog*> (parent);

    int roomNumber = parentDialog->getChoosenRoomNumber();

    QString setRoomNumberText = QString :: number(roomNumber);

    setCurrentRoomNumber(roomNumber);

    ui->labelRoomNumber->setText(setRoomNumberText);

      Hotel* hotel = Hotel::getInstance();

    Room *room = hotel->findRoom(roomNumber);

      ui->lineEditCustomerName->setText(QString::fromStdString(room->getGuestName()));
}

CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}

int CheckOutDialog::getTotalDays() const
{
    return totalDays;
}

void CheckOutDialog::setTotalDays(int newTotalDays)
{
    totalDays = newTotalDays;
}

void CheckOutDialog::on_pushButtonCalculateFee_clicked()
{
    if(ui->lineEditTotalDays->text().toInt() && ui->lineEditTotalDays->text().toInt() != 0)
    {
        Hotel* hotel = Hotel::getInstance();

        Room *room = hotel->findRoom(getCurrentRoomNumber());

        int totalFee = ((room->getDailyRate()) * (ui->lineEditTotalDays->text().toInt())) + room->getExtraExpenses();

        ui->lineEditTotalCost->setText(QString::number(totalFee));
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Invalid day !");
    }
}

int CheckOutDialog::getCurrentRoomNumber() const
{
    return currentRoomNumber;
}

void CheckOutDialog::setCurrentRoomNumber(int newCurrentRoomNumber)
{
    currentRoomNumber = newCurrentRoomNumber;
}


void CheckOutDialog::on_pushButtonCheckOut_clicked()
{
        if(ui->lineEditTotalCost->text().toInt() != 0)
        {
        setTotalDays(ui->lineEditTotalDays->text().toInt());

        accept();
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Calculate first !");
        }

}


void CheckOutDialog::on_pushButtonCancel_clicked()
{
    reject();
}

