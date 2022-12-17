#include "Key.h"

Key::Key(std::string name, std::string desc, Room &unlockingRoom, Room &lockedRoom, Game& game) :
    Item(name, desc, true, game),
    unlockingRoom_(&unlockingRoom),
    lockedRoom_(&lockedRoom) {}

void Key::use() {
    Game game = getWorld();
    if (hasBeenUsed_) {
        std::cout << "the " << getName() << " has already been used\n\n";
        return;
    }
    if (game.currentRoom_ == unlockingRoom_) {
        lockedRoom_->unlock();
        std::cout << "the " << getName() << " has unlocked " << lockedRoom_->getName() << "\n\n";
        hasBeenUsed_ = true;
    } else {
        std::cout << "the " << getName() << "can't be used here\n\n";
    }
}