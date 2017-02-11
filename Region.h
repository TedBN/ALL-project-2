//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_REGION_H
#define EUROPE_AT_WAR_REGION_H


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>

#include "MilitaryUnit.h"
#include "Country.h"

using namespace std;

//   PRE - DECLARATION
class Country;
class Army;

// ### REGION & ARMY ###

class Region {

public:

// ###  ATTRIBUTES ###

    Country * owner;

    int                     metalProduction = 50;
    int                     oilProduction = 50;
    int                     energyProduction = 50;
    int                     stockLimit = 200;
    int                     metalStock = 50, oilStock = 50, energyStock = 50;
    std::string             name;
    std::vector <Army*>     defenceArmies;
    std::vector <Region*>   contiguousRegions;

//  #################


//  ### RESOURCES ###

    void                    regionalResourceCollection () {
        addToEnergyStock(Region::energyProduction);
        addToMetalStock(Region::metalProduction);
        addToOilStock(Region::oilProduction);
    };
    bool                    checkResourceAvailability(int metal, int oil, int energy) {
        /** This function will check if the specified amount of resources is available */

        if ( Region::metalStock >= metal  &&  Region::oilStock >= oil &&
             Region::energyStock >= energy) {
            return true;
        }
        else {
            return false;
        }
    }
    void                    deductResources (int metalStock, int oilStock, int energyStock) {
        Region::energyStock -= energyStock;
        Region::metalStock -= metalStock;
        Region::oilStock -= oilStock;

    }
    void                    addResources (int metal, int oil, int energy) {
        addToEnergyStock(energy);
        addToOilStock(oil);
        addToMetalStock(metal);
    }
    void                    addToMetalStock(int quantity) {
        Region::metalStock += quantity;
        if (metalStock > stockLimit) {
            metalStock = stockLimit;
        }
    }
    void                    addToOilStock(int quantity) {
        Region::oilStock += quantity;
        if (oilStock > stockLimit) {
            oilStock = stockLimit;
        }
    }
    void                    addToEnergyStock(int quantity) {
        Region::energyStock += quantity;
        if (energyStock > stockLimit) {
            energyStock = stockLimit;
        }
    }

//  ### REGION CONTROL ###

    void                    upgradeStockCapacity( ) {
        /** This function edits the attribute "stockLimit" increasing it by 25% if all of the current resources
         * in stock exceed 74%.
         */

        int requiredResource = stockLimit * 0.75;
        bool resourcesSufficient = checkResourceAvailability( requiredResource, requiredResource, requiredResource);

        if (resourcesSufficient) {
            stockLimit += stockLimit * 0.25;
            deductResources(requiredResource, requiredResource, requiredResource);
        } else { cout << "Insufficient resources ";
            return;}



    }
    void                    displayStats() {
        /** The function outputs the state of the object */

        cout << endl << ">>" << name << endl;

        cout << endl << "Energy production: " << energyProduction << endl;
        cout << "Metal production: " << metalProduction << endl;
        cout << "Oil production: " << oilProduction << endl << endl;

        cout << "Energy stock: " << energyStock << endl;
        cout << "Metal stock: " << metalStock << endl;
        cout << "Oil stock: " << oilStock << endl << endl;

        cout << "Stockpile: " << stockLimit << endl << endl;

        cout << "Army units: " << defenceArmies.size() << endl ;
    }

// ### ARMY CONTROL ###

    void recruitArmy () {

//        int requiredResource = stockLimit;
//
//        bool resourcesSufficient = checkResourceAvailability( requiredResource, requiredResource, requiredResource);
//
//        if (resourcesSufficient) {
//            Army * newArmy = new Army;
//            Region::defenceArmies.push_back(newArmy);
//            deductResources(requiredResource, requiredResource, requiredResource);
//
//        } else {
//            cout << "Insufficient resources ";
//            return;}

    }

// ### CONSTRUCTORS ###
    Region(const string &name, Army * defenceArmy) : name(name) { defenceArmies.push_back(defenceArmy); }
    Region() {}
    virtual ~Region() {}
};
//  ####################

class Army {

public:
// ###  ATTRIBUTES ###

    int         health = 100;
    string      name;
    Region*     currentLocation;
    Country*    owner;
    vector <MilitaryUnit> landArmy;

// ### CONSTRUCTORS ###

    Army() {}

};
//  ####################

#endif //EUROPE_AT_WAR_REGION_H