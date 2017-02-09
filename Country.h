//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_FRACTION_H
#define EUROPE_AT_WAR_FRACTION_H

#include <map>
#include <vector>

using namespace std;

#include "Region.h"

class Country;

class DiplomacyRequest {
    /** Class to enable a player to form alliances, declare war or exchange with resources.
     *
     * An object of this class will be inserted into the receiving country class object's vector, pendingDiplomacy, to get presented.
     * */




public:
    DiplomacyRequest * myPointer;

    Country *issuerCountry;
    Country *recipientCountry;

    string message;
    bool formAlliance = false;
    bool breakAlliance = false;
    bool declareWar = false;
    bool ceasfire = false;
    int aPassRight = 0;
    int money = 0;
    int metal = 0;
    int oil = 0;
    int energy = 0;
    int manpower = 0;

    int periodOfValidity;

    const string &getMessage() const {
        return message;
    }

    void acceptRequest();
    void declainRequest();

    void sendRequest(Country * recipientCountry, DiplomacyRequest * myPointer);

public:

    DiplomacyRequest(Country *issuerCountry, Country *recipientCountry,
                     const string &message, bool formAlliance, bool breakAlliance, bool declareWar, bool ceasfire,
                     int aPassRight, int money, int metal, int oil, int energy, int manpower, int periodOfValidity)
            : issuerCountry(issuerCountry), recipientCountry(recipientCountry), message(message),
              formAlliance(formAlliance), breakAlliance(breakAlliance), declareWar(declareWar), ceasfire(ceasfire),
              aPassRight(aPassRight), money(money), metal(metal), oil(oil), energy(energy), manpower(manpower),
              periodOfValidity(periodOfValidity) {

        DiplomacyRequest::myPointer = this;
    }

    virtual ~DiplomacyRequest() {
        std::cout << " I got into destructor! "<< myPointer;
    }
};

class Country {

    /** Class that encapsulates data about the state of player's country and provides member functions for minor control */

public:

    string countryName; // User defined name for his country


    vector <Country*> allies ; // Vector to comprise allies of the country
    vector <Country*> enemies; // Enemies of the country
    vector <Country*> neutral; // Permission to cross other country's border
    vector <DiplomacyRequest*> pendingDiplomacy; // List of pending notifications by diplomacyRequest()

    vector <Region*> regions; // Vector to comprise regions under the country's control

    char color_on_map; // Colour by which the country is represented on the map

    void diplomacyRequest (Country *issuerCountry, Country *recipientCountry,  string message, bool formAlliance,
                           bool breakAlliance, bool declareWar, bool ceasfire, int aPassRight, int money, int metal, int oil,
                           int energy, int manpower) {
    }

    void transferResources(Region * recipientRegion) {


    };

    map <string, Region*> structuriseRegionsAsMap () {
        /** A function to convert a country's "regions" array, which contains "Region" objects,
         *  into a map structure where the string key denotes its position in the array;
         */
        map <string, Region *> regionsAsMap;
        string key;

        for (int i = 1; i < regions.size() + 1; i ++) {
            key = to_string(i);
            regionsAsMap[key] = regions.at(i - 1);
            }
        return regionsAsMap;
        }
    Region* inputRegion() {
        /** A function which will display the content of "regions" vactor structurised as a map where the keys
         * denote position of an object in the array.
         *
         * Validate the input, with an option to terminate the process entering the key of "back" option;
         *
         * It will return the value that corresponds to the element whose key was entered by a user.
         */
        map <string, Region *> regionsAsMap = structuriseRegionsAsMap ();
        string userInput;
        bool isInputValid = false;

        for (auto& kv : regionsAsMap) { // DISPLAYING THE CONTENT OF THE STD::MAP
            cout << kv.first << ": " << kv.second->name << endl;
        }

        cout << regionsAsMap.size() + 1 << ": " << "Back" << endl; // DISPLAYING THE OPTION TO RETURN TO THE PREVIOUS MENU.

        while (isInputValid == false) {  // INPUT VALIDATION

            cout << "Your choice: ";
            cin >> userInput;
            isInputValid = regionsAsMap.find(userInput) != regionsAsMap.end();

            if (stoi(userInput) == regionsAsMap.size() + 1 ) { return NULL;}
            else if (isInputValid == false) {cout << "Invalid input, try again" << endl; }
            else { return regionsAsMap[userInput];}
        }



    }
    void resourceTransfer (Region * fromRegion, Region * toRegion) {
        /** A function that asks to input amount of resources and deducts it from "fromRegion" and adds to "toRegion".
         *    I.e. resource transfer between a country's regions.
         *    The function will ask for confirmation at the end.
         */
        // to-do implement exception management and input validation

        string userInputEnergy, userInputMetal, userInputOil;
        char userConfirmation; // to-do why error appears when userConfirmation[2];


        // #### INPUT #####
        cout << "Enter amount of energy you want to transfer: " << endl;
        cin >> userInputEnergy;
        cout << "Enter amount of metal you want to transfer: " << endl;
        cin >> userInputMetal;
        cout << "Enter amount of oil you want to transfer: "<< endl;
        cin >> userInputOil;

        // #### AVAILABILITY CHECK ####
        bool areResourcesSufficient;
        areResourcesSufficient = fromRegion->checkResourceAvailability(stoi(userInputMetal),stoi(userInputOil), stoi(userInputMetal));

        // #### CONFIRMATION ####
        if (areResourcesSufficient) {

            cout << "Confirm (Y/N): ";
            cin >> userConfirmation;

            if ( (userConfirmation == 'Y') || (userConfirmation == 'y') ) {
                fromRegion -> deductResources(stoi(userInputMetal),stoi(userInputOil), stoi(userInputMetal));
                toRegion -> addResources(stoi(userInputMetal),stoi(userInputOil), stoi(userInputMetal));
            } else {
                cout << "The process shut down" << endl;
                return;
            }
        } else {
            cout << "Insufficient resources" << endl;
        }
    }




    struct resources { // Country's wealth
        int money;
        int metal;
        int oil;
        int energy;
        int manpower;
    } resources;

    // METHODS

    void askResourcesFromRegions() {   };

    void addNewRegion(Region region) {};
    void loseRegion (Region region) {};

    Country(Region *region1, Region *region2, string name) : countryName(name) {
        regions.push_back(region1);
        regions.push_back(region2);
    }

    Country() {}
} ;

#endif //EUROPE_AT_WAR_FRACTION_H