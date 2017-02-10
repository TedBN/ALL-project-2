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

//  ##################
//  ### ATTRIBUTES ###

    int turn = 1;               // Keeps track of the current turn;
    int countriesInGame;        // Quantity of currently active countries
    array   <Region, 8>         ALL_REGIONS;
    array   <Country *, 4>     countries = {NULL, NULL, NULL, NULL};

//  ##################

//  ### INITIALISATION ###

    void initRegions() {
        /** Initialisation of class Region objects which have pre-determined member values.
         */

        for (int i = 0; i < ALL_REGIONS.size(); i++) {

            // to-do would there be a benefit from dynamic initialisation?

            switch (i) {
                case 0: {
                    Army *army = new Army;
                    Region region0("Region_0", army);
                    ALL_REGIONS[i] = region0;
                    break;}
                case 1: {
                    Army *army = new Army;
                    Region region1("Region_1", army);
                    ALL_REGIONS[i] = region1;
                    break;}
                case 2: {
                    Army *army = new Army;
                    Region region2("Region_2", army);
                    ALL_REGIONS[i] = region2;
                    break;}
                case 3: {
                    Army *army = new Army;
                    Region region3("Region_3", army);
                    ALL_REGIONS[i] = region3;
                    break;}
                case 4: {
                    Army *army = new Army;
                    Region region4("Region_4", army);
                    ALL_REGIONS[i] = region4;
                    break;}
                case 5: {
                    Army *army = new Army;
                    Region region5("Region_5", army);
                    ALL_REGIONS[i] = region5;
                    break;}
                case 6: {
                    Army *army = new Army;
                    Region region6("Region_6", army);
                    ALL_REGIONS[i] = region6;
                    break;}
                case 7: {
                    Army *army = new Army;
                    Region region7("Region_7", army);
                    ALL_REGIONS[i] = region7;
                    break;}
            }
        }
    }      //   init_Regions()
    void init_Countries() {
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




    }   //   init_Countries()
    void fill_Neutral() {
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
    }     //   fill_Neutral()
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

            C_ControlInterf(countries.at(i));

            if (i == countries.size() - 1) {
                i = 0;
                Manager::turn++;
                continue; }

            i++;

        }
    };        //   MAINLOOP


//  ###    DIPLOMACY   ###

    void    new_DRequest     (Country *issuer) {
// to-do exceptions management for input validation cin >> energy
        Country *recipient;
        char userInput;
        string userMessage;

        bool formAlliance = false;
        bool ceasefire = false;
        int aPassRight = 0;

        int metal = 0;
        int oil = 0;
        int energy = 0;

        int periodOfValidity = 1;

        recipient = input_Country(issuer);
        if (recipient == NULL) { return;}

        while (true) {

            // to-do what is the effective way to do it so that enumeration changes as an option disappears??

            cout << endl << "1: Offer to " << recipient->countryName << endl;
            cout << "2: Demand from " << recipient->countryName << endl;
            cout << "3: Add message" << endl;
            cout << "4: Confirm" << endl;
            cout << "5: Cancel" << endl;

            cin >> userInput;

            while (true) {
                switch (userInput) {
                    case ('1') : {
                        char userSubInput;

                        if (not formAlliance) {cout << endl << "1: Form alliance " << endl;}
                        if (not ceasefire) {cout << "2: Cease of hostility" << endl;}
                        cout << "3: Send energy" << endl;
                        cout << "4: Send metal" << endl;
                        cout << "5: Sent oil" << endl;
                        cout << "6: Reset" << endl;
                        cout << "7: Back" << endl;

                        cin >> userSubInput;

                        switch (userSubInput) {
                            case ('1'): {
                                formAlliance = true;
                                continue;
                            }
                            case ('2'): {
                                ceasefire = true;
                                continue;
                            }
                            case ('3'): {
                                cin >> energy;
                                continue;
                            }
                            case ('4'): {
                                cin >> metal;
                                continue;
                            }
                            case ('5'): {
                                cin >> oil;
                                continue;
                            }
                            case ('6'): {
                                formAlliance = false;
                                ceasefire = false;
                                aPassRight = 0;

                                metal = 0;
                                oil = 0;
                                energy = 0;
                                continue;
                            }
                            case ('7'): {
                                break;
                            }


                        }
                    }
                    case ('2'): {
                        char userSubInput;

                        if (aPassRight == 0) {cout << endl << "1: Request military access" << endl;}
                        cout << "2: Demand energy" << endl;
                        cout << "3: Demand metal" << endl;
                        cout << "4: Demand oil" << endl;
                        cout << "5: Reset" << endl;
                        cout << "6: Back" << endl;

                        cin >> userSubInput;

                        switch (userSubInput) {
                            case ('1'): {
                                cout << "Amount of turns: " ;
                                cin >> aPassRight;
                                if (aPassRight < 0) {
                                    aPassRight =0;
                                }
                                continue;
                            }
                            case ('2'): {
                                cin >> energy;
                                energy = -energy;
                                continue;
                            }
                            case ('3'): {
                                cin >> metal;
                                metal = -metal;
                                continue;
                            }
                            case ('4'): {
                                cin >> oil;
                                oil = -oil;
                                continue;
                            }
                            case ('5'): {

                                aPassRight = 0;

                                metal = 0;
                                oil = 0;
                                energy = 0;
                                continue;
                            }
                            case ('6'): {
                                break;
                            }


                        }


                    }

                    case ('3'): {
                        cout << "Your message to: " << recipient->countryName << endl;
                        cin.ignore();
                        std::getline(std::cin,userMessage);
                    }

                    case ('4'): {
                        char userSubInput;
                        cout << endl << "Summary: " << endl;
                        if (formAlliance) {cout << endl << "> Form alliance " << endl;}
                        if (ceasefire) {cout << "> Cease of hostility" << endl;}

                        cout << endl << "Offer: " << endl << endl;
                        if (metal > 0) { cout << "Metal: " << metal << endl;}
                        if (energy > 0) { cout << "Energy: " << energy << endl;}
                        if (oil > 0) { cout << "Oil: " << oil << endl;}

                        cout << endl << "1: Confirm" << endl;
                        cout << endl << "2: Back" << endl;
                        cin >> userSubInput;

                        switch (userSubInput) {
                            case ('1'): {
                                cout << "Enter period of validity: ";
                                cin >> periodOfValidity;
                                if (periodOfValidity < 1) {
                                    cout << "Period of validity set to 1" << endl;
                                    periodOfValidity = 1;}

                                DiplomacyRequest * dr = new DiplomacyRequest(issuer,recipient,userMessage,formAlliance,
                                ceasefire,aPassRight, metal, oil, energy, periodOfValidity);

                                issuer -> sentDiplomacyRequests.push_back(dr);
                                recipient -> incomingDiplomacyRequests.push_back(dr);
                            }

                            case ('2'): {
                                continue; }
                        }
                    }
                    case ('5'): {
                        return;}
                }
            }

        }


    }
    void    D_ControlInterf  (Country *countryInControl) {
        /** The function will provide a country object with information on received, sent, accepted diplomacy request
         * and let compose a new request.
         */

        do {
            cout << endl << "1: Treaty Report" << endl;
            cout << "2: Sent Requests" << endl;
            cout << "3: Received Requests [" << countryInControl->incomingDiplomacyRequests.size() << "]" << endl;
            cout << "4: Compose new request" << endl;
            cout << "5: Main Menu" << endl << "->";

            char userSelection;
            cin >> userSelection;

            switch (userSelection) {
                case ('1'): {
                    // MILITARY ACCESS TREATIES
                    for (MilitaryAccess *ma : countryInControl->accessRights) {
                        ma->coutMyself();
                    }
                    cout << endl;
                    // WAR TREATIES
                    for (Country *c : countryInControl->enemies) {
                        cout << "At war with: " << c->countryName;
                    }
                    // ALLIED COUNTRIES
                    for (Country *c : countryInControl->allies) {
                        cout << "Alliance treaty with: " << c->countryName;
                    }

                    continue;

//                    char userSubSelection;
//                    cout << endl << "1: Continue" << endl;
//                    cin >> userSubSelection;
//                    if (userSubSelection == '1') {
//                        continue;
//                    }
                }

                case ('2'): {
                    for (DiplomacyRequest *dr : countryInControl->sentDiplomacyRequests) {
                        cout << endl << "Sent to: " << dr->recipientCountry->countryName;
                        dr->coutReportOfConditions();
                        if (countryInControl->sentDiplomacyRequests.size() == 0 ) {
                            cout << "Nothing to display" << endl;
                        }


                    }
                    continue;

                }

                case ('3'): {
                    for (DiplomacyRequest *dr : countryInControl->incomingDiplomacyRequests) {
                        cout << endl << "Received from " << dr->issuerCountry->countryName;
                        dr->coutReportOfConditions();
                    }
                    continue;
                }

                case ('4'): {
                    new_DRequest(countryInControl);
                    continue;
                }


                case ('5'): {
                    return;
                }


            }

        } while (true);
    }

//  ### COUNTRY CONTROL ###

    map < string, Country* >   countries_to_map(Country *inCountry) {
        /** A function to convert the "countries" array into a map structure where the string
         * key denotes its position in the array;
         *
         *  The function won't include the value in the function's argument into the output map.
         */
        map <string, Country *> countriesAsMap;
        string key;

        vector <Country*> conditionedCountries; //

        // A loop to detect if any pointer in "regions" match to the parameter "inRegion"
        // to avoid inclusion of the match.
        for (int j = 0; j < countries.size(); j++) {

            // A condition to only include the pointers which don't match the input parameter
            if (countries.at(j) != inCountry && countries[j] != NULL ) {
                conditionedCountries.push_back(countries.at(j));
            }
        };

        // Creating map structure
        for (int i = 1; i < conditionedCountries.size() + 1; i ++) {

            key = to_string(i);
            countriesAsMap[key] = conditionedCountries.at(i - 1);
        }
        return countriesAsMap;
    }
    Country*                 input_Country   (Country *inCountry) {
        /** The function which will display the content of "countries" vector, structurised as a map where the keys
         * denote the position of an object in the array.
         *
         * The objects matching the address "inCountry" won't be displayed.
         *
         * Displayable countries are obtained by calling the function "structuriseCountriesAsMap";
         * The returned values are displayed.
         * An user inputs a digit which represents his choice of the country.
         * Input digit is validated.
         * If is valid the corresponding country will be returned.
         */
        map <string, Country *> countriesAsMap = countries_to_map(inCountry); // Calling function to obtain displayable regions
        string userInput;
        bool isInputValid = false;

        cout << "Select a country" << endl;



        for (auto& kv : countriesAsMap) { // DISPLAYING THE CONTENT OF THE STD::MAP
            cout << kv.first << ": " << kv.second->countryName << endl;
        }
        cout << countriesAsMap.size() + 1 << ": " << "< Back <" << endl; // DISPLAYING THE OPTION TO RETURN TO THE PREVIOUS MENU.

        while (isInputValid == false) {  // INPUT VALIDATION

            cout << "-> ";
            cin >> userInput;
            isInputValid = countriesAsMap.find(userInput) != countriesAsMap.end(); // Whether or not the input is in the map

            if (stoi(userInput) == countriesAsMap.size() + 1 ) { return NULL;} // The user pressed "back" option

            else if (isInputValid == false) {cout << "Invalid input, try again" << endl; }

            else { return countriesAsMap[userInput];} // The pointer is found
        }



    }

    void    C_ControlInterf  (Country *countryInControl) {
        /** A function to provide player with a control interface of his country.
         * The mainLoop() passes a Country object into argument of the function
         * where the user gets to enter commands to invoke functions which alter the
         * state of the program.
         *
         * Loop operates in the function which lets the user enter commands until
         * the procedure to switch the turn is called.
         *
         */

        countryInControl->runResourceCollection();

        cout << "[ " << Manager::turn << " ] >>> " << countryInControl->countryName << " <<<" << endl << endl;

        cout << "0: Diplomacy [" << countryInControl->incomingDiplomacyRequests.size() << "]" << endl;
        cout << "1: Make a diplomacy request" << endl;
        cout << "2: Display pending diplomacy requests [" << countryInControl->incomingDiplomacyRequests.size() << "]" << endl;
        cout << "3: Display regions" << endl;
        cout << "4: End turn" << endl;

        char command;

        while (true == true) {  // MAINLOOP
            cout << endl << "Your command: ";
            cin >> command;
            cout << endl;

            switch (command) {

                case ('0'):
                    D_ControlInterf(countryInControl);

                case ('1'): {
                    new_DRequest(countryInControl);
                    break;
                }
                case ('2'): {
                    // to-do implement as a function;
                    for (int i = 0; i < countryInControl->incomingDiplomacyRequests.size(); ++i) {
                        cout << endl;
                        cout << "From: " << countryInControl->incomingDiplomacyRequests.at(i)->issuerCountry->countryName
                             << endl;
                        cout << "Message: " << endl << countryInControl->incomingDiplomacyRequests.at(i)->getMessage() << endl;
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
    };

//  #############################
    void saveGame();
    void loadGame();


    Manager()
    {
        initRegions();
        init_Countries();
        fill_Neutral(); // Procedure to set all the initialised countries neutral to each other.
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