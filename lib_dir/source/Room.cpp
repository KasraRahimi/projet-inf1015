#include "Room.h"
#include "Item.h"

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
    northRoom_(nullptr),
    eastRoom_(nullptr),
    southRoom_(nullptr),
    westRoom_(nullptr),
    isLocked_(isLocked) {}

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
        case Direction::VOID:
        default:
            break;
    }
}

std::string Room::getName() const {
    return name_;
}

void Room::setName(std::string newName) {
    name_ = newName;
}

std::string Room::getDescription() const {
    return description_;
}

void Room::setDescription(std::string newDescription) {
    description_ = newDescription;
}

Room* Room::getAdjacentRoomPtr(Direction side) const {
    switch (side) {
        case Direction::NORTH:
            return northRoom_;
            break;
        case Direction::EAST:
            return eastRoom_;
            break;
        case Direction::SOUTH:
            return southRoom_;
            break;
        case Direction::WEST:
            return westRoom_;
            break;
        case Direction::VOID:
        default:
            return nullptr;
            break;
    }
}

bool Room::isLocked() const {
    return isLocked_;
}

void Room::unlock() {
    isLocked_ = false;
}

void Room::addItem(ItemPtr newItem) {
    contents_.push_back(move(newItem));
}

ItemPtr Room::take(std::string keyWord) {
    for (size_t i = 0; i < contents_.size(); i++) {
        if (contents_[i]->isInKeyWords(keyWord)) {
            ItemPtr itemTaken = move(contents_[i]);
            contents_.erase(contents_.begin() + i);
            return move(itemTaken);
        }
    }
    return nullptr;
}

bool Room::use(std::string keyWord) {
    for (size_t i = 0; i < contents_.size(); i++) {
        if (contents_[i]->isInKeyWords(keyWord)) {
            contents_[i]->use();
            return true;
        }
    }
    return false;
}