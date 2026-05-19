#include "hotel.h"

Hotel *Hotel :: instance = nullptr;     //Initialization

Hotel::Hotel()
{
    /*
    //push_back: firstly object is formed, then copied to the vector(rooms)
    room r1(101, 3000.0);       //1. floor (standard rooms)
    room r2(102, 3000.0);
    room r3(103, 3000.0);
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    */

    //emplace_back: object directly be formed inside vector(rooms). No copy proccess, arguments directly pass to vector.
    rooms.emplace_back(101, 2500.0);        //1. floor (single rooms)
    rooms.emplace_back(102, 2500.0);
    rooms.emplace_back(103, 2500.0);
    rooms.emplace_back(104, 2500.0);


    rooms.emplace_back(201, 4000.0);        //2. floor (double rooms)
    rooms.emplace_back(202, 4000.0);
    rooms.emplace_back(203, 4000.0);

    rooms.emplace_back(301, 7000.0);        // 3. floor (suite rooms)
    rooms.emplace_back(302, 7000.0);

}

Hotel* Hotel :: getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();

    return instance;
}

Room *Hotel :: findRoom(int _roomNumber)
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

Hotel :: ~Hotel()
{
    delete instance;
}