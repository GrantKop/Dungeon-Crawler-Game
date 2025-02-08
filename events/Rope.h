#ifndef ROPE_H
#define ROPE_H

#include <iostream>

#include "../Event.h"
#include "../Player.h"

class Rope : public Event {

public:
    Rope();

    void Encounter(Player* player);
};

#endif // ROPE_H
