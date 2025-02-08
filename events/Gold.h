#ifndef GOLD_H
#define GOLD_H

#include <iostream>

#include "../Event.h"
#include "../Player.h"

class Gold : public Event {

public:
    Gold();

    void Encounter(Player* player);
};

#endif // GOLD_H
