#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
public:
    int health;
    int arrows;

    int xPos;
    int yPos;

    bool isAlive = true;
    bool hasGold = false;
    bool hasEscaped = false;
    bool isConfused = false;
    bool hasSlainWumpus = false;
    
    Player();
};

#endif // PLAYER_H
