#pragma once
#include "Room.h"
#include <vector>
#include "string.h"
#include <functional>
#include <map>
#include <algorithm>

#define CYAN "\033[96m"
#define RED "\033[91m"
#define COLOR_LESS "\033[00m"
using Words = std::vector<std::string>;

Words stringToVectorOfWords(std::string sentence);

class Game {
public:
    Game();
    Game(Room &defaultRoom, const std::string &name);
    ~Game();
    std::string getUserInput();
    void processCommand(std::string command);

    bool isRunning() const;
private:
    Room* currentRoom_;
    const std::string name_;
    bool isRunning_;
    std::string currentInstruction_;
    Words currentArguments_;
    Inventory* inventory_;
    std::map<std::string, std::function<void()>> commands_ = { 
        {"go", [=]() { movingRoomsProcess(); } },
        {"look", [=]() { look(); } },
        {"quit", [=]() { endingGameProcess();} },
        {"take", [=]() { takeItem(); }},
        {"use", [=]() { useItem(); }}
    };

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printAllNeighbors();
    void printNeighbor(Direction side);
    void printRoomInventory();
    void printUserInventory();

    void printUnknownCommand();
    void printArgumentNumberError();

    void endingGameProcess();
    void movingRoomsProcess();
    Direction castingOperandToDirection(const char direction[1]);

    void look();
    void takeItem();
    void useItem();


    friend class Key;
    friend class Passage;
    friend class SingleUseItem;
};