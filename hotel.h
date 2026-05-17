#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include <vector>

class hotel
{
private:
    static hotel *instance;     //Declaration
    vector <room> rooms;

    hotel();        //Private constructor for Singleton pattern

public:
    static hotel *getInstance();

    room *findRoom(int _roomNumber);

    ~hotel();

};

#endif // HOTEL_H
