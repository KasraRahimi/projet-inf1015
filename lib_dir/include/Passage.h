#pragma once
#include "Item.h"

class Passage : public Item {
public:
    Passage(std::string name, std::string desc, Room& source, Room& destination, Game& game,  bool isTwoWay = true);
    void use();
private:
    Room* destination_;
    Game* game_;
};