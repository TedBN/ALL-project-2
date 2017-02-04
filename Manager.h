//
// Created by Oskars Pozdnakovs on 30/01/2017.
//

#ifndef ALL_PROJECT_2_MANAGER_H
#define ALL_PROJECT_2_MANAGER_H

// to-do min 2 player game

#include "Country.h"
#include <array>


class Manager {

public:

    array <Region, 8> ALL_REGIONS;
    vector <Country> activeCountries;
    string allRegionMap;



    void initCountries( ) {
        /** A method to initialise a country after a user has chosen a country by the name.
         * Input is the string that is passed to the function after the user selected his country.
         * The country is initialised with pre-determined regions based on the user's choice of the country.
         * Once the Country object has been initialised, it is appended to the vector activeCountries;
         */

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



                Country outCountry(ALL_REGIONS[0], ALL_REGIONS[1], "West");

                setActiveCountries(outCountry);


            } else if( selectedCountry == "East") {


                Country outCountry(ALL_REGIONS[2], ALL_REGIONS[3],"East");

                setActiveCountries(outCountry);

            } else if( selectedCountry == "North") {


                Country outCountry(ALL_REGIONS[4], ALL_REGIONS[5], "North");

                setActiveCountries(outCountry);

            } else  if (selectedCountry == "South"){


                Country outCountry(ALL_REGIONS[6], ALL_REGIONS[7], "South");

                setActiveCountries(outCountry);

            }

            ++userInputCounter;
        } while ((userInputCounter < 4) && (selectedCountry != "Next"));

    };

    void howManyCountries () {cout << activeCountries.size();}

    void initRegions() {

        for (int i = 0; i < ALL_REGIONS.size(); i++) {
            switch (i) {
                case 0: { Region region0("Region_0"); ALL_REGIONS[i] = region0;
                    break;}
                case 1: { Region region1("Region_1"); ALL_REGIONS[i] = region1;
                    break;}
                case 2: { Region region2("Region_2"); ALL_REGIONS[i] = region2;
                    break;}
                case 3: { Region region3("Region_3"); ALL_REGIONS[i] = region3;
                    break;}
                case 4: { Region region4("Region_4"); ALL_REGIONS[i] = region4;
                    break;}
                case 5: { Region region5("Region_5"); ALL_REGIONS[i] = region5;
                    break;}
                case 6: { Region region6("Region_6"); ALL_REGIONS[i] = region6;
                    break;}
                case 7: { Region region7("Region_7"); ALL_REGIONS[i] = region7;
                    break;}
            }
        }
    };

    void turnInterfaceFor (Country countryInControl) {
//        cout << "Commands available" << endl;
//        cout << "dr - Send a diplomacy request" << endl;
//        cout << "Your command: ";
//
//        string command;
//        cin >> command;
//
//        if (command == "dr") {
//            countryInControl.diplomacyRequest()
//        }
    };

    void mainLoop () {

        int i = 0;
        while (activeCountries.size() > 1) {

            turnInterfaceFor(activeCountries.at(i));


            if ( i == sizeof(activeCountries) - 1) {
                i = 0;

            } else {i++;}
        }
    };

    void setActiveCountries(Country inCountry) {
        activeCountries.push_back(inCountry);
    }

    void formMap() { Region r("rrr");};

    void saveGame();
    void loadGame();


    Manager() {initRegions(); initCountries();}


};

#endif //ALL_PROJECT_2_MANAGER_H