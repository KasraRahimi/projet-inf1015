// Projet final INF1015
// Auteurs : Rezki, Imane 2118881 - Rahimi, Kasra 2118712
// Équipe : 08

#include "Game.h"
#include "Inventory.h"

Game::Game() :
    currentRoom_(nullptr),
    isRunning_(false) {
}

Game::Game(Room &defaultRoom, const std::string &name) :
    currentRoom_(&defaultRoom),
    name_(name),
    isRunning_(true),
    inventory_(new Inventory()) {
        std::cout << CYAN << ">>> " << name_ << " <<<" << COLOR_LESS << std::endl << std::endl;
        processCommand("look");
}

std::string Game::getUserInput() {
    std::cout << "> ";
    std::string command;
    std::getline(std::cin, command);
    return command;
}

void Game::changeRoom(Direction side) {
    Room* nextRoom = currentRoom_->getAdjacentRoomPtr(side);
    if (nextRoom != nullptr && !(nextRoom->isLocked()))
        currentRoom_ = nextRoom;
}

void Game::printCurrentRoom() {
    std::cout << "~~ " << currentRoom_->getName() << " ~~" << std::endl;
    std::cout << currentRoom_->getDescription() << std::endl;
    printAllNeighbors();
    printRoomInventory();
    printUserInventory();
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
    if (neighbor != nullptr && !(neighbor->isLocked())) {
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

Words stringToVectorOfWords(std::string sentence) {
    if (sentence.length() == 0)
        return { "invalid command" };
    std::vector<std::string> words;
    std::string word;
    std::size_t size = sentence.length();
    for (std::size_t i = 0; i < size; i++) {
        if (sentence[i] == ' ') {
            words.push_back(word);
            word = "";
        } else if (i == size - 1) {
            word += sentence[i];
            words.push_back(word);
        } else {
            word += sentence[i];
        }
    }
    return words;
}

void Game::endingGameProcess(){
    std::cout << RED << "Thank you for your visit!\nNow leaving...\n\n" << COLOR_LESS << std::endl;
    isRunning_ = false;
}

Direction Game::castingOperandToDirection(const char direction[1]) {
	if (direction[0] != 'n' && direction[0] != 's' && direction[0] != 'w' && direction[0] != 'e' && direction[0] != 'v') {
        return Direction::VOID;
    } else {
        return static_cast<Direction>(direction[0]);
    }
}

void Game::movingRoomsProcess() {
    if (currentArguments_.size() != 1 || currentArguments_[0].length() != 1) {
        printUnknownCommand();
        return;
    }
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

void Game::processCommand(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), tolower);
    Words currentCommand = stringToVectorOfWords(command);
    Words arguments(currentCommand.begin() + 1, currentCommand.end());
    std::size_t nArguments = arguments.size();

    currentInstruction_ = currentCommand[0];
    if (nArguments == 0)
        currentArguments_ = {};
    else
        currentArguments_ = arguments;
    
    try {
        commands_[currentInstruction_]();
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

void Game::look() {
    if (currentArguments_.size() == 0)
        printCurrentRoom();
    else {
        for (std::string& keyWord : currentArguments_) {
            if (currentRoom_->getInventory().look(keyWord)) {
                std::cout << std::endl;
                return;
            }
            else if (inventory_->look(keyWord)) {
                std::cout << std::endl;
                return;
            }
        }
        printUnknownCommand();
    }
}

Game::~Game() {
    delete inventory_;
}

void Game::printRoomInventory() {
    std::cout << "In the " << currentRoom_->getName() << " there is : ";
    if (currentRoom_->getInventory().size() == 0)
        std::cout << "nothing" << std::endl;
    else {
        std::cout << std::endl;
        currentRoom_->getInventory().printContents();
    }
}

void Game::printUserInventory() {
    std::cout << "You have : ";
    if (inventory_->size() == 0)
        std::cout << "nothing" << std::endl;
    else {
        std::cout << std::endl;
        inventory_->printContents();
    }
}

void Game::takeItem() {
    if (currentArguments_.size() == 0) {
        printUnknownCommand();
        return;
    }
    for (std::string& keyWord : currentArguments_) {
        ItemPtr itemPtr = currentRoom_->getInventory().take(keyWord);
        if (itemPtr != nullptr && itemPtr->isTakeable()) {
            std::cout << "You took the " << itemPtr->getName() << std::endl;
            inventory_->addItem(std::move(itemPtr));
            std::cout << std::endl;
            return;
        } else if (itemPtr != nullptr) {
            std::cout << "The " << itemPtr->getName() << " can't be taken" << std::endl << std::endl;
            currentRoom_->getInventory().addItem(std::move(itemPtr));
            return;
        }
    }
    printUnknownCommand();
}

void Game::useItem() {
    if (currentArguments_.size() == 0) {
        printUnknownCommand();
        return;
    }
    for (std::string& keyWord : currentArguments_) {
        if (currentRoom_->getInventory().use(keyWord))
            return;
        else if (inventory_->use(keyWord))
            return;
    }
    printUnknownCommand();
}