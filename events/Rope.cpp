#include "Rope.h"

Rope::Rope() {
    name = "Rope";
    symbol = "R";
    percept = "You see a rope hanging from the ceiling.";
}

void Rope::Encounter(Player* player) {

    if (!player->isAlive) return;

    if (!player->hasGold && !player->hasSlainWumpus) {
        std::cout << "You don't have any gold and the wumpus is still alive! You can't leave yet!" << std::endl;
        return;
    }
    else if (player->hasGold && !player->hasSlainWumpus) {
        std::cout << "You found the gold and can now climb out of the cave!" << std::endl;
        player->hasEscaped = true;
        return;
    } else if (player->hasSlainWumpus && !player->hasGold) {
        std::cout << "You killed the Wumpus and can now climb out of the cave!" << std::endl;
        player->hasEscaped = true;
        return;
    } else if (player->hasGold || player->hasSlainWumpus) {
        std::cout << "You killed the Wumpus and stole his gold! Now you can climb out of the cave!" << std::endl;
        player->hasEscaped = true;
        return;
    }
}
