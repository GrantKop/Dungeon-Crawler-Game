#include "Game.h"

Game::Game() {

    while (true) {
        std::cout << "Enter the size of the map (Cols): ";
        std::cin >> sizeX;
        std::cout << "Enter the size of the map (Rows): ";
        std::cin >> sizeY;

        if (sizeX < 4 || sizeY < 4) {
            std::cout << "The map size must be at least 4x4!" << std::endl;
        } else if (sizeX > 30 || sizeY > 30) {
            std::cout << "The map size must be at most 30x30!" << std::endl;
        } else {
            break;
        }
    }

    while (true) {
        std::string mode = "";
        std::cout << "Enter the game mode easy(1) / hard(2): ";
        std::cin >> mode;

        if (mode == "1") {
            easyMode = true;
            break;
        } else if (mode == "2") {
            easyMode = false;
            break;
        } else {
            std::cout << "Invalid mode!" << std::endl;
        }
    }

    system("clear");

    map = new Map(sizeX, sizeY);
    player = new Player();
}

Game::~Game() {
    delete map;
    delete player;
}

Room* Game::getCurrentRoom() {
    return currentRoom;
}

void Game::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Game::findEventlessRoom(Event* event) {

    int x = rand() % sizeX;
    int y = rand() % sizeY;

    while (map->getRoom(x, y)->getEvent() != nullptr) {
        x = rand() % sizeX;
        y = rand() % sizeY;
    }

    map->getRoom(x, y)->setEvent(event);
}

void Game::setEvents() {

    srand(time(NULL));

    int randomX, randomY = 0;

    randomX = rand() % sizeX;
    randomY = rand() % sizeY;

    Wumpus* wumpus = new Wumpus();
    Gold* gold = new Gold();
    Rope* rope = new Rope();
    Bats* bats = new Bats();
    BottomlessPit* pit = new BottomlessPit();
    Arrow* arrow = new Arrow();

    // Set the player's starting position
    currentRoom = map->getRoom(randomX, randomY);
    currentRoom->setPlayer(true);
    player->xPos = randomX;
    player->yPos = randomY;

    // Set the Rope's position
    map->getRoom(randomX, randomY)->setEvent(rope);

    // Set the Wumpus's position
    findEventlessRoom(wumpus);

    // Set the Gold's position
    findEventlessRoom(gold);

    // Set the Bats's position
    findEventlessRoom(bats);

    // Set the Bottomless Pits positions
    findEventlessRoom(pit);
    findEventlessRoom(pit);

    // Set the Arrows positions
    findEventlessRoom(arrow);
    findEventlessRoom(arrow);
    
    printMap();
}

// Check the 4 surrounding rooms if an event is present, and print the percept
void Game::checkPercepts() {

    int x = player->xPos;
    int y = player->yPos;

    if (x - 1 >= 0) {
        if (map->getRoom(x - 1, y)->hasEvent()) {
            std::cout << map->getRoom(x - 1, y)->getEvent()->percept << std::endl;
        }
    }

    if (x + 1 < sizeX) {
        if (map->getRoom(x + 1, y)->hasEvent()) {
            std::cout << map->getRoom(x + 1, y)->getEvent()->percept << std::endl;
        }
    }

    if (y - 1 >= 0) {
        if (map->getRoom(x, y - 1)->hasEvent()) {
            std::cout << map->getRoom(x, y - 1)->getEvent()->percept << std::endl;
        }
    }

    if (y + 1 < sizeY) {
        if (map->getRoom(x, y + 1)->hasEvent()) {
            std::cout << map->getRoom(x, y + 1)->getEvent()->percept << std::endl;
        }
    }

}

void Game::checkRoomEvent() {
    if (currentRoom->getEvent() != nullptr) {
        if (currentRoom->getEvent()->symbol == "W") {
            currentRoom->getEvent()->Encounter(player);
        } else if (currentRoom->getEvent()->symbol == "G") {
            currentRoom->getEvent()->Encounter(player);
            delete currentRoom->getEvent();
            currentRoom->setEvent(nullptr);
        } else if (currentRoom->getEvent()->symbol == "R") {
            currentRoom->getEvent()->Encounter(player);
        } else if (currentRoom->getEvent()->symbol == "B") {
            currentRoom->getEvent()->Encounter(player);
        } else if (currentRoom->getEvent()->symbol == "P") {
            currentRoom->getEvent()->Encounter(player);
        } else if (currentRoom->getEvent()->symbol == "A") {
            currentRoom->getEvent()->Encounter(player);
            delete currentRoom->getEvent();
            currentRoom->setEvent(nullptr);
        }
    }
}

void Game::playerMove(std::string direction) {
    int x = player->xPos;
    int y = player->yPos;

    if (direction.find("w") != std::string::npos) {
        x--;
    } else if (direction.find("s") != std::string::npos) {
        x++;
    } else if (direction.find("a") != std::string::npos) {
        y--;
    } else if (direction.find("d") != std::string::npos) {
        y++;
    }


    if (x < sizeX && y < sizeY && x >= 0 && y >= 0) {
        currentRoom->setPlayer(false);
        setCurrentRoom(map->getRoom(x, y));
        currentRoom->setPlayer(true);
        player->xPos = x;
        player->yPos = y;
        if (currentRoom->getEvent() != nullptr) {
            system("clear");
            printMap();
            checkRoomEvent();
            return;
        }
    } else {
        system("clear");
        printMap();
        std::cout << "You can't walk into a wall!" << std::endl;
        playerAction();
    }

    system("clear");
    printMap();

    return;
}

void Game::shootArrow() {
    std::string direction = "";
    std::cout << "Enter the direction you want to shoot the arrow (w, s, a, d): ";
    std::cin >> direction;

    int x = player->xPos;
    int y = player->yPos;
    int roomsTraveled = 0;

    player->arrows--;

    Arrow* arrow = new Arrow();

    if (direction.find("w") != std::string::npos) {
        while (x >= 0 || roomsTraveled < 3) {
            if (map->getRoom(x, y)->hasEvent()) {
                if (map->getRoom(x, y)->getEvent()->symbol == "W") {
                    std::cout << "You have slain the Wumpus!" << std::endl;
                    player->hasSlainWumpus = true;
                    delete map->getRoom(x, y)->getEvent();
                    map->getRoom(x, y)->setEvent(arrow);
                    break;
                } else {
                    std::cout << "You missed!" << std::endl;
                    map->getRoom(x, y)->setEvent(arrow);
                }
            }
            x--;
            roomsTraveled++;
        }
    } else if (direction.find("s") != std::string::npos) {
        while (x < sizeX || roomsTraveled < 3) {
            if (map->getRoom(x, y)->hasEvent()) {
                if (map->getRoom(x, y)->getEvent()->symbol == "W") {
                    std::cout << "You have slain the Wumpus!" << std::endl;
                    player->hasSlainWumpus = true;
                    delete map->getRoom(x, y)->getEvent();
                    map->getRoom(x, y)->setEvent(arrow);
                    break;
                } else {
                    std::cout << "You missed!" << std::endl;
                    map->getRoom(x, y)->setEvent(arrow);
                }
            }
            x++;
            roomsTraveled++;
        }
    } else if (direction.find("a") != std::string::npos) {
        while (y >= 0 || roomsTraveled < 3) {
            if (map->getRoom(x, y)->hasEvent()) {
                if (map->getRoom(x, y)->getEvent()->symbol == "W") {
                    std::cout << "You have slain the Wumpus!" << std::endl;
                    player->hasSlainWumpus = true;
                    delete map->getRoom(x, y)->getEvent();
                    map->getRoom(x, y)->setEvent(arrow);
                    break;
                } else {
                    std::cout << "You missed!" << std::endl;
                    map->getRoom(x, y)->setEvent(arrow);
                }
            }
            y--;
            roomsTraveled++;
        }
    } else if (direction.find("d") != std::string::npos) {
        while (y < sizeY || roomsTraveled < 3) {
            if (map->getRoom(x, y)->hasEvent()) {
                if (map->getRoom(x, y)->getEvent()->symbol == "W") {
                    std::cout << "You have slain the Wumpus!" << std::endl;
                    player->hasSlainWumpus = true;
                    delete map->getRoom(x, y)->getEvent();
                    map->getRoom(x, y)->setEvent(arrow);
                    break;
                } else {
                    std::cout << "You missed!" << std::endl;
                    map->getRoom(x, y)->setEvent(arrow);
                }
            }
            y++;
            roomsTraveled++;
        }
    } else {
        system("clear");
        delete arrow;
        printMap();
        std::cout << "Invalid direction!" << std::endl;
        player->arrows++;
        shootArrow();
    }
}

void Game::playerAction() {
    std::string action = "";

    std::cout << "Move up: w" << std::endl;
    std::cout << "Move down: s" << std::endl;
    std::cout << "Move left: a" << std::endl;
    std::cout << "Move right: d" << std::endl;
    std::cout << "Shoot arrow: g" << std::endl;
    std::cout << "Enter your action: ";
    std::cin >> action;

    if (action.find("w") != std::string::npos || action.find("s") != std::string::npos || action.find("a") != std::string::npos || action.find("d") != std::string::npos) {
        playerMove(action);
    } else if (action.find("g") != std::string::npos) {
        shootArrow();
    } else {
        std::cout << "Invalid action!" << std::endl;
        playerAction();
    }

    return;
}

void Game::run() {

    if (!this->player->isAlive) {
        std::cout << "You are dead! Game over!" << std::endl;
        return;
    } else if (this->player->hasEscaped) {
        std::cout << "You escaped! You win!" << std::endl;
        return;
    }

    if (!getEasyMode()) {
        checkPercepts();
    }

    playerAction();

    run();
}

void Game::printMap() {
    map->printMap(getEasyMode());
}

bool Game::getEasyMode() {
    return this->easyMode;
}
