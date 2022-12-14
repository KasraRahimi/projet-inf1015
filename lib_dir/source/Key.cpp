#include "Key.h"

Key::Key(std::string name, std::string desc, Room &unlockingRoom, Room &lockedRoom) :
    Item(name, desc, true),
    unlockingRoom_(&unlockingRoom),
    lockedRoom_(&lockedRoom) {}