//
// Created by Oskars Pozdnakovs on 30/01/2017.
//

#ifndef ALL_PROJECT_2_MANAGER_H
#define ALL_PROJECT_2_MANAGER_H


#include "Country.h"
#include <array>


class Manager {

public:

    int turn = 1; // Keeps track of the current turn;
    int countriesInGame; // Quantity of currently active countries
    array  <Region, 8> ALL_REGIONS;
    array <Country*,4> countries = {NULL, NULL, NULL, NULL};
    string allRegionMap;



    void sendDiplomacy () {

        countries.at(0)->diplomacyRequest(countries.at(0), countries.at(1), "Hello" , true, false,
                false, false, 0, 1000, 1, 2, 3, 4);
    }

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
                Country *outCountry = new Country(ALL_REGIONS[0], ALL_REGIONS[1], "West");
                // The country is included into the Manager class' countries vector.
                countries[3] = outCountry;


            } else if( userInput == "East") {

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(ALL_REGIONS[2], ALL_REGIONS[3],"East");
                // The country is included into the Manager class' countries vector.
                countries[0] = outCountry;

            } else if( userInput == "North") {

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(ALL_REGIONS[4], ALL_REGIONS[5], "North");
                // The country is included into the Manager class' countries vector.
                countries[1] = outCountry;

            } else  if (userInput == "South"){

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(ALL_REGIONS[6], ALL_REGIONS[7], "South");
                // The country is included into the Manager class' countries vector.
                countries[2] = outCountry;
            }

            ++userInputCounter;

        } while ((userInputCounter < 4) && (userInput != "Next"));

        Manager::countriesInGame = userInputCounter; // Save the quantity of initialised countries


        fillNeutralCountries(); // Procedure to set all the initialised countries neutral to each other.

    };

    void fillNeutralCountries () {
        /**A procedure to set all the initialised countries neutral to each other. */

        // to-do could it be done with ranged for?

        for (int i = 0; i < countries.size(); i++) {
            // In range of pointers to all active countries, where each pointer to a country is i,
            // If i points to NULL, then next iteration, else
            // In range of all active countries, where each country is j,
            // If j points to NULL, then next iteration, else
            // If i is not equal to j, then
            // include the pointer to the country j into the country's i vector of pointers to neutral countries.

            if (countries[i] == NULL) { continue; }

            for (int j = 0; j < countries.size(); j++) {

                if (i != j && countries[j] != NULL) {
                    countries[i]->neutral.push_back(countries[j]);
                }
            }
        }
    }

    void howManyCountries () {cout << countries.size();}

    void initRegions() {
        /** Initialisation of class Region objects which have pre-determined member values.
         */

        for (int i = 0; i < ALL_REGIONS.size(); i++) {

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
        /** A function to provide player with a control interface of his country.
         * The mainLoop() passes a Country object into argument of the function
         * where the user gets to enter commands to invoke functions which alter the
         * state of the program.
         *
         * Loop operates in the function which lets the user enter commands until
         * the procedure to switch the turn is called.
         *
         */


        cout << "[ "<< Manager::turn << " ] >>> " << countryInControl.countryName << " <<<" << endl;
        cout << "Commands available" << endl;
        cout << "end - Call destructor" << endl;
        cout << "et - End turn" << endl;


        string command;

        while (true == true) {
            cout << "Your command: ";
            cin >> command;

            if (command == "end") {
                Manager::~Manager();
                return;

            } else if (command == "et") { return; }

            else {
                cout << "Unknown Command, try again" << endl;
                continue;
            };
        }
    }

    void mainLoop() {
        /**
         * Iterate until Manager::activeCountries > 1 {
         *
         * if the pointer [i] in the array "countries" is NULL, then i++ and switch to next iteration, else
         *
         * provide the country at "countries[i]" with control interface.
         *
         * if i is equal to the size of "countries", set it to 0, increment the current turn counter and switch to next iteration, else
         *
         * increment i and repeat.
         *
         * }
         */

        int i = 0;



        while (Manager::countriesInGame > 1) {

            // to-do implement a function to destruct a Country object and decrement Manager::countriesInGame

            if (countries[i] == NULL) {
                i++;
                continue;}

            turnInterfaceFor(*countries.at(i));

            if (i == countries.size() - 1) {
                i = 0;
                Manager::turn++;
                continue; }

            i++;

        }
    };


    void formMap() { Region r("rrr"); };

    void saveGame();
    void loadGame();


    Manager()
    {
        initRegions();
        initCountries();
        mainLoop();
    }

    virtual ~Manager() {
        cout << "The End" << endl;
        for ( int i = 0; i < countries.size(); i++) {


            if (countries[i] != NULL) {
            cout << countries[i]->countryName << " removed from the heap" << endl;
            delete countries[i];
            countries[i] = NULL;
                // to-do resolve destruction issue

            }

        }

        countriesInGame = 0;
    }

};


#endif //ALL_PROJECT_2_MANAGER_H