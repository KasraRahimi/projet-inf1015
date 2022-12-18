#include "Key.h"

Key::Key(std::string name, std::string desc, Room &unlockingRoom, Room &lockedRoom, Game& game) :
    Item(name, desc, true),
    unlockingRoom_(&unlockingRoom),
    lockedRoom_(&lockedRoom),
    hasBeenUsed_(false),
    game_(&game) {}

void Key::use() {
    if (hasBeenUsed_) {
        std::cout << "the " << getName() << " has already been used\n\n";
        return;
    }
    if (game_->currentRoom_ == unlockingRoom_) {
        lockedRoom_->unlock();
        std::cout << "the " << getName() << " has unlocked " << lockedRoom_->getName() << "\n\n";
        hasBeenUsed_ = true;
    } else {
        std::cout << "the " << getName() << " can't be used here\n\n";
    }
}