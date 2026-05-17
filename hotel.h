#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include <vector>

class Hotel
{
private:
    static Hotel *instance;     //Declaration
    vector <Room> rooms;

    Hotel();        //Private constructor for Singleton pattern

public:
    static Hotel *getInstance();

    Room *findRoom(int _roomNumber);

    ~Hotel();

};

#endif // HOTEL_H
