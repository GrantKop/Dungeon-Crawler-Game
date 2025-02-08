#include "Wumpus.h"

Wumpus::Wumpus() {
    name = "Wumpus";
    symbol = "W";
    percept = "The hairs stand up on the back of your neck.";
}

void Wumpus::Encounter(Player* player) {

    if (!player->hasSlainWumpus) {
        std::cout << "You have encountered the Wumpus and it has eaten you!" << std::endl;
        player->isAlive = false;
        player->health = 0;
    } else {
        std::cout << "The Wumpus is dead!" << std::endl;
    }
}
