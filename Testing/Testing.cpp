//
// Created by Oskars Pozdnakovs on 12/02/2017.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Manager.h"


class Game_Initialisation : public ::testing::Test {

public:
    virtual ~Game_Initialisation() {

        delete m;
    }

    virtual void SetUp() {
        m = new Manager;
        m->init_Spain();
        m->init_France();
        m->init_Poland();
    }

    Manager  *m;
    const int INIT_COUNTRIES = 3;
    array <string, 4> validCountryNames = {"Spain", "France", "Germany", "Poland"};

//    array <Country*, 3> theInitialisedCountries() {
//        array <Country*, 3> theInitialisedCountries;
//        theInitialisedCountries[0] = m->countries[0]; // SPAIN
//        theInitialisedCountries[1] = m->countries[1]; // FRANCE
//        theInitialisedCountries[2] = m->countries[3]; // POLAND
//
//        return theInitialisedCountries;
//    };
//    vector <Country*> validNeutralCountriesFor (Country * inCountry) {
//        vector <Country*> validNeutralCountries;
//        array <Country*, 3> theInitialisedCountries = theInitialisedCountries();
//
//        for (int i = 0; i < INIT_COUNTRIES; ++i) {
//            if (inCountry != theInitialisedCountries[i]) {
//                validNeutralCountries.push_back(theInitialisedCountries[i]);
//            }
//        }
//        return validNeutralCountries;
//    }
};



TEST_F(Game_Initialisation, Region_Initialisation_Test) {
    array <string, 8> validRegionNames;
    validRegionNames = {"Western Spain","Eastern Spain","Western France","Eastern France","Western Germany","Eastern Germany","Western Poland","Eastern Poland"};
    bool isNameValid;

    for (int i = 0; i < m->all_Regions.size() ; ++i) {
        isNameValid = find(begin(validRegionNames), end(validRegionNames), m->all_Regions[i].name) != end(validRegionNames);
        EXPECT_EQ(isNameValid, true);
        EXPECT_EQ(m->all_Regions[i].defenceArmies.size(), 1);
        EXPECT_EQ(m->all_Regions[i].metalStock, 50);
        EXPECT_EQ(m->all_Regions[i].metalProduction, 50);
        EXPECT_EQ(m->all_Regions[i].stockLimit, 200);
    }


    //cout<<"test2:"<<m->countriesInGame;


}

TEST_F(Game_Initialisation, Country_Initialisation_Test) {

    EXPECT_EQ(m->countriesInGame, INIT_COUNTRIES);


    bool isNameValid;
    int countryCounter = 0;

    for (int i = 0; i < m->countries.size(); ++i) {
        if (m->countries[i] != NULL){
            isNameValid = find(begin(validCountryNames), end(validCountryNames), m->countries[i]->countryName) != end(validCountryNames);
            EXPECT_EQ(isNameValid, true);
            countryCounter++;
        }
    }
    EXPECT_EQ(countryCounter, 3);
}
//
//TEST_F(Game_Initialisation, MakeCountriesNeutral_Test) {
//    m->makeCountriesNeutral();
//
//    for (int i = 0; i < INIT_COUNTRIES; ++i) {
//
//    };
//
//
//}

//
//int main(int argc, char* argv[]) {
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
//
//    Manager startGame;
//
//
//}