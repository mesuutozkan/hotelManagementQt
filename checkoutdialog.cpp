#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include "checkindialog.h"
#include "hotel.h"
#include "room.h"

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
    if(ui->lineEditTotalDays->text().toInt())
    {
        Hotel* hotel = Hotel::getInstance();

        Room *room = hotel->findRoom(getCurrentRoomNumber());

        int totalFee = ((room->getDailyRate()) * (ui->lineEditTotalDays->text().toInt())) + room->getExtraExpenses();

        ui->lineEditTotalCost->setText(QString::number(totalFee));
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
    setTotalDays(ui->lineEditTotalDays->text().toInt());

        accept();

}


void CheckOutDialog::on_pushButtonCancel_clicked()
{
    reject();
}

