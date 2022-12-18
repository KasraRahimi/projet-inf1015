#include "Inventory.h"

void Inventory::addItem(ItemPtr itemPtr) {
    contents_.push_back(std::move(itemPtr));
}

ItemPtr Inventory::take(std::string keyWord) {
    for (auto it = contents_.begin(); it != contents_.end(); ++it) {
        if ((*it)->isInKeyWords(keyWord)) {
            ItemPtr output = std::move(*it);
            contents_.erase(it);
            return std::move(output);
        }
    }
    return nullptr;
}

bool Inventory::use(std::string keyWord) {
    for (auto it = contents_.begin(); it != contents_.end(); ++it) {
        if ((*it)->isInKeyWords(keyWord)) {
            (*it)->use();
            return true;
        }
    }
    return false;
}

bool Inventory::look(std::string keyWord) {
    for (ItemPtr& item : contents_) {
        if (item->isInKeyWords(keyWord)) {
            std::cout << "## " << item->getName() << " ##" << std::endl;
            std::cout << item->getDescription() << std::endl;
            return true;
        }
    }
    return false;
}