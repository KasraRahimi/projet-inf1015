#include <Game.h>

int main() {
    Room livingRoom("Living Room",
        "The living room is a spacious room. It has a TV and a couch.");
    Room kitchen("Kitchen",
        "The kitchen has a fridge, an oven, and many pots and pans!");
    Room hallway("Hallway",
        "The hallway connects the living room to the bathroom. It's kinda dark. The light went out.");
    Room bathroom("Bathroom",
        "The bathroom has a toilet and a bathtub. It's rather small.");
    Room bedroom("Bedroom",
        "The bedroom is large. It has a bed and a desk. Your closet can be found here.");

    livingRoom.addRoom(kitchen, Direction::NORTH);
    livingRoom.addRoom(hallway, Direction::EAST);
    hallway.addRoom(bathroom, Direction::SOUTH);
    hallway.addRoom(bedroom, Direction::NORTH);

    const std::string name = "INF1015 KAWA & IMANE'S ROOM ADVENTURE";
    Game game(livingRoom, name);

    while (game.isRunning()) {
        std::string command = game.getUserInput();
        game.processCommande(command);
    }
    return 0;
}