#include "extrabuttondialog.h"
#include "ui_extrabuttondialog.h"

#include "hotel.h"
#include "room.h"

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

        if(room != nullptr && room->isRoomOccupied())
        {
            room->addExtraExpenses(ui->lineEditExtras->text().toInt());
            accept();
        }

        else if(!room->isRoomOccupied())
        {
            QMessageBox::critical(nullptr, "Error", "Room is empty!");
        }
    }
}


void ExtraButtonDialog::on_pushButtonCancel_clicked()
{
    reject();
}

