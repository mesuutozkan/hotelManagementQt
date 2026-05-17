#include "hotel.h"

hotel *hotel :: instance = nullptr;     //Initialization

hotel::hotel()
{
    //push_back: first object is formed then copied to the vector(rooms)
    room r1(101, 3000.0);       //1. floor (standard rooms)
    room r2(102, 3000.0);
    room r3(103, 3000.0);
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);

    //emplace_back: object directly be formed inside vector(rooms).
    rooms.emplace_back(201, 4000.0);        //2. floor (double rooms)
    rooms.emplace_back(202, 4000.0);
    rooms.emplace_back(203, 4000.0);

    rooms.emplace_back(301, 7000.0);        // 3. floor (suite rooms)
    rooms.emplace_back(302, 7000.0);
    rooms.emplace_back(303, 7000.0);

}

hotel* hotel :: getInstance()
{
    if(instance == nullptr)
        instance = new hotel();

    return instance;
}

room *hotel :: findRoom(int _roomNumber)
{
    for(auto &room : rooms)
    {
        if(room.getRoomNumber() == _roomNumber)
        {
            return &room;

        }

    }
    return nullptr;

}

hotel :: ~hotel()
{
    delete instance;
}