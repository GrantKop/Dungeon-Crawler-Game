#include "Gold.h"

Gold::Gold() {
    name = "Gold";
    symbol = "G";
    percept = "You see a glimmer nearby.";
}

void Gold::Encounter(Player* player) {
    std::cout << "You have found the gold!" << std::endl;
    player->hasGold = true;
}
