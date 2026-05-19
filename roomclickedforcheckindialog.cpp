#include "roomclickedforcheckindialog.h"
#include "ui_roomclickedforcheckindialog.h"

#include "room.h"

RoomClickedForCheckInDialog::RoomClickedForCheckInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomClickedForCheckInDialog)
{
    ui->setupUi(this);

    CheckInDialog* parentDialog = dynamic_cast <CheckInDialog*> (parent);

    parentDialogPtr = parentDialog;

    int roomNumberText = parentDialog->getChoosenRoomNumber();

    QString setRoomNumberText = QString :: number(roomNumberText);

    ui->labelRoomNumber->setText(setRoomNumberText);

}

RoomClickedForCheckInDialog::~RoomClickedForCheckInDialog()
{
    delete ui;
}

void RoomClickedForCheckInDialog::on_pushButtonOkay_clicked()
{
    if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit->text().trimmed().isEmpty())
    {
        parentDialogPtr->setTypedCustomerName(ui->lineEdit->text());

        accept();

    }
    else
    {
        //do nothing

    }

}


void RoomClickedForCheckInDialog::on_pushButtonCancel_clicked()
{
    reject();

}

