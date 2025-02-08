#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

#include "Room.h"


class Map {
public:
    Room** rooms;

    int sizeX;
    int sizeY;
    
    Map(int sizeX, int sizeY);
    ~Map();

    void printMap(bool easyMode);

    Room* getRoom(int x, int y);
};

#endif // MAP_H
