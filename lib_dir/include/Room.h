#pragma once
#include <iostream>
#include <vector>
#include <memory>

enum class Direction : char  {
    NORTH = 'N',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W',
    VOID = 'V'
};

class Item;
using ItemPtr = std::unique_ptr<Item>;
using Items = std::vector<ItemPtr>;

class Room {
public:
    Room();
    Room(std::string name, std::string description, bool isLocked=false);
    void addRoom(Room &room, Direction side);
    std::string getName() const;
    void setName(std::string newName);
    std::string getDescription() const;
    void setDescription(std::string newDescription);
    Room* getAdjacentRoomPtr(Direction side) const;
    bool isLocked() const;
    void unlock();
    void addItem(ItemPtr newItem);
    ItemPtr take(std::string keyWord);
    bool use(std::string keyWord);
private:
    std::string name_, description_;
    Room* northRoom_;
    Room* eastRoom_;
    Room* southRoom_;
    Room* westRoom_;
    bool isLocked_;
    Items contents_;
};