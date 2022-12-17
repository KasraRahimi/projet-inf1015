#pragma once
#include "Room.h"
#include "string.h"
#include <functional>
#include <map>

#define CYAN "\033[96m"
#define RED "\033[91m"
#define COLOR_LESS "\033[00m"
using Words = std::vector<std::string>;

Words stringToVectorOfWords(std::string sentence);

class Game {
public:
    Game();
    Game(Room &defaultRoom, const std::string &name);
    std::string getUserInput();
    void processCommande(std::string command);

    bool isRunning() const;
private:
    Room* currentRoom_;
    const std::string name_;
    bool isRunning_;
    std::string currentInstruction_;
    Words currentArguments_;
    Items inventory_;

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printAllNeighbors();
    void printNeighbor(Direction side);
    void printUnknownCommand();
    void endingGameProcess();
    void movingRoomsProcess();
    Direction castingOperandToDirection(const char direction[1]);
    friend class Key;
};