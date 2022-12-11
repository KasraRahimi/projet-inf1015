#include "Game.h"

Game::Game() :
    currentRoom_(nullptr),
    isRunning_(false) {
}

Game::Game(Room &defaultRoom, const std::string &name) :
    currentRoom_(&defaultRoom),
    name_(name),
    isRunning_(true) {
        std::cout << CYAN << ">>> " << name_ << " <<<" << COLOR_LESS << std::endl << std::endl;
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
            case Direction::VOID:     
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

void Game::endingGameProcess(){
    std::cout << RED << "Thank you for your visit!\nNow leaving...\n\n" << COLOR_LESS << std::endl;
    isRunning_ = false;
}

Direction Game::castingOperandToDirection(const char direction[1]) {
	if (direction[0] != 'N' && direction[0] != 'S' && direction[0] != 'W' && direction[0] != 'E'&& direction[0] != 'V') {
        return Direction::VOID;
    } else {
        return static_cast<Direction>(direction[0]);
    }
}

void Game::movingRoomsProcess(std::string direction) {
    char directionChar[1];
    std::strcpy(directionChar, direction.c_str());
    Direction directionEnum =  castingOperandToDirection(directionChar);

    switch (directionEnum) {
        case Direction::NORTH:
            changeRoom(Direction::NORTH);
            std::cout << "going North" << std::endl << std::endl;
            break;
        case Direction::SOUTH:
            changeRoom(Direction::SOUTH);
            std::cout << "going South" << std::endl << std::endl;
            break;
        case Direction::WEST:
            changeRoom(Direction::WEST);
            std::cout << "going West" << std::endl << std::endl;
            break;
        case Direction::EAST:
            changeRoom(Direction::EAST);
            std::cout << "going East" << std::endl << std::endl;
            break;
        case Direction::VOID:
        default:
            printUnknownCommand();
            std::cout << "cannot go there" << std::endl;
            break;
        }
        printCurrentRoom();
}

void Game::processCommande(std::string command) {
    std::map<std::string, std::function<void(std::string)> > commands = { 
        {"go", [=](std::string direction) { movingRoomsProcess(direction); }},
        {"look", [=](std::string direction) { printCurrentRoom(); }},
        {"quit", [=](std::string direction) { endingGameProcess(); }},
    };
    std::vector<std::string> instruction = stringToVectorOfWords(command);
    std::string action = instruction[0];
    std::string parameter = instruction[1];
    commands[action](parameter);       // this allows commands with 2 operands and more, but will ONLY take the first one, must be in keyWords vector of item
}

// alternative but requires one more of if - else :
// std::map<std::string, std::function<void(std::string)> > commandsOneOperand = { 
//     {"go", [=](std::string direction) { movingRoomsProcess(direction); } }
// };

// std::map<std::string, std::function<void(void)> > commandsNoOperand = { 
//     {"look", [=]() { printCurrentRoom(); } },
//     {"quit", [=]() { endingGameProcess();} }
// };

// std::vector<std::string> instruction = stringToVectorOfWords(command);
// std::size_t nArguments = instruction.size();
// std::string action = instruction[0];
// std::string parameter = instruction[1];

// if (nArguments == 1) {
//     commandsNoOperand[action]();
// }
// else {
//     commandsOneOperand[action](parameter);
// }

bool Game::isRunning() const {
    return isRunning_;
}

void Game::printUnknownCommand() {
    std::cout << RED << "unknown command" << COLOR_LESS << std::endl << std::endl;
}
