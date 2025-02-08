#ifndef BATS_H
#define BATS_H

#include "../Event.h"
#include "../Player.h"

class Bats : public Event {
public:
    Bats();
    
    void Encounter(Player* player);
};

#endif // BATS_H
