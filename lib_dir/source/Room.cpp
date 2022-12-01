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