#pragma once
#include "Item.h"

class Stairs : public Item {
public:
    Stairs(std::string name, std::string desc, Room& source, Room& destination, Game& game,  bool isAddingToDestination = true);
    void use();
private:
    Room* destination_;
    Game* game_;
};