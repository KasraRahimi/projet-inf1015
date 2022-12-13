#include "Item.h"

bool Item::isInKeyWords(std::string word) {
    for (std::string keyWord : keyWords) {
        if (word.find(keyWord) != std::string::npos)
            return true;
    }
    return false;
}

void Item::addKeyword(std::string keyword) {
    keyWords.push_back(keyword);
}