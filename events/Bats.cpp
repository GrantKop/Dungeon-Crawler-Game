#include "Bats.h"

Bats::Bats() {
    name = "Bats";
    symbol = 'B';
    percept = "You hear screeching nearby!";
}

void Bats::Encounter(Player* player) {

    std::cout << "You have encountered a swarm of bats! They confuse you and randomize your next move!" << std::endl;

    player->isConfused = true;
}
