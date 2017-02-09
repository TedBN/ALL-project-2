//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_REGION_H
#define EUROPE_AT_WAR_REGION_H



#include "fstream"
#include "string"
#include "vector"

#include "MilitaryUnit.h"

class Region;


class Army {

    string name;
    int health = 100;
    Region *currentLocation;

    std::vector <MilitaryUnit> landArmy;

public:

    string txt = "I do exist";
    Army() {}


};

class Region {

public:

//    fstream mapFile;

    int metalProduction = 50;
    int oilProduction = 50;
    int energyProduction = 50;

    int stockPile = 100;

    int metalStock = stockPile, oilStock = stockPile, energyStock = stockPile;

    std::string name;
    std::string colour;

    std::vector <Army*> defenceArmies;
    std::vector <Region*> contiguousRegions;

    string getMapString (char symbolicRepresentation);


    void upgradeStockPile( ) {

        int requiredResource = stockPile * 0.75;
        bool resourcesSufficient = checkResourceAvailability( requiredResource, requiredResource, requiredResource);

        if (resourcesSufficient) {
            stockPile += stockPile * 0.25;
            deductResources(requiredResource, requiredResource, requiredResource);
        } else { cout << "Insufficient resources ";
            return;}



    }

    bool checkResourceAvailability(int metal, int oil, int energy) {
        if ( Region::metalStock >= metal  &&  Region::oilStock >= oil &&
                Region::energyStock >= energy) {
            return true;
        }
        else {
            return false;
        }
    }

    void deductResources (int metalStock, int oilStock, int energyStock) {
        Region::energyStock -= energyStock;
        Region::metalStock -= metalStock;
        Region::oilStock -= oilStock;

    }
    void addResources (int metalStock, int oilStock, int energyStock) {
        Region::energyStock += energyStock;
        Region::metalStock += metalStock;
        Region::oilStock += oilStock;
    }
    void displayStats() {

        cout << endl << ">>" << name << endl;

        cout << endl << "Energy production: " << energyProduction << endl;
        cout << "Metal production: " << metalProduction << endl;
        cout << "Oil production: " << oilProduction << endl << endl;

        cout << "Energy stock: " << energyStock << endl;
        cout << "Metal stock: " << metalStock << endl;
        cout << "Oil stock: " << oilStock << endl << endl;

        cout << "Stockpile: " << stockPile << endl << endl;

        cout << "Army units: " << defenceArmies.size() << endl ;
    }

    void recruitArmy () {

        int requiredResource = stockPile;

        bool resourcesSufficient = checkResourceAvailability( requiredResource, requiredResource, requiredResource);

        if (resourcesSufficient) {
            Army * newArmy = new Army;
            Region::defenceArmies.push_back(newArmy);
            deductResources(requiredResource, requiredResource, requiredResource);

        } else {
            cout << "Insufficient resources ";
            return;}

    }

    void controlRegion() {


    }

    struct giveResourcesToCountry {  };

    void formArmy();

    Region(const string &name) : name(name) {Army *army = new Army; defenceArmies.push_back(army);}

    Region() {}

    virtual ~Region() {
    }

};


#endif //EUROPE_AT_WAR_REGION_H