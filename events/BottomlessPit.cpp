#include "BottomlessPit.h"

BottomlessPit::BottomlessPit() {
    name = "Bottomless Pit";
    symbol = 'P';
    percept = "You feel a breeze nearby.";
}

void BottomlessPit::Encounter(Player* player) {

    int seed = time(NULL);

    srand(seed);

    int random = rand() % 2;

    if (random == 0) {
        std::cout << "You have fallen into a bottomless pit! You have died!" << std::endl;
        player->isAlive = false;
    } else {
        std::cout << "You narrowly avoid falling into a bottomless pit! Phew." << std::endl;
    }
}
