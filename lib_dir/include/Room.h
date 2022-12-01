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
    void addRoom(std::shared_ptr<Room> room, Direction side);
private:
    std::string name_, description_;
    std::shared_ptr<Room> northRoom_, eastRoom_, southRoom_, westRoom_;
    bool isLocked_;
};