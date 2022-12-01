#pragma once
#include "Room.h"

class Game {
public:
    Game();
    Game(Room defaultRoom);
    std::string getUserInput();
    void changeRoom();
    void printCurrentRoom();
private:
    Room* currentRoom_;
};