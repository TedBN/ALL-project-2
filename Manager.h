//
// Created by Oskars Pozdnakovs on 30/01/2017.
//

#ifndef ALL_PROJECT_2_MANAGER_H
#define ALL_PROJECT_2_MANAGER_H


#include "Country.h"
#include <array>
#include <map>


class Manager {

public:

    int turn = 1; // Keeps track of the current turn;
    int countriesInGame; // Quantity of currently active countries
    array  <Region, 8> ALL_REGIONS;
    array <Country*,4> countries = {NULL, NULL, NULL, NULL};
    string allRegionMap;


    void sendDiplomacy (Country * issuer) {

        map <string, Country*> countriesMap;
        int index = 1;
        string key;
        string userInput;
        string userMessage;

        for (int i = 0; i < countries.size(); i ++) {
            // Creates a map container of enumerated active countries;
            if (countries[i] != NULL && countries[i] != issuer) {

                key = to_string(index);
                countriesMap[key] = countries[i];
                index++;
            }
        }

        cout << "Select recipient country:" << endl;
        // to-do Input validation
        for (map<string, Country*>::iterator it = countriesMap.begin(); it != countriesMap.end(); it++) {
            cout << it->first << ": " << it->second->countryName << endl;
        }

        cin >> userInput;

//        cout << countriesMap[userInput]->countryName << endl;



        cout << "Your message to " << countriesMap[userInput]->countryName << ": ";

        cin.ignore();
        std::getline(std::cin,userMessage);



        DiplomacyRequest *request = new DiplomacyRequest(issuer, countriesMap[userInput], userMessage , true, false,
               false, false, 0, 1000, 1, 2, 3, 4, 2);
        // to-do is this pointer deleted after the function is terminated?

        countriesMap[userInput]->pendingDiplomacy.push_back(request);

        return;

    }

    void controlInterface(Country *countryInControl) {
        /** A function to provide player with a control interface of his country.
         * The mainLoop() passes a Country object into argument of the function
         * where the user gets to enter commands to invoke functions which alter the
         * state of the program.
         *
         * Loop operates in the function which lets the user enter commands until
         * the procedure to switch the turn is called.
         *
         */


        cout << "[ "<< Manager::turn << " ] >>> " << countryInControl->countryName << " <<<" << endl << endl;

        cout << "1: Make a diplomacy request" << endl;
        cout << "2: Display pending diplomacy requests [" << countryInControl->pendingDiplomacy.size() << "]" << endl;
        cout << "3: Display regions" << endl;
        cout << "4: End turn" << endl;

        char command;

        while (true == true) {  // MAINLOOP
            cout << endl << "Your command: ";
            cin >> command;
            cout << endl;

            switch (command) {
                case ('1'): {
                    sendDiplomacy(countryInControl);
                    break;
                }
                case ('2'): {
                    // to-do implement as a function;
                    for (int i = 0; i < countryInControl->pendingDiplomacy.size(); ++i) {
                        cout << endl;
                        cout << "From: " << countryInControl->pendingDiplomacy.at(i)->issuerCountry->countryName
                             << endl;
                        cout << "Message: " << endl << countryInControl->pendingDiplomacy.at(i)->getMessage() << endl;
                    }
                    break;
                }
                case ('3'): {
                    Region *selectedRegion;
                    string functionOutcome;

                    do {
                        selectedRegion = countryInControl->inputRegion(NULL);
                        if (selectedRegion == NULL) { break; }
                        functionOutcome = countryInControl->regionControlInterface(selectedRegion);
                    } while (functionOutcome == "back to region selection");
                    break;
                }
                case ('4'): {
                    return;
                }


            }

        }

//            if (command == "end") {
//                Manager::~Manager();
//                return;
//
//            } else if (command == "et") {
//                return;
//
//            } else if (command == "dr") {
//
//
//            } else if (command == "ddr") {
//                // to-do implement as a function;
//                for (int i = 0; i < countryInControl->pendingDiplomacy.size(); ++i) {
//                    cout << endl;
//                    cout << "From: " << countryInControl->pendingDiplomacy.at(i)->issuerCountry->countryName << endl;
//                    cout << "Message: " << endl << countryInControl->pendingDiplomacy.at(i)->getMessage() << endl;
//                }
//                cout << endl;
//
//            } else if (command == "d_reg") {
//
//
//
////                if (selectedRegion == NULL) {
////                    continue;
////                } else { selectedRegion->displayStats(); }
//
//            }else {
//                cout << "Unknown Command, try again" << endl << endl;
//            };
//
//        }
    }

//  ###############################
//  ####### INITIALISATION ########

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
    void initCountries() {
        /** A method to initialise a country after a user has chosen a country by the name.
         * Input is the string that is passed to the function after the user selected his country.
         * The country is initialised with pre-determined regions based on the user's choice of the country.
         * Once the Country object has been initialised, it is appended to the vector activeCountries;
         */

        string userInput;
        int userInputCounter = 0; // Counts how many times a user has entered valid value
        bool isInputValid;

        array <string, 5> validInputs = {"West", "North", "South", "East", "Continue"};


        cout << "Select a country: " << endl ;


        do { // USER INPUT LOOP
            // Max 4 iterations of a valid input, userInputCounter keeps track of that

            for (int i = 0; i < validInputs.size(); i++) {
                if (validInputs[i] != "") {
                    // Condition to check which countries haven't been selected yet
                    // and output them.
                    cout << validInputs[i] <<endl;
                }
            }

            cout << "-> ";
            cin >> userInput;
            cout << endl;

            // Checking weather or not the user input is in the list of valid input
            isInputValid = find(begin(validInputs), end(validInputs), userInput) != end(validInputs);

            if (isInputValid == false) {
                cout << "Invalid input, try again"<< endl << endl;
                continue;}

            //  STARTS PROCESSING OF VALID INPUT

            for (int i = 0; i < validInputs.size() - 1; i++) {
                // Replacing the matching value in the input list with ""
                if (validInputs[i] == userInput) {validInputs[i] = "";}
            }

            if(userInput == "West" ) {

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(&ALL_REGIONS[0], &ALL_REGIONS[1], "West");
                // The country is included into the Manager class' countries vector.
                countries[3] = outCountry;


            } else if( userInput == "East") {

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(&ALL_REGIONS[2], &ALL_REGIONS[3],"East");
                // The country is included into the Manager class' countries vector.
                countries[0] = outCountry;

            } else if( userInput == "North") {

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(&ALL_REGIONS[4], &ALL_REGIONS[5], "North");
                // The country is included into the Manager class' countries vector.
                countries[1] = outCountry;

            } else  if (userInput == "South"){

                // A country is initialised with pre-set regions and name
                Country *outCountry = new Country(&ALL_REGIONS[6], &ALL_REGIONS[7], "South");
                // The country is included into the Manager class' countries vector.
                countries[2] = outCountry;

            } else if (userInput == "Continue") {
                if (userInputCounter < 2) {
                    cout << "At least 2 countries required. You have: " << userInputCounter << endl << endl;
                    continue;}
                else { break;}
            }

            ++userInputCounter;

        } while (userInputCounter < 4) ;

        Manager::countriesInGame = userInputCounter; // Save the quantity of initialised countries




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

            controlInterface(countries.at(i));

            if (i == countries.size() - 1) {
                i = 0;
                Manager::turn++;
                continue; }

            i++;

        }
    };

//  #### END OF INITIALISATION ####
//  ###############################


    void formMap() { Region r("rrr"); };
    void saveGame();
    void loadGame();


    Manager()
    {
        initRegions();
        initCountries();
        fillNeutralCountries(); // Procedure to set all the initialised countries neutral to each other.
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