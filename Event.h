#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

#include "Player.h"

class Event {
public:
    std::string name;
    std::string symbol;
    std::string percept = "";

    virtual ~Event() = default;

    virtual void Encounter(Player* player);
};

#endif // EVENT_H
