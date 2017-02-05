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
    vector <Country> activeCountries;  // to-do Should or shouldn't I make it list type
    string allRegionMap;



//    void sendDiplomacy (Country recipient) {
//        countryInControl.diplomacyRequest(&countryInControl, &activeCountries.at(1), "Hello" , true, false,
//                false, false, 0, 1000, 1, 2, 3, 4);
//
//
//    }

    void initCountries( ) {
        /** A method to initialise a country after a user has chosen a country by the name.
         * Input is the string that is passed to the function after the user selected his country.
         * The country is initialised with pre-determined regions based on the user's choice of the country.
         * Once the Country object has been initialised, it is appended to the vector activeCountries;
         */

        string userInput;
        int userInputCounter = 0; // Counts how many times a user has entered valid input
        bool isInputValid;

        array <string, 5> validInputs = {"West", "North", "South", "East", "Next"};


        cout << "Select a country: ";


        do { // USER INPUT LOOP
        // Max 4 iterations of a valid input, userInputCounter keeps track of that

            for (int i = 0; i < validInputs.size(); i++) {
                if (validInputs[i] != "") {
                    // Condition to check which countries haven't been selected yet
                    // and output them.
                    cout << " > " << validInputs[i] ;
                }
            }
            cout << " to exit" << endl;
            cin >> userInput;

            // Checking weather or not the user input is in the list of valid input
            isInputValid = find(begin(validInputs), end(validInputs), userInput) != end(validInputs);

            if (isInputValid == false) {
                cout << "Invalid input, try again"<< endl;
                continue;}

            //  STARTS PROCESSING OF VALID INPUT

            for (int i = 0; i < validInputs.size(); i++) {
                // Replacing the matching value in the input list with ""
                if (validInputs[i] == userInput) {validInputs[i] = "";}
            }

            if(userInput == "West") {

                // A country is initialised with pre-set regions and name
                Country outCountry(ALL_REGIONS[0], ALL_REGIONS[1], "West");
                // The country is included into the Manager class' activeCountries vector.
                setActiveCountries(outCountry);


            } else if( userInput == "East") {

                // A country is initialised with pre-set regions and name
                Country outCountry(ALL_REGIONS[2], ALL_REGIONS[3],"East");
                // The country is included into the Manager class' activeCountries vector.
                setActiveCountries(outCountry);

            } else if( userInput == "North") {

                // A country is initialised with pre-set regions and name
                Country outCountry(ALL_REGIONS[4], ALL_REGIONS[5], "North");
                // The country is included into the Manager class' activeCountries vector.
                setActiveCountries(outCountry);

            } else  if (userInput == "South"){

                // A country is initialised with pre-set regions and name
                Country outCountry(ALL_REGIONS[6], ALL_REGIONS[7], "South");
                // The country is included into the Manager class' activeCountries vector.
                setActiveCountries(outCountry);

            }

            ++userInputCounter;

        } while ((userInputCounter < 4) && (userInput != "Next"));

        fillNeutralCountries(); // Procedure to set all the initialised countries neutral to each other.
    };

    void fillNeutralCountries () {
        /**A procedure to set all the initialised countries neutral to each other. */

        // to-do could it be done with ranged for?

        for (int i = 0; i < activeCountries.size(); i++) {
            // In range of all active countries, where each country is i,
            // In range of all active countries, where each country is j,
            // If i is not equal to j, then
            // include the country j into the country's i vector of neutral countries.

            for (int j = 0; j < activeCountries.size(); j++) {

                if (i != j) {
                    activeCountries.at(i).neutral.push_back(&activeCountries.at(j));
                }
            }
        }
    }

    void howManyCountries () {cout << activeCountries.size();}

    void initRegions() {
        /** Initialisation of class Region objects which have pre-determined member values.
         */

        for (int i = 0; i < ALL_REGIONS.size(); i++) {

            // From 0 to the size of the array ALL_REGIONS
            // to-do would there be a benefit from dynamic initialisation?

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