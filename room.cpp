#include "room.h"

Room::Room(int _roomNumber, double _dailyRate)
    : roomNumber(_roomNumber), guestName(""), dailyRate(_dailyRate), isOccupied(false), extraExpenses(0) {};

void Room :: checkIn(const string &_guestName)
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

void Room :: checkOut(int days)
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

void Room :: addExtraExpenses(double _extraExpenses)
{
    extraExpenses += _extraExpenses;
}

int Room :: getRoomNumber()
{
    return roomNumber;
}

bool Room :: isRoomOccupied()
{
    return isOccupied;
}

