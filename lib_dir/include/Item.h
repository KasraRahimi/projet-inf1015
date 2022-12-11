#pragma once
#include <iostream>
#include <vector>
#include "Game.h"
class Item {
public:
    Item() = default;
    virtual ~Item() = default;
    std::string getName() const { return name_; }
    std::string getDescription() const { return description_; }
    bool isInKeyWords(std::string word);
private:
    std::string name_, description_;
    Words keyWords;
    bool isTakeable_;
};