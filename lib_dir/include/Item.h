#pragma once
#include "Game.h"

class Item {
public:
    Item() = default;
    Item(std::string name, std::string desc, bool isTakeable, Game &game);
    virtual ~Item() = default;
    std::string getName() const { return name_; }
    std::string getDescription() const { return description_; }
    bool isTakeable() const { return isTakeable_; }
    bool isInKeyWords(std::string word) const;
    virtual void use() = 0;
protected:
    Game& getWorld() { return *world_; }
private:
    std::string name_, description_;
    Words keyWords_;
    bool isTakeable_;
    Game* world_;
};