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

    /** Class which provides to the player control over his country */
private:

    string name;
    vector <Country> allies ;
    vector <Country> enemies;


    vector <MilitaryUnit> militaryUnits;
    vector <Region> regions;
    char color_on_map;

    vector <resources> notifications;

    struct resources {
        string
        int money;
        int iron;
        int leather;
        int stone;
        int wood;
    } resources;

    // METHODS

    void sendReinforcement(Region region, MilitaryUnit militaryUnit) {};

    void attackRegion(Region region, MilitaryUnit militaryUnit);

    void collectResources(void) {};

    void addRegion(Region region) {};

    void buyUnits(int quantity); // <-----?????? Will be ready when Teodor presents his design

    void diplomacyRequest(Country fraction, char requestType);


public:
    Country(const string &name) : name(name) {}

};