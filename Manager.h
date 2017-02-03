//
// Created by Oskars Pozdnakovs on 30/01/2017.
//

#ifndef ALL_PROJECT_2_MANAGER_H
#define ALL_PROJECT_2_MANAGER_H

// to-do min 2 player game

#include "Country.h"


class Manager {

public:

    vector <Country> activeCountries;
    string allRegionMap;



    void initCountries() {
        /** A method to initialise a country after a user has chosen a country by the name.
         * Input is the string that is passed to the function after the user selects his country.
         * The country is initialised with pre-determined regions based on the user's choice of the country.
         * Once the Country object is initialised, it is appended to the vector activeCountries;
         */

        vector <Region> initialTerritory;

        string selectedCountry;
        int userInputCounter = 0;
        bool isInputValid;

        string notSelectedCountries[5] = {"West", "North", "South", "East", "Next"};

        cout << "Select a country: ";


        do {
            for (int i = 0; i < 5; i++) {
                if (notSelectedCountries[i] != "") {
                    cout << " > " << notSelectedCountries[i] ;
                }
            }
            cout << " to exit" << endl;
            cin >> selectedCountry;

            isInputValid = find(begin(notSelectedCountries), end(notSelectedCountries), selectedCountry) != end(notSelectedCountries);

            if (isInputValid == false) { cout << "Invalid input, try again"<< endl;
                continue;}

            for (int i = 0; i < 5; i++) {
                if (notSelectedCountries[i] == selectedCountry) {notSelectedCountries[i] = "";}
            }

            if(selectedCountry == "West") {

                initialTerritory.push_back(region1);
                initialTerritory.push_back(region2);
                initialTerritory.push_back(region3);

                Country outCountry(initialTerritory,"West");

                setActiveCountries(outCountry);


            } else if( selectedCountry == "East") {
                initialTerritory.push_back(region4);
                initialTerritory.push_back(region5);
                initialTerritory.push_back(region6);

                Country outCountry(initialTerritory,"East");

                setActiveCountries(outCountry);

            } else if( selectedCountry == "North") {
                initialTerritory.push_back(region1);
                initialTerritory.push_back(region2);
                initialTerritory.push_back(region3);

                Country outCountry(initialTerritory, "North");

                setActiveCountries(outCountry);

            } else  if (selectedCountry == "South"){
                initialTerritory.push_back(region1);
                initialTerritory.push_back(region2);
                initialTerritory.push_back(region3);

                Country outCountry(initialTerritory, "South");

                setActiveCountries(outCountry);

            }

            ++userInputCounter;
        } while ((userInputCounter < 4) && (selectedCountry != "Next"));

    };

    void howManyCountries () {cout << activeCountries.size();}

    void initRegions() {
        cout << "LOL?";
    };

    void turnInterfaceFor (Country countryInControl) {

    };

    void mainLoop () {

        int i = 0;
        while (activeCountries.size() > 1) {

            turnInterfaceFor(activeCountries.at(i));


            if ( i == sizeof(activeCountries) - 1) {
                i = 0;
                //Here the turn has ended,  You can do maintanance here

            } else {i++;}
        }
    };

    void setActiveCountries(Country inCountry) {
        activeCountries.push_back(inCountry);
    }

    void formMap();

    void saveGame();
    void loadGame();


    Manager() {initCountries();}


};

#endif //ALL_PROJECT_2_MANAGER_H