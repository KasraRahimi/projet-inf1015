#pragma once
#include "Game.h"

class Item {
public:
    Item() = default;
    Item(std::string name, std::string desc, bool isTakeable);
    virtual ~Item() = default;
    std::string getName() const { return name_; }
    std::string getDescription() const { return description_; }
    bool isTakeable() const { return isTakeable_; }
    bool isInKeyWords(const std::string &word) const;
    virtual void use() = 0;
private:
    std::string name_, description_;
    Words keyWords_;
    bool isTakeable_;
};