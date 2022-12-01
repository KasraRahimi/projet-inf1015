#pragma once
#include <iostream>
#include <memory>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Room {
public:
    Room();
    Room(std::string name, std::string description, bool isLocked=false);
    void addRoom(Room &room, Direction side);
    std::string getName() const;
    std::string getDescription() const;
    Room* getAdjacentRoomPtr(Direction side) const;
    bool isLocked() const;
private:
    std::string name_, description_;
    Room* northRoom_;
    Room* eastRoom_;
    Room* southRoom_;
    Room* westRoom_;
    bool isLocked_;
};