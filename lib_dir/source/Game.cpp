#include "Game.h"

Game::Game() :
    currentRoom_(nullptr),
    isRunning_(false) {
}

Game::Game(Room &defaultRoom, const std::string &name) :
    currentRoom_(&defaultRoom),
    name_(name),
    isRunning_(true) {
        std::cout << "\033[96m>>> " << name_ << " <<<\033[00m" << std::endl << std::endl;
        processCommande("look");
}

std::string Game::getUserInput() {
    std::cout << "> ";
    std::string command;
    std::getline(std::cin, command);
    return command;
}

void Game::changeRoom(Direction side) {
    Room* nextRoom = currentRoom_->getAdjacentRoomPtr(side);
    if (nextRoom != nullptr)
        currentRoom_ = nextRoom;
}

void Game::printCurrentRoom() {
    std::cout << "~~ " << currentRoom_->getName() << " ~~" << std::endl;
    std::cout << currentRoom_->getDescription() << std::endl;
    printAllNeighbors();
    std::cout << std::endl;
}

void Game::printAllNeighbors() {
    printNeighbor(Direction::NORTH);
    printNeighbor(Direction::EAST);
    printNeighbor(Direction::SOUTH);
    printNeighbor(Direction::WEST);
}

void Game::printNeighbor(Direction side) {
    Room* neighbor = currentRoom_->getAdjacentRoomPtr(side);
    if (neighbor != nullptr) {
        std::cout << neighbor->getName() << " is to the ";
        switch (side) {
            case Direction::NORTH:
                std::cout << "North (N)" << std::endl;
                break;
            case Direction::EAST:
                std::cout << "East (E)" << std::endl;
                break;
            case Direction::SOUTH:
                std::cout << "South (S)" << std::endl;
                break;
            case Direction::WEST:
                std::cout << "West (W)" << std::endl;
                break;      
            default:
                break;
        }
    }
}

std::vector<std::string> Game::stringToVectorOfWords(std::string command) {
    std::vector<std::string> words;
    std::string word;
    std::size_t size = command.length();
    for (std::size_t i = 0; i < size; i++) {
        if (command[i] == ' ') {
            words.push_back(word);
            word = "";
        } else if (i == size - 1) {
            word += command[i];
            words.push_back(word);
        } else {
            word += command[i];
        }
    }
    return words;
}

void Game::processCommande(std::string command) {
    std::vector<std::string> instruction = stringToVectorOfWords(command);
    std::size_t nArguments = instruction.size();
    if (nArguments > 2) {
        printUnknownCommand();
        return;
    } else {
        std::string action = instruction[0];
        if (action == "look" && nArguments == 1)
            printCurrentRoom();
        
        else if (action == "go" && nArguments == 2) {
            std::string direction = instruction[1];
            Room* ptrCurrentRoom = currentRoom_;

            std::string output;
            if (direction == "N") {
                changeRoom(Direction::NORTH);
                output = "going North";
            } else if (direction == "E") {
                changeRoom(Direction::EAST);
                output = "going East";
            } else if (direction == "S") {
                changeRoom(Direction::SOUTH);
                output = "going South";
            } else if (direction == "W") {
                changeRoom(Direction::WEST);
                output = "going West";
            } else {
                printUnknownCommand();
                return;
            }

            if (currentRoom_ == ptrCurrentRoom)
                std::cout << "cannot go there" << std::endl << std::endl;
            else {
                std::cout << output << std::endl << std::endl;
                printCurrentRoom();
            }
    
        } else if (action == "quit" && nArguments == 1) {
            std::cout << "\033[91mThank you for your visit!\nNow leaving...\n\n\033[00" << std::endl;
            isRunning_ = false;
        } else {
            printUnknownCommand();
        }
    }
}

bool Game::isRunning() const {
    return isRunning_;
}

void Game::printUnknownCommand() {
    std::cout << "\033[91munknown command\033[00m" << std::endl << std::endl;
}
