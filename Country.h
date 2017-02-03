//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_FRACTION_H
#define EUROPE_AT_WAR_FRACTION_H


#include <vector>

using namespace std;

#include "Region.h"

class Country;

class DiplomacyRequest {
    /** Class to enable a player to form alliances, declare war or exchange with resources.
     *
     * An object of this class will be inserted into the receiving country class object's vector, pendingDiplomacy, to get presented.
     * */




public:
    Country *issuerCountry;
    string message;
    bool formAlliance = false;
    bool breakAlliance = false;
    bool declareWar = false;
    bool ceasfire = false;
    int aPassRight = 0;
    int money = 0;
    int metal = 0;
    int oil = 0;
    int energy = 0;
    int manpower = 0;

    void acceptRequest();

    void declainRequest();

public:
    DiplomacyRequest(Country *issuerCountry, int money) : issuerCountry(issuerCountry), money(money) {}

};

class Country {

    /** Class that encapsulates data about the state of player's country and provides member functions for minor control */

public:

    string countryName; // User defined name for his country

    vector <Country> allies ; // Vector to comprise allies of the country
    vector <Country> enemies; // Enemies of the country
    vector <Country> aPassRight; // Permission to cross other country's border


    vector <Region> regions; // Vector to comprise regions under the country's control

    char color_on_map; // Colour by which the country is represented on the map

    vector <DiplomacyRequest> pendingDiplomacy; // List of pending notifications by diplomacyRequest()

    struct resources { // Country's wealth
        int money;
        int metal;
        int oil;
        int energy;
        int manpower;
    } resources;

    // METHODS

    void askResourcesFromRegions() {   };
             // to-do implement as independent function

    void addNewRegion(Region region) {};
    void loseRegion (Region region) {};
    void sendDiplomacyRequest(Country recipient);

    Country(const vector<Region> &regions, string name) : regions(regions), countryName(name) {}
} ;

#endif //EUROPE_AT_WAR_FRACTION_H