#pragma once
#include <iostream>
#include <memory>

class Room {
public:
    Room();
    Room(std::string name, std::string description, bool isLocked=false);
private:
    std::string name_, description_;
    std::shared_ptr<Room> northRoom_, eastRoom_, southRoom_, westRoom_;
    bool isLocked;
};