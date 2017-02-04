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
    Country *recipientCountry;

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
    DiplomacyRequest(Country *issuerCountry, Country *recipientCountry, const string &message, bool formAlliance,
                     bool breakAlliance, bool declareWar, bool ceasfire, int aPassRight, int money, int metal, int oil,
                     int energy, int manpower) : issuerCountry(issuerCountry), recipientCountry(recipientCountry),
                                                 message(message), formAlliance(formAlliance),
                                                 breakAlliance(breakAlliance), declareWar(declareWar),
                                                 ceasfire(ceasfire), aPassRight(aPassRight), money(money), metal(metal),
                                                 oil(oil), energy(energy), manpower(manpower) {}

};

class Country {

    /** Class that encapsulates data about the state of player's country and provides member functions for minor control */

public:

    string countryName; // User defined name for his country

    // to-do class' member variable as pointer to mmry location

    vector <Country> allies ; // Vector to comprise allies of the country
    vector <Country> enemies; // Enemies of the country
    vector <Country> aPassRight; // Permission to cross other country's border


    vector <Region> regions; // Vector to comprise regions under the country's control

    char color_on_map; // Colour by which the country is represented on the map

    void diplomacyRequest (Country *issuerCountry, Country *recipientCountry,  string message, bool formAlliance,
                           bool breakAlliance, bool declareWar, bool ceasfire, int aPassRight, int money, int metal, int oil,
                           int energy, int manpower) {

        DiplomacyRequest dr(issuerCountry, recipientCountry, message, formAlliance, breakAlliance, declareWar,
                            ceasfire, aPassRight, money, metal, oil, energy, manpower); }


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

    Country(Region region1, Region region2, string name) : countryName(name) {
        regions.push_back(region1);
        regions.push_back(region2);
    }
} ;

#endif //EUROPE_AT_WAR_FRACTION_H