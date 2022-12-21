#include "Passage.h"
#include "Inventory.h"

Passage::Passage(std::string name, std::string desc, Room& source, Room& destination, Game& game, bool isTwoWay) :
    Item(name, desc, false),
    destination_(&destination),
    game_(&game) {
        if (isTwoWay) {
            auto stairPtr = std::make_unique<Passage>(name, desc, destination, source, game, false);
            destination.getInventory().addItem(std::move(stairPtr));
        }
}

void Passage::use() {
    std::cout << "You've used the " << getName()
    << " and gone to the " << destination_->getName() << std::endl;
    game_->currentRoom_ = destination_;
    game_->processCommand("look");
}