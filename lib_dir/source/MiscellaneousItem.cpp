#include "MiscellaneousItem.h"

void MiscellaneousItem::use() {
    std::cout << getUseMessage() << std::endl;
}

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

void Book::use() {
    std::cout << "You read :" << std::endl;
    std::cout << getPassage() << std::endl;
    std::cout << "You read for quite a while, somewhere a clock strikes the arrival of a new hour..." << std::endl;
}

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

void TwoUsesItem::use() {
    if (game_->currentRoom_ == destinationRoom_) {
        if (isUsedTwice_) {
            std::cout << "the " << getName() << " has completed it's use.\n\n";
        } else if (isUsedOnce_) {
            std::cout << getSecondMessage() << std::endl;
            isUsedTwice_ = true;
        } else if (!isUsedOnce_) {
            std::cout << getFirstMessage() << std::endl;
            isUsedOnce_ = true;
        }
    } else {
        std::cout << "the " << getName() << " cannot be used in this room. You may want to try elsewhere. " << "\n\n";
    }
}