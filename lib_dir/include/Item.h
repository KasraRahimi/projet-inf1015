#pragma once
#include <iostream>
#include <vector>
using vecOfStrings = std::vector<std::string>;

class Item {
public:
    Item() = default;
    virtual ~Item() = default;
    std::string getName() { return name_; }
    std::string getDescription() { return description_; }
    bool isInKeyWords(std::string word);
private:
    std::string name_, description_;
    vecOfStrings keyWords;
    bool isTakeable_;
};