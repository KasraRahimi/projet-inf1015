#pragma once
#include "Room.h"
#include <vector>

class Game {
public:
    Game();
    Game(Room &defaultRoom);
    std::string getUserInput();
    void processCommande(std::string command);

    bool isRunning_() const;
private:
    Room* currentRoom_;
    bool isRunning_;

    void changeRoom(Direction side);
    void printCurrentRoom();
    void printNeighboringRoom(const Room* ptrRoom, Direction side);
    std::vector<std::string> stringToVectorOfWords(std::string sentence);
};