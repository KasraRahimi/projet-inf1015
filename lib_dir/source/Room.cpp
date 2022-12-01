#include "Room.h"

Room::Room() : 
    name_("NO NAME"), 
    description_("NO DESCRIPTION"),
    northRoom_(nullptr),
    eastRoom_(nullptr),
    southRoom_(nullptr),
    westRoom_(nullptr),
    isLocked_(false) {}

Room::Room(std::string name, std::string description, bool isLocked) :
    name_(name),
    description_(description),
    isLocked_(isLocked),
    northRoom_(nullptr),
    eastRoom_(nullptr),
    southRoom_(nullptr),
    westRoom_(nullptr) {}

void Room::addRoom(Room &room, Direction side) {
    switch (side) {
        case Direction::NORTH:
            northRoom_ = &room;
            room.southRoom_ = this;
            break;
        case Direction::EAST:
            eastRoom_ = &room;
            room.westRoom_ = this;
            break;
        case Direction::SOUTH:
            southRoom_ = &room;
            room.northRoom_ = this;
            break;
        case Direction::WEST:
            westRoom_ = &room;
            room.eastRoom_ = this;
            break;
    }
}