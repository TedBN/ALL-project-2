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
    int manpowerProduction = 50;

    std::string name;
    std::string colour;
    std::vector <Army> defenseArmies;

    std::vector <Region> contiguousRegions;

    string getMapString (char symbolicRepresentation);

    void setMetalProduction(int metalProduction) {
        Region::metalProduction = metalProduction;
    }

    void setOilProduction(int oilProduction) {
        Region::oilProduction = oilProduction;
    }

    void setEnergyProduction(int energyProduction) {
        Region::energyProduction = energyProduction;
    }

    void setManpowerProduction(int manpowerProduction) {
        Region::manpowerProduction = manpowerProduction;
    }

    struct giveResourcesToCountry {};

    void formArmy();

    Region(const string &name) : name(name) {Army army; defenseArmies.push_back(army);}

    Region() {}

    virtual ~Region() {
    }

};


#endif //EUROPE_AT_WAR_REGION_H