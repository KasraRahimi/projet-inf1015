// Projet final INF1015
// Auteurs : Rezki, Imane 2118881 - Rahimi, Kasra 2118712
// Équipe : 08

#include "Game.h"
#include "MiscellaneousItem.h"
#include "Key.h"
#include "Passage.h"
#include "Inventory.h"

int main() {
    Room foyer("foyer",
        "This is the entrance to the house. Not much to see here.");
    Room livingRoom("living room",
        "This room is so cozy. There's a couch and TV!");
    Room kitchen("kitchen", 
        "Pots, pans, and dishes everywhere! Even the faucet is broken! Someone should really fix up this room. ");
    Room hallway1("first hallway",
        "This is the section of the hallway connected to the living room.");
    Room hallway2("second hallway",
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
        "This is the fanciest bathroom I've ever seen in my life. The toilet is made of gold! The toilet paper is made of $100 bills!");
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

    auto pianoPtr = std::make_unique<MiscellaneousItem>("suspicious old piano", 
    "This is an antique Steinway & Sons with 85 keys. It looks like dark and sinister, probably from the late 1860s.", 
    false, 
    "You play some chords on the piano. It does not sound very well.");
    pianoRoom.getInventory().addItem(std::move(pianoPtr));

    auto paintingPtr = std::make_unique<MiscellaneousItem>("sinister painting", 
    "A mother sheep stands over the dead body of its lamb, surrounded by a murder. It is a gruesome landscape.", 
    false, 
    "Nothing to do here, but you're creeped out. Try resting someplace less intense.");
    pianoRoom.getInventory().addItem(std::move(paintingPtr));

    auto candlePtr = std::make_unique<TwoUsesItem>("wax candle", 
    "An unlit wax candle. This could light the way ahead...",
    true,
    hallway1,
    game,
    "You strike a match and light up the candle. The wax steadily melts down unto the saucer.",
    "You blow out the candle. \033[3mOut, out, brief candle!\033[0m");
    kitchen.getInventory().addItem(std::move(candlePtr));

    auto bookPtr = std::make_unique<Book>("beautiful leatherbound book", 
    "It is resting on the bedside table. The pages open to Act V, Scene 5.", 
    true, 
    "\n\t\033[3mTomorrow, and tomorrow, and tomorrow, \n\tCreeps in this petty pace from day to day, \n\tTo the last syllable of recorded time...\n\033[0m");
    bedroom.getInventory().addItem(std::move(bookPtr));

    auto bedPtr = std::make_unique<MiscellaneousItem>("comfortable bed", 
    "It looks soft and pillowy, almost cartoonish", 
    false, 
    "You tuck yourself into bed. \033[3mYou sleep for what feels like a very long time, yet hardly any time has passed...\033[0m");
    bedroom.getInventory().addItem(std::move(bedPtr));

    auto clockPtr = std::make_unique<Clock>("small pocket watch", 
    "It is silver and encrusted in rubies, a bit rusted but still beautiful.", 
    true);
    livingRoom.getInventory().addItem(std::move(clockPtr));

    auto telescopePtr = std::make_unique<SingleUseItem>("telescope",
    "This telescope is quite impressive, you may want to \033[3mstudy\033[0m the stars when you get the chance.",
    "You carefully align the telescope in front of the big bay window. You look in and see...\n\t\033[3mthe Christmas Star !\033[0m\n",
    study,
    game);
    basement.getInventory().addItem(std::move(telescopePtr));

    auto panFlutePtr = std::make_unique<SingleUseItem>("pan flute",
    "There are many different sized glass pipes. You can see your hands through it, almost like fish under water.",
    "\n\033[3ma beautiful melody erupts!\033[0m\n Birds and animals curiously approach, curious to see the newcomer.\nYou see a magestic lion coming towards you.\n",
    narnia,
    game);
    bathroom.getInventory().addItem(std::move(panFlutePtr));
// Add Aslan giving Patron Saint Key to the realm honorary member if pan flute is played twice

    auto srewDriverPtr = std::make_unique<SingleUseItem>("screw driver",
    "Standard srew driver. Nothing special here.",
    "You successfully fixed the broken faucet. Whoever lives here will greatly appreciate it.",
    kitchen,
    game);
    kitchen.getInventory().addItem(std::move(srewDriverPtr));

    auto dirtyPotPtr = std::make_unique<TwoUsesItem>("dirty copper pot",
    "The pot is covered in grime, it could use some cleaning.",
    true,
    kitchen,
    game,
    "You successfully cleaned the dirty pot. You may use it to make a delicious meal.",
    "You have prepared a delicious Christmas Eve meal, if only you had someone to share it with...\n\033[3myou hear laughter in the walls\033[0m");
    kitchen.getInventory().addItem(std::move(dirtyPotPtr));

    auto ceramicMaskPtr = std::make_unique<SingleUseItem>("white half-face ceramic mask",
    "Eerie looking mask...it reminds you of something, but you can't quite place it.",
    "The light shakes, you hear a booming voice singing an aria. Shaken, you quickly put the mask away.",
    bathroom,
    game);
    livingRoom.getInventory().addItem(std::move(ceramicMaskPtr));

    auto noteBookPtr = std::make_unique<NoteBook>("small nearly full notebook", 
    "This notebook is nearly full, you could write down a couple things if you'd like.", 
    true, 
    3);
    livingRoom.getInventory().addItem(std::move(noteBookPtr));

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