#pragma once
#include "Room.h"

class Game {
public:
    Game();
    Game(Room &defaultRoom);
    std::string getUserInput();
private:
    Room* currentRoom_;

    void changeRoom();
    void printCurrentRoom();
};