#include <Game.h>

int main() {
    Room LivingRoom("Living Room",
        "The living room is a spacious room. It has a TV and a couch.");
    Room Kitchen("Kitchen",
        "The kitchen has a fridge, an oven, and many pots and pans!");
    LivingRoom.addRoom(Kitchen, Direction::NORTH);
    Game game(LivingRoom);
    while (game.isRunning()) {
        std::string command = game.getUserInput();
        game.processCommande(command);
    }
    return 0;
}