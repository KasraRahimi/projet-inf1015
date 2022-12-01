#pragma once
#include "Room.h"
#include <vector>

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

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printAllNeighbors();
    void printNeighbor(Direction side);
    void printUnknownCommand();
    std::vector<std::string> stringToVectorOfWords(std::string sentence);
};