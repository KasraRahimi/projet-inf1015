#pragma once
#include "Item.h"

class Key : public Item {
public:
    Key(std::string name, std::string desc, Room &unlockingRoom, Room &lockedRoom, Game& game);
    void use();
private:
    Room* unlockingRoom_;
    Room* lockedRoom_;
    bool hasBeenUsed_;
    Game* game_;
};