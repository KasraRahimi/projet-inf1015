#pragma once
#include "Item.h"

class MiscellaneousItem : public Item {
public:
    MiscellaneousItem() : Item() {}
    MiscellaneousItem(std::string name, std::string desc, bool isTakeable, std::string usedDescription) : Item(name, desc, isTakeable) { usedDescription_ = usedDescription; }
    void use();
    std::string getUseMessage() const { return usedDescription_; }
private:
    std::string usedDescription_;
};

void MiscellaneousItem::use() {
    std::cout << getUseMessage() << std::endl;
}


class Clock : public Item {
public:
    Clock() : Item() {}
    Clock(std::string name, std::string desc, bool isTakeable) : Item(name, desc, isTakeable) { currentTime_ = defaultTime; }
    void use();
    void showTime() const;
    void resetTime() { currentTime_ = defaultTime; }
private:
    static const int defaultTime = 0;
    int currentTime_;
};

void Clock::showTime() const {
    std::cout << "The time is : " << std::to_string(currentTime_) << ":00." << std::endl;
}

void Clock::use() {
    if (currentTime_ == defaultTime) {
        std::cout << "Round and round goes the clock!" << std::endl;
        showTime();
    } else if (currentTime_ > 23) {
        resetTime();
        showTime();
    } else {
        showTime();
    }
    currentTime_++;
}


class Book : public Item {
public:
    Book() : Item() {}
    Book(std::string name, std::string desc, bool isTakeable, std::string passage) : Item(name, desc, isTakeable) { passage_ = passage; }
    void use();
    std::string getPassage() { return passage_; }
private:
    std::string passage_;
};

void Book::use() {
    std::cout << "You read :" << std::endl;
    std::cout << getPassage() << std::endl;
    std::cout << "You read for quite a while, somewhere a clock strikes the arrival of a new hour..." << std::endl;
}

class NoteBook : public Item {
public:
    NoteBook() : Item() {}
    NoteBook(std::string name, std::string desc, bool isTakeable, int nbLines) : Item(name, desc, isTakeable) { lineCount_ = 0; maxLineCount_ = nbLines; }
    void use();
    void getContents();
private:
    int lineCount_;
    int maxLineCount_;
    std::map<int,std::string> addedNotes_ = {};
};

void NoteBook::getContents() {
    for (auto& line : addedNotes_){
        std::cout << "\t\033[3m" << line.second << "\t\033[0m" << std::endl;
    }
}

void NoteBook::use() {
    if (maxLineCount_ != 0) {
        std::cout << "There are " << maxLineCount_ << " empty lines, you write :";
        std::string sentence;
        std::getline(std::cin, sentence);
        std::cout << "\nYou put down your pen..." << std::endl;
        addedNotes_[lineCount_] = sentence;
        lineCount_++;
        maxLineCount_--;
    } else {
        std::cout << "\nThe notebook is complete, you read back your notes :\n" << std::endl;
        getContents();
    }
}


class SingleUseItem : public Item {
public:
    SingleUseItem(std::string name, std::string desc, std::string usedDescription, Room &destinationRoom, Game& game) : Item(name, desc, true), destinationRoom_(&destinationRoom), game_(&game) { usedDescription_ = usedDescription; hasBeenUsed_ = false; }
    void use();
    std::string getUseMessage() const { return usedDescription_; }
private:
    Room* destinationRoom_;
    Game* game_;
    bool hasBeenUsed_;
    std::string usedDescription_;
};

void SingleUseItem::use() {
    if (hasBeenUsed_) {
        std::cout << "the " << getName() << " has already been used.\n\n";
        return;
    } else if (game_->currentRoom_ == destinationRoom_) {
        std::cout << getUseMessage() << std::endl;
        hasBeenUsed_ = true;
    } else {
        std::cout << "the " << getName() << " cannot be used in this room. You may want to try elsewhere. " << "\n\n";
    }
}