#ifndef WUMPUS_H
#define WUMPUS_H

#include "../Event.h"
#include "../Player.h"

class Wumpus : public Event {
public:
    Wumpus();

    void Encounter(Player* player);
};

#endif // WUMPUS_H
