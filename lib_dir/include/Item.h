#pragma once
#include "Game.h"

class Item {
public:
    Item() = default;
    virtual ~Item() = default;
    std::string getName() const { return name_; }
    std::string getDescription() const { return description_; }
    bool isTakeable() const { return isTakeable_; }
    bool isInKeyWords(std::string word) const;
    virtual void use(Game* game) = 0;
protected:
    void addKeyword(std::string keyword);
private:
    std::string name_, description_;
    Words keyWords;
    bool isTakeable_;
};