

//
// Created by Oskars Pozdnakovs on 12/02/2017.
//
/**
 *      STRUCTURE:
 *      Manager.h: Manager
 *      Country.h: DipolmacyRequest, Country, MilitaryAccess
 *      Region.h: Region, Army
 *
 *      A new game is started when an object of the "Manager" class is instantiated. The only pre-determined
 *      methods which are called for this object belong to initialisation of requisite objects for the game to become functional.
 *
 *
 *      The game is initialised with 8 unique "Region" objects which will be associated with a "country" at its initialisation.
 *      The regions have containers of "defence armies" and capability to produce and store resources. Resources can be transferred
 *      between "regions" of a particular country or added to a "diplomacy request" addressed to other country.
 *
 *      The maximal number of initialisable countries is 4. Each country has a unique name, unique collection of "regions"
 *      to start with and it may or may not be initialised which depends on the selection made by players. At the beginning
 *      of a game, a function includes in each "country's" vector: "neutral" pointers to the other countries, which will represent
 *      a neutral status between them. The vector "countries" in the "Manager" class contains the pointers to all the initialised
 *      regions.
 *
 *      Once the function has completed its task the main loop will start to operate until only one pointer to a "Country" object
 *      object is left in the "countries" vector. At each iteration of the mainloop, a function that provides control interface
 *      to a country is called and the player can input commands into the console to interact with the system.
 *      */



#include "Manager.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
cout << "Please enter either New Game or MiniGame" << endl;
std::string input = "Null";
while(true){
    cin >> input;
    if (input == "Minigame" || input == "minigame"){
        std::system("./Minigame");
    }
    else if (input == "New Game" || input == "new game" || input == "New game"{
    Manager newGame;
    

    INITIALISATION OF REQUISITE OBJECTS FOR THE GAME
    newGame.initRegions();
    newGame.init_Countries();
    newGame.makeCountriesNeutral();
    newGame.mainLoop();
    }
}
}
