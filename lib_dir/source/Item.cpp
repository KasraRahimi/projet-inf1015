#include "Item.h"

Item::Item(std::string name, std::string desc, bool isTakeable) :
    name_(name),
    description_(desc),
    isTakeable_(isTakeable) {
        keyWords_ = stringToVectorOfWords(name);
}

bool Item::isInKeyWords(const std::string &word) const {
    for (std::string keyWord : keyWords_) {
        if (word.find(keyWord) != std::string::npos)
            return true;
    }
    return false;
}
