// Projet final INF1015
// Auteurs : Rezki, Imane 2118881 - Rahimi, Kasra 2118712
// Équipe : 08

#include "Game.h"
#include "Key.h"
#include "Passage.h"
#include "Inventory.h"

int main() {
    Room foyer("foyer",
        "This is the entrance to the house. Not much to see here.");
    Room livingRoom("living room",
        "This room is so cozy. There's a couch and TV!");
    Room kitchen("kitchen", 
        "Pots, pans, and dishes everywhere! Someone should really clean up here.");
    Room hallway1("hallway1",
        "This is the section of the hallway connected to the living room.");
    Room hallway2("hallway2",
        "This section of the hallway is connected to the bedroom.");
    Room bedroom("bedroom",
        "A nice bed, a good amount of storage. Hmm this seems like a nice bedroom");
    Room pianoRoom("piano room",
        "This room is a mess. Sheet music everywhere, spider webs in every corner. How could someone let it get this bad?",
        true);
    Room closet("closet",
        "This appears to be a regular closet. What can I find in here?");
    Room narnia("narnia",
        "Holy cow, this place is magical! Why do I have to pass through a closet to get here?",
        true);
    Room study("study",
        "This room is a little messy, nothing too bad. It's just a little too dark.",
        true);
    Room bathroom("bathroom",
        "This is the fanciest bathroom I've ever seen in my life. \
        The toilet is made of gold! The toilet paper is made of $100 bills!");
    Room basement("basement",
        "This place is humid and dark. There are boxes everywhere but nothing worth taking. The pipes are leaking water onto the floor. I don't like it here");

    livingRoom.addRoom(foyer, Direction::SOUTH);
    livingRoom.addRoom(kitchen, Direction::NORTH);
    livingRoom.addRoom(hallway1, Direction::EAST);

    hallway1.addRoom(pianoRoom, Direction::SOUTH);
    hallway1.addRoom(hallway2, Direction::EAST);

    closet.addRoom(pianoRoom, Direction::NORTH);
    closet.addRoom(narnia, Direction::SOUTH);

    hallway2.addRoom(study, Direction::NORTH);
    hallway2.addRoom(bedroom, Direction::EAST);
    hallway2.addRoom(bathroom, Direction::SOUTH);

    const std::string name = "INF1015 KASRA & IMANE'S ROOM ADVENTURE";
    Game game(foyer, name);

    auto pianoRoomKeyPtr = std::make_unique<Key>("large silver key",
        "This key seems large and important. It's a little rusty.",
        hallway1,
        pianoRoom,
        game);
    auto narniaKeyPtr = std::make_unique<Key>("tiny rainbow colored key",
        "Really weird key. It doesn't look normal at all. What could it be for?",
        closet,
        narnia,
        game);
    auto studyKeyPtr = std::make_unique<Key>("mid-sized golden key",
        "This key seems majestic. Golden colored and everything!",
        hallway2,
        study,
        game);
    auto stairsPtr = std::make_unique<Passage>("slightly moldy stairway", 
        "These stairs seem questionable. They're not well maintened.",
        basement,
        bedroom,
        game);
    auto slidePtr = std::make_unique<Passage>("neat out-of place slide",
        "This slide is suspicious. It leads to a dark place and looks like it has no place in a study.",
        study,
        basement,
        game,
        false);

    kitchen.getInventory().addItem(std::move(pianoRoomKeyPtr));
    closet.getInventory().addItem(std::move(narniaKeyPtr));
    narnia.getInventory().addItem(std::move(studyKeyPtr));
    basement.getInventory().addItem(std::move(stairsPtr));
    study.getInventory().addItem(std::move(slidePtr));
    while (game.isRunning()) {
        std::string command = game.getUserInput();
        game.processCommand(command);
    }
    return 0;
}