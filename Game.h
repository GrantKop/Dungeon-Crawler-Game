#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "events/Rope.h"
#include "events/Wumpus.h"
#include "events/Gold.h"
#include "events/Bats.h"
#include "events/BottomlessPit.h"
#include "events/Arrow.h"

class Game {

private:
    int sizeX;
    int sizeY;

    bool easyMode;

    Room* currentRoom;

    Map* map;
    Player* player;
    Wumpus* wumpus;

public:
    Game();

    ~Game();

    Room* getCurrentRoom();
    void setCurrentRoom(Room* room);

    void findEventlessRoom(Event* event);
    void setEvents();

    void checkPercepts();

    void checkRoomEvent();

    void playerMove(std::string direction);
    void shootArrow();

    void playerAction();

    void run();
    void printMap();

    bool getEasyMode();

};

#endif // GAME_H
