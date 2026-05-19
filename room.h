#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room
{
private:
    int roomNumber;
    string guestName;
    double dailyRate;
    bool isOccupied;
    double extraExpenses;

public:
    Room(int _roomNumber, double _dailyRate);

    void checkIn(const string &_guestName);
    void checkOut(int days);
    void addExtraExpenses(double _extraExpenses);

    int getRoomNumber();
    bool isRoomOccupied();

};

#endif // ROOM_H
