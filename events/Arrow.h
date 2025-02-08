#ifndef ARROW_H
#define ARROW_H

#include "../Event.h"
#include "../Player.h"

class Arrow : public Event {
public:
    Arrow();
    
    void Encounter(Player* player);
};

#endif // ARROW_H
