#include "Item.h"

Item::Item(std::string name, std::string desc, bool isTakeable, Game& game) :
    name_(name),
    description_(desc),
    isTakeable_(isTakeable),
    game_(&game) {
        keyWords_ = stringToVectorOfWords(name);
}

bool Item::isInKeyWords(std::string word) const {
    for (std::string keyWord : keyWords_) {
        if (word.find(keyWord) != std::string::npos)
            return true;
    }
    return false;
}
