#include "Key.h"

Key::Key(std::string name, std::string desc, Room &unlockingRoom, Room &lockedRoom) :
    Item(name, desc, true),
    unlockingRoom_(&unlockingRoom),
    lockedRoom_(&lockedRoom) {}

void Key::use(Game* game) {
    if (hasBeenUsed_) {
        std::cout << "the " << getName() << " has already been used\n\n";
        return;
    }
    if (game->currentRoom_ == unlockingRoom_) {
        lockedRoom_->unlock();
        std::cout << "the " << getName() << " has unlocked " << lockedRoom_->getName() << "\n\n";
        hasBeenUsed_ = true;
    } else {
        std::cout << "the " << getName() << "can't be used here\n\n";
    }
}