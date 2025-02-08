#ifndef BOTTOMLESSPIT_H
#define BOTTOMLESSPIT_H

#include <iostream>
#include <stdlib.h>

#include "../Event.h"
#include "../Player.h"

class BottomlessPit : public Event {
public:
    BottomlessPit();
    
    void Encounter(Player* player);
};

#endif // BOTTOMLESSPIT_H
