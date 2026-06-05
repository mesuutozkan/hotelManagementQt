#include "room.h"

double Room::getDailyRate() const
{
    return dailyRate;
}

int Room::getExtraExpenses() const
{
    return extraExpenses;
}

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
        double totalCost = (days * dailyRate) + extraExpenses;

        guestName = "";

        isOccupied = false;

        extraExpenses = 0;

    }

    else
    {
        //Room is already empty. Check out can not done.
    }
}

void Room :: addExtraExpenses(int _extraExpenses)
{
    if(isOccupied)
    {
    extraExpenses += _extraExpenses;
    }
}

int Room :: getRoomNumber()
{
    return roomNumber;
}

bool Room :: isRoomOccupied()
{
    return isOccupied;
}

string Room::getGuestName() const
{
    return guestName;
}
