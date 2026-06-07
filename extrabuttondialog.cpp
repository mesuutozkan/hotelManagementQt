#include "extrabuttondialog.h"
#include "ui_extrabuttondialog.h"

#include "hotel.h"
#include "room.h"

//Use QMessageBox class for error message pop-ups.

#include <QMessageBox>

ExtraButtonDialog::ExtraButtonDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExtraButtonDialog)
{
    ui->setupUi(this);
}

ExtraButtonDialog::~ExtraButtonDialog()
{
    delete ui;
}

void ExtraButtonDialog::on_pushButtonOkay_clicked()
{
    if(ui->lineEditExtras->text().toInt() && ui->lineEditRoomNumber->text().toInt())
    {
        Hotel* hotel = Hotel::getInstance();

        Room *room = hotel->findRoom(ui->lineEditRoomNumber->text().toInt());

        if(room != nullptr)
        {
            if(room->isRoomOccupied())
            {
            room->addExtraExpenses(ui->lineEditExtras->text().toInt());
            accept();
            }
            else
            {
                QMessageBox::critical(nullptr, "Error", "Room is empty!");


            }
        }

        else
        {
            QMessageBox::critical(nullptr, "Error", "Invalid Room !\nCheck your room number and enter it again.");
        }
    }
}


void ExtraButtonDialog::on_pushButtonCancel_clicked()
{
    reject();
}

