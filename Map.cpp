#include "Map.h"

Map::Map(int sizeX, int sizeY) {
    rooms = new Room*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        rooms[i] = new Room[sizeY];
    }

    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

Map::~Map() {
    for (int i = 0; i < sizeof(rooms) / sizeof(rooms[0]); i++) {
        delete[] rooms[i];
    }
    delete[] rooms;
}

void Map::printMap(bool easyMode) {
    
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
        for (int j = 0; j < sizeY; j++) {
            rooms[i][j].printRoom(easyMode);
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < sizeY; j++) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
}

Room* Map::getRoom(int x, int y) {
    return &rooms[x][y];
}
