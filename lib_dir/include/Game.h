#pragma once
#include "Room.h"
#include <vector>

class Game {
public:
    Game();
    Game(Room &defaultRoom);
    std::string getUserInput();
    void processCommande(std::string command);

    bool isRunning() const;
private:
    Room* currentRoom_;
    bool isRunning_;

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printAllNeighbors();
    void printNeighbor(Direction side);
    void printUnknownCommand();
    std::vector<std::string> stringToVectorOfWords(std::string sentence);
};