#pragma once
#include "Room.h"
#include <vector>

#define CYAN "\033[96m"
#define RED "\033[91m"
#define COLOR_LESS "\033[00m"

class Game {
public:
    Game();
    Game(Room &defaultRoom, const std::string &name);
    std::string getUserInput();
    void processCommand(std::string command);

    bool isRunning() const;
private:
    Room* currentRoom_;
    const std::string name_;
    bool isRunning_;

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printAllNeighbors();
    void printNeighbor(Direction side);
    void printUnknownCommand();
    std::vector<std::string> stringToVectorOfWords(std::string sentence);
};