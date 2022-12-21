#pragma once
#include "Item.h"

class MiscellaneousItem : public Item {
public:
    MiscellaneousItem(std::string name, std::string desc, bool isTakeable, std::string usedDescription) : 
        Item(name, desc, isTakeable),
        usedDescription_(usedDescription)
        {}
    void use();
    std::string getUseMessage() const { return usedDescription_; }
private:
    std::string usedDescription_;
};

class Clock : public Item {
public:
    Clock() : Item() {}
    Clock(std::string name, std::string desc, bool isTakeable) : Item(name, desc, isTakeable), currentTime_(defaultTime) {}
    void use();
    void showTime() const;
    void resetTime() { currentTime_ = defaultTime; }
private:
    static const int defaultTime = 0;
    int currentTime_;
};


class Book : public Item {
public:
    Book() : Item() {}
    Book(std::string name, std::string desc, bool isTakeable, std::string passage) : Item(name, desc, isTakeable), passage_(passage) {}
    void use();
    std::string getPassage() { return passage_; }
private:
    std::string passage_;
};


class NoteBook : public Item {
public:
    NoteBook(std::string name, std::string desc, bool isTakeable, int nbLines) : 
        Item(name, desc, isTakeable),
        lineCount_(0),
        maxLineCount_(nbLines)
        {}
    void use();
    void getContents();
private:
    int lineCount_, maxLineCount_;
    std::map<int,std::string> addedNotes_ = {};
};


class SingleUseItem : public Item {
public:
    SingleUseItem(std::string name, std::string desc, bool isTakeable, std::string usedDescription, Room &destinationRoom, Game& game) : 
        Item(name, desc, isTakeable), 
        destinationRoom_(&destinationRoom), 
        game_(&game),
        hasBeenUsed_(false),
        usedDescription_(usedDescription)
        {}

    void use();
    std::string getUseMessage() const { return usedDescription_; }
private:
    Room* destinationRoom_;
    Game* game_;
    bool hasBeenUsed_;
    std::string usedDescription_;
};


class TwoUsesItem : public Item {
public:
    TwoUsesItem(std::string name, std::string desc, bool isTakeable, Room &destinationRoom, Game& game, std::string usedDescription, std::string secondTimeUsedDescription) : 
        Item(name, desc, isTakeable),
        destinationRoom_(&destinationRoom), 
        game_(&game),
        usedDescription_(usedDescription),
        secondTimeUsedDescription_(secondTimeUsedDescription),
        isUsedOnce_(false),
        isUsedTwice_(false)
        {}
    void use();
    std::string getFirstMessage() const { return usedDescription_; }
    std::string getSecondMessage() const { return secondTimeUsedDescription_; }
private:
    Room* destinationRoom_;
    Game* game_;
    std::string usedDescription_, secondTimeUsedDescription_;
    bool isUsedOnce_,isUsedTwice_;
};
