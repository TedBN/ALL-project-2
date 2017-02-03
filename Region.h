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
    int health;
    Region *currentLocation;

    std::vector <MilitaryUnit> landArmy;



};

class Region {

public:

//    fstream mapFile;

    int metalProduction = 50;
    int oilProduction = 50;
    int energyProduction = 50;
    int manpowerProduction = 50;

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

    Region() {}

}region1, region2, region3, region4, region5, region6, region7, region8, region9;


#endif //EUROPE_AT_WAR_REGION_H