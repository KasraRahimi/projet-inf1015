#pragma once
#include <vector>
#include <memory>
#include "Item.h"
using ItemPtr = std::unique_ptr<Item>;

class Inventory {
public:
    Inventory() = default;
    void addItem(ItemPtr itemPtr);
    ItemPtr take(std::string keyWord);
    bool use(std::string keyWord);
    bool look(std::string keyWord);
    size_t size() { return contents_.size(); }
    std::vector<ItemPtr>::iterator begin() { return contents_.begin(); }
    std::vector<ItemPtr>::iterator end() { return contents_.end(); }
private:
    std::vector<ItemPtr> contents_;
};
