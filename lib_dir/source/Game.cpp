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

void Game::movingRoomsProcess() {
    char directionChar[1];
    strcpy(directionChar, currentArguments_[0].c_str());
    Direction directionEnum =  castingOperandToDirection(directionChar);

    Room* previousRoom = currentRoom_;
    std::string output;

    switch (directionEnum) {
        case Direction::NORTH:
            changeRoom(Direction::NORTH);
            output = "going North\n\n";
            break;
        case Direction::SOUTH:
            changeRoom(Direction::SOUTH);
            output = "going South\n\n";
            break;
        case Direction::WEST:
            changeRoom(Direction::WEST);
            output = "going West\n\n";
            break;
        case Direction::EAST:
            changeRoom(Direction::EAST);
            output = "going East\n\n";
            break;
        case Direction::VOID:
        default:
            printUnknownCommand();
            return;
            break;
    }
    
    if (currentRoom_ == previousRoom)
        std::cout << "cannot go there\n\n";
    else {
        std::cout << output;
        printCurrentRoom();
    }
}

void Game::processCommande(std::string command) {
    std::map<std::string, std::function<void()>> commands = { 
        {"go", [=]() { movingRoomsProcess(); } },
        {"look", [=]() { printCurrentRoom(); } },
        {"quit", [=]() { endingGameProcess();} }
    };

    Words currentCommand = stringToVectorOfWords(command);
    Words arguments(currentCommand.begin() + 1, currentCommand.end());
    std::size_t nArguments = arguments.size();

    currentInstruction_ = currentCommand[0];
    if (nArguments == 0)
        currentArguments_ = {};
    else
        currentArguments_ = arguments;
    
    try {
        commands[currentInstruction_]();
    } catch(const std::bad_function_call& e) {
        printUnknownCommand();
    }
    
}

bool Game::isRunning() const {
    return isRunning_;
}

void Game::printUnknownCommand() {
    std::cout << RED << "unknown command" << COLOR_LESS << std::endl << std::endl;
}
