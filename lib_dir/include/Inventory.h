#pragma once
#include <vector>
#include <memory>
#include "Item.h"
using ItemPtr = std::unique_ptr<Item>;

class Inventory {
public:
    Inventory() = default;
    void addItem(ItemPtr itemPtr);
    ItemPtr take(const std::string &keyWord);
    bool use(const std::string &keyWord);
    bool look(const std::string &keyWord);
    size_t size() { return contents_.size(); }
    void printContents(bool isTabulated = true);
    std::vector<ItemPtr>::iterator begin() { return contents_.begin(); }
    std::vector<ItemPtr>::iterator end() { return contents_.end(); }
private:
    std::vector<ItemPtr> contents_;
};
