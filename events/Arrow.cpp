#include "Arrow.h"

Arrow::Arrow() {
    name = "Arrow";
    symbol = 'A';
    percept = "";
}

void Arrow::Encounter(Player* player) {
    player->arrows++;
    std::cout << "You have found an arrow!" << std::endl;
}
