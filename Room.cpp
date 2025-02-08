#include "Room.h"

Room::Room() {}

void Room::printRoom(bool easyMode) {
    if (easyMode) {
        std::cout << "|" << (event == nullptr ? " " : event->symbol) << (has_player ? "*" : " ") << " ";
    } else {
        std::cout << "| " << (has_player ? "*" : " ") << " ";
    }
    
}

bool Room::hasPlayer() {
    return has_player;
}

void Room::setPlayer(bool has_player) {
    this->has_player = has_player;
}

Event* Room::getEvent() {
    return event;
}

void Room::setEvent(Event* newEvent) {
    this->event = newEvent;
}

bool Room::hasEvent() {
    return event != nullptr;
}
