#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Event.h"

class Room {

private:

    Event* event = nullptr;

    bool has_player = false;

public:
    
    Room();

    void printRoom(bool easyMode);

    bool hasPlayer();

    void setPlayer(bool has_player);

    Event* getEvent();

    void setEvent(Event* newEvent);

    bool hasEvent();
};

#endif // ROOM_H
