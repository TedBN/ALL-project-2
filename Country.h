//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_FRACTION_H
#define EUROPE_AT_WAR_FRACTION_H

#endif //EUROPE_AT_WAR_FRACTION_H

#include <iostream>
#include "Region.h"
#include "vector"
#include "string"


using namespace std;


class Country {

    /** Class that encapsulates the state of player's country and provides member functions for simple control */

private:

    string name; // User defined name for his country

    vector <Country> allies ; // Vector to comprise allies of the country
    vector <Country> enemies; // Enemies of the country


    vector <MilitaryUnit> militaryUnits; // Vector of military units at the country's disposal

    vector <Region> regions; // Vector to comprise regions under the country's control

    char color_on_map; // Colour by which the country is represented on the map

    vector <vector> notifications; // List of pending notifications by diplomacyRequest()

    struct resources { // Country's wealth
        int money;
        int metal;
        int oil;
        int energy;
        int manpower;
    } resources;

    // METHODS

    void sendReinforcement(Region region, MilitaryUnit militaryUnit) {};

    void attackRegion(Region region, MilitaryUnit militaryUnit);

    void collectResources(void) {};

    void addRegion(Region region) {};

    void buyUnits(int quantity); // <-----?????? Will be ready when Teodor presents his design

public:
    Country(const string &name) : name(name) {}

};