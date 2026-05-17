#include "room.h"

room::room(int _roomNumber, double _dailyRate)
    : roomNumber(_roomNumber), guestName(""), dailyRate(_dailyRate), isOccupied(false), extraExpenses(0) {};

void room :: checkIn(const string &_guestName)
{
    if(!isOccupied)
    {
        guestName = _guestName;

        isOccupied = true;
    }
    else
    {
        //room is occupied
    }
}

void room :: checkOut(int days)
{
    if(isOccupied)
    {
        int totalCost = (days * dailyRate) + extraExpenses;

        guestName = "";

        isOccupied = false;

        extraExpenses = 0;

    }

    else
    {
        //Room is already empty. Check out can not done.
    }
}

void room :: addExtraExpenses(double _extraExpenses)
{
    extraExpenses += _extraExpenses;
}

int room :: getRoomNumber()
{
    return roomNumber;
}

bool room :: isRoomOccupied()
{
    return isOccupied;
}

