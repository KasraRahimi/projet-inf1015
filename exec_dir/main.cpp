// Projet final INF1015
// Auteurs : Rezki, Imane 2118881 - Rahimi, Kasra 2118712
// Équipe : 08

#include "Game.h"
#include "Key.h"
#include "Inventory.h"

int main() {
    Room livingRoom("Living Room",
        "The living room is a spacious room. It has a TV and a couch.");
    Room kitchen("Kitchen",
        "The kitchen has a fridge, an oven, and many pots and pans!");
    Room hallway("Hallway",
        "The hallway connects the living room to the bathroom. It's kinda dark. The light went out.",
        true);
    Room bathroom("Bathroom",
        "The bathroom has a toilet and a bathtub. It's rather small.");
    Room bedroom("Bedroom",
        "The bedroom is large. It has a bed and a desk. Your closet can be found here.",
        true);
    Room foyer("Foyer",
        "The foyer is at the entrance of the house. There are many more rooms to explore!");

    foyer.addRoom(livingRoom, Direction::NORTH);
    livingRoom.addRoom(kitchen, Direction::NORTH);
    livingRoom.addRoom(hallway, Direction::EAST);
    hallway.addRoom(bathroom, Direction::SOUTH);
    hallway.addRoom(bedroom, Direction::NORTH);

    const std::string name = "INF1015 KASRA & IMANE'S ROOM ADVENTURE";
    Game game(foyer, name);

    kitchen.getInventory().addItem(std::make_unique<Key>("small sticky blue key",
        "This key is blue and sticky. It's uncomfortable to touch. It seems rather small.",
        livingRoom,
        hallway,
        game));
    kitchen.getInventory().addItem(std::make_unique<Key>("small dry golden key",
        "This key is small, but it's golden and majestic. What could it be for?",
        hallway,
        bedroom,
        game));

    while (game.isRunning()) {
        std::string command = game.getUserInput();
        game.processCommand(command);
    }
    return 0;
}