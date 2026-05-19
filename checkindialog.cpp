#include "checkindialog.h"
#include "ui_checkindialog.h"

#include "room.h"
#include "hotel.h"
#include "roomclickedforcheckindialog.h"

CheckInDialog::CheckInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckInDialog)
{
    ui->setupUi(this);

    fillRoomButtonColors(101, ui->pushButtonRoom101);
    fillRoomButtonColors(102, ui->pushButtonRoom102);
    fillRoomButtonColors(103, ui->pushButtonRoom103);
    fillRoomButtonColors(104, ui->pushButtonRoom104);
    fillRoomButtonColors(201, ui->pushButtonRoom201);
    fillRoomButtonColors(202, ui->pushButtonRoom202);
    fillRoomButtonColors(203, ui->pushButtonRoom203);
    fillRoomButtonColors(301, ui->pushButtonRoom301);
    fillRoomButtonColors(302, ui->pushButtonRoom302);

}

void CheckInDialog :: fillRoomButtonColors(int _roomNumber, QPushButton* pushButton)
{
    Hotel* hotel = Hotel::getInstance();
    Room *room = hotel->findRoom(_roomNumber);

    if(room->isRoomOccupied())
    {
        pushButton->setStyleSheet(
            "QPushButton {background-color: red;"
            "color: white;"
            "font-weight: bold;"
            "border-radius: 10 px;"
            "font-size: 18 px}"
            "QPushButton:hover {background-color: darkred;}"
            );

    }
    else
    {
        pushButton->setStyleSheet(
            "QPushButton {background-color: green;"
            "color: white;"
            "font-weight: bold;"
            "border-radius: 10 px;"
            "font-size: 18 px}"
            "QPushButton:hover {background-color: darkgreen;}"
            );

    }

}

CheckInDialog::~CheckInDialog()
{
    delete ui;
}

void CheckInDialog::on_pushButtonOkay_clicked()
{
    accept();
}

void CheckInDialog::on_pushButtonRoom101_clicked()
{
    setChoosenRoomNumber(101);

    Hotel* hotel = Hotel::getInstance();

    Room *room = hotel->findRoom(getChoosenRoomNumber());

    if(!room->isRoomOccupied())
    {

        RoomClickedForCheckInDialog *roomClickedForCheckInDialog = new RoomClickedForCheckInDialog(this);     //Form a RoomClickedCheckInDialog object

        auto ret = roomClickedForCheckInDialog->exec();       //Start CheckInDialog

        if(ret == QDialog :: Accepted)          //Control point
        {

            room->checkIn(getTypedCustomerName().toStdString());

            fillRoomButtonColors(101, ui->pushButtonRoom101);

            qDebug() << "Okay Clicked";

        }
        else
        {
            qDebug() << "Cancel Clicked";

        }
    }
}

QString CheckInDialog::getTypedCustomerName() const
{
    return typedCustomerName;
}

void CheckInDialog::setTypedCustomerName(const QString &newTypedCustomerName)
{
    typedCustomerName = newTypedCustomerName;
}

int CheckInDialog::getChoosenRoomNumber() const
{
    return choosenRoomNumber;
}

void CheckInDialog::setChoosenRoomNumber(int _choosenRoomNumber)
{
    choosenRoomNumber = _choosenRoomNumber;
}

