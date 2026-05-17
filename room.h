#ifndef ROOM_H
#define ROOM_H

#include <iostream>

#include <string>

using namespace std;

class room
{
private:
    int roomNumber;
    string guestName;
    double dailyRate;
    bool isOccupied;
    double extraExpenses;

public:
    room(int _roomNumber, double _dailyRate);

    void checkIn(const string &_guestName);
    void checkOut(int days);
    void addExtraExpenses(double amount);

    int getRoomNumber();
    bool isRoomOccupied();

};

#endif // ROOM_H
