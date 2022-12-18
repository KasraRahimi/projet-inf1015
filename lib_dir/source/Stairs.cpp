#include "Stairs.h"
#include "Inventory.h"

Stairs::Stairs(std::string name, std::string desc, Room& source, Room& destination, Game& game, bool isAddingToDestination) :
    Item(name, desc, false),
    destination_(&destination),
    game_(&game) {
        if (isAddingToDestination) {
            auto stairPtr = std::make_unique<Stairs>(name, desc, destination, source, game, false);
            destination.getInventory().addItem(std::move(stairPtr));
        }
}

void Stairs::use() {
    std::cout << "You've used the " << getName()
    << " and gone to the " << destination_->getName() << std::endl << std::endl;
    game_->currentRoom_ = destination_;
    game_->processCommand("look");
}