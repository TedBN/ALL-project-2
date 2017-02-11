//
// Created by Oskars Pozdnakovs on 24/01/2017.
//

#ifndef EUROPE_AT_WAR_FRACTION_H
#define EUROPE_AT_WAR_FRACTION_H

#include "Region.h"

// PRE - DECLARATION
class Country;
class MilitaryAccess;


// ### COUNTRY - DIPLOMACY ###

class DiplomacyRequest {
    /** Class to enable a player to form alliances, declare war or exchange with resources.
     *
     * An object of this class will be inserted into the recipient's vector of "incomoingDiplomacyRequests";
     *  and
     * An object of this class will be inserted into the issuer's vector of "sentDiplomacyRequests";
     * */

public:

//  ### ATTRIBUTES ###
    bool        formAlliance = false;
    bool        ceasefire = false;
    int         aPassRight = 0;
    int         metal = 0;
    int         oil = 0;
    int         energy = 0;
    int         periodOfValidity;

    Country*    issuerCountry;
    Country*    recipientCountry;
    string      message;

// ### METHODS
    void        acceptRequest();

public:
    DiplomacyRequest*        runMaintenance() {
        /** This function processes validity period of a request and if
         * the it has expired will return the objetc's address for further processing
         * (i.e. erasure and removal from the list of all the ongoing requests)
         */
        periodOfValidity--;
        if (periodOfValidity <= 0) {
            return this;
        } else {
            return NULL;
        }
    }
    void        coutReportOfConditions() {
        /** Function to output the summary of the request on the screen. */

        cout<< endl << "> Offered " <<endl;

        if (formAlliance)     {cout << "  Form alliance" << endl;}
        if (ceasefire)        {cout << "  Cease of hostility" << endl; }
        if (metal > 0)        {cout << "  " << metal << " Metal"<< endl;;}
        if (oil > 0)          {cout << "  " << oil << " Oil"<< endl;;}
        if (energy > 0)       {cout << "  " << energy << " Energy"<< endl;;}

        cout <<endl<< ">Demanded: " <<endl;

        if (aPassRight > 0 ) {cout << "  Military access for " << aPassRight << " turns" <<  endl; }
        if (metal < 0)       {cout << "  " << -metal << " Units of metal offered"<< endl;;}
        if (oil < 0)         {cout << "  " << -oil << " Units of oil offered"<< endl;;}
        if (energy < 0)      {cout << "  " << -energy << " Units of energy offered"<< endl;;}

        cout <<endl<< " Message" <<endl;
        cout << "  " << message <<endl;

        if (periodOfValidity - 1 == 0 ) {
            cout <<endl<< "The request remains valid for: this turn only" <<endl;
        } else {
            cout <<endl<< "The request remains valid for: " << periodOfValidity - 1 << " turns" <<endl;
        }

        cout << "----------------" <<endl;
    }


//  ### CONSTRUCTOR ###

    DiplomacyRequest(Country *issuerCountry, Country *recipientCountry,
                     const string &message, bool formAlliance,  bool ceasfire,
                     int aPassRight, int metal, int oil, int energy,  int periodOfValidity) :
              issuerCountry(issuerCountry), recipientCountry(recipientCountry), message(message),
              formAlliance(formAlliance),  ceasefire(ceasfire),
              aPassRight(aPassRight),  metal(metal), oil(oil), energy(energy),
              periodOfValidity(periodOfValidity + 1) {
    }

    virtual ~DiplomacyRequest() {}
};
//  #####################

class Country {

    /** Class that encapsulates data about the state of a player controllable country*/

public:

//  ### ATTRIBUTES ###

    string                      countryName;
    vector <Army *>             armiesAbroad;
    vector <Country*>           allies ;                 // Vector to comprise allies of the country
    vector <Country*>           enemies;                // Enemies of the country
    vector <Country*>           neutral;               // Permission to cross other country's border
    vector <DiplomacyRequest*>  receivedDiplomacyRequests;
    vector <DiplomacyRequest*>  sentDiplomacyRequests;
    vector <Region*>            regions;            // Vector to comprise regions under the country's control
    vector <MilitaryAccess*>    accessRights;      // Rights to access the territory of a country in the vector

//  ### METHODS ###

    vector<Army *>              getAllArmies ();
    map< string, Region* >      structuriseRegionsAsMap (Region * inRegion) {
        /** A function to convert a country's "regions" array, which contains "Region" objects,
         *  into a map structure where the string key denotes its position in the array;
         *
         *  The function won't include the value in the argument into the output map.
         */
        map <string, Region *> regionsAsMap;
        string key;

        vector <Region*> ConditionedRegions; //

        // A loop to detect if any pointer in "regions" match to the parameter "inRegion"
        // to avoid inclusion of the match.
        for (int j = 0; j < regions.size(); j++) {

            // A condition to only include the pointers which don't match the input parameter
            if (regions.at(j) != inRegion ) {
                ConditionedRegions.push_back(regions.at(j));
            }
        };

        // Creating map structure
        for (int i = 1; i < ConditionedRegions.size() + 1; i ++) {

            key = to_string(i);
            regionsAsMap[key] = ConditionedRegions.at(i - 1);
        }
        return regionsAsMap;
        }
    Region*                     inputRegion(Region * inRegion) {
        /** The function which will display the content of "regions" vector, structurised as a map where the keys
         * denote the position of an object in the array.
         *
         * The objects matching the address "inRegion" won't be displayed.
         *
         * Displayable regions are obtained by calling the function "structuriseRegionsAsMap";
         * The returned values are displayed.
         * An user inputs a digit which represents his choice of the region.
         * Input digit is validated.
         * If is valid the corresponding region will be returned.
         */
        map <string, Region *> regionsAsMap = structuriseRegionsAsMap (inRegion); // Calling function to obtain displayable regions
        string userInput;
        bool isInputValid = false;

        cout << "Select a region" << endl;

        for (auto& kv : regionsAsMap) { // DISPLAYING THE CONTENT OF THE STD::MAP
            cout << kv.first << ": " << kv.second->name << endl;
        }

        cout << regionsAsMap.size() + 1 << ": " << "< Back <" << endl; // DISPLAYING THE OPTION TO RETURN TO THE PREVIOUS MENU.

        while (isInputValid == false) {  // INPUT VALIDATION

            cout << "-> ";
            cin >> userInput;

            isInputValid = regionsAsMap.find(userInput) != regionsAsMap.end(); // Whether or not the input is in the map

            if (stoi(userInput) == regionsAsMap.size() + 1 ) { return NULL;} // The user pressed "back" option

            else if (isInputValid == false) {cout << "Invalid input, try again" << endl; }

            else { return regionsAsMap[userInput];} // The pointer is found
        }



    }
    string                      regionControlInterface(Region * selectedRegion) {
        /** Calling this function the selected region's stats and a selection of control commands related to the regions
         * are displayed. A user gets to enter a digit that will represents his choice.
         *
         * Then the command is processed.
         */

        selectedRegion->displayStats();

        cout << endl << "| Region control options |" << endl;

        cout << endl << " 1: Transfer resources to another region" << endl;
        cout << " 2: Defence army overview" << endl;
        cout << " 3: Infrastructure upgrade" << endl;

        cout << " 4: Back" << endl;
        cout << " 5: Back to main menu" << endl << "-> ";

        char userCommand;

        cin >> userCommand;

        switch (userCommand) {
            case ('1'): {
                Region * destinationRegion;

                cout << endl << "Destination" << endl;
                destinationRegion = inputRegion(selectedRegion); //to-do implement a function not to output a particular element;
                resourceTransfer(selectedRegion,destinationRegion);
                return "back to region selection";  }

            case ('2'): {
                cout << "Not implemented yet" << endl;
                break;
                }

            case ('3'): {
                cout << "Not implemented yet" << endl;
                break;
            }

            case ('4'): {
                return "back to region selection";

            }

            case ('5'): {
                return "back to main menu";
            }

            default: {
                cout << endl << "Wrong Input" << endl;
            }



        }




    }
    vector<Army *>              getArmiesOnTerritoryOf( Country * countrySelected ) {
        /** A function to iterate through the list of "armiesAbroad" of an object and determines if the "Army" object's pointer
         * to current location matches any region of the country in the function's argument.
         *
         * The output will be the vector of "Army" pointers whose current location matched the regions.
         */


        vector <Army *> outputArmies;
        const vector <Region *> countrysRegions = countrySelected->regions;

        for (Army * army : armiesAbroad) {
            if ( std::find(countrysRegions.begin(), countrysRegions.end(), army->currentLocation) != countrysRegions.end() )
                outputArmies.push_back(army);
            else
                continue;
            }

        return outputArmies;
        }
    void                        sendArmiesHomeFrom ( Country * countrySelected ) {
        // to-do add docstrings
        vector <Army *> armiesAbroad;
        armiesAbroad = getArmiesOnTerritoryOf(countrySelected );

        for (Army * army : armiesAbroad) {
            army -> currentLocation = regions[0]; // Region at pos 0 in regions is the capital city
            regions[0]->defenceArmies.push_back(army);

        }


    }
    void                        runResourceCollection () {
        /** Function to run the method regionalResourceCollection() for each "Region" object in the
         *  "regions" vector to update the stock based on produced resources.
         */
        for (Region * region: regions) {
            region->regionalResourceCollection();
        }

    }
    void                        resourceTransfer (Region * fromRegion, Region * toRegion) {
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
        areResourcesSufficient = fromRegion->checkResourceAvailability(stoi(userInputMetal),stoi(userInputOil), stoi(userInputEnergy));

        // #### CONFIRMATION ####
        if (areResourcesSufficient) {

            cout << "Confirm (Y/N): ";
            cin >> userConfirmation;

            if ( (userConfirmation == 'Y') || (userConfirmation == 'y') ) {
                fromRegion -> deductResources(stoi(userInputMetal),stoi(userInputOil), stoi(userInputEnergy));
                toRegion -> addResources(stoi(userInputMetal),stoi(userInputOil), stoi(userInputEnergy));
            } else {
                cout << "The process shut down" << endl;
                return;
            }
        } else {
            cout << "Insufficient resources" << endl;
        }
    }
    void                        removeSentRequest(DiplomacyRequest * expiredRequest) {
        sentDiplomacyRequests.erase(remove(sentDiplomacyRequests.begin(), sentDiplomacyRequests.end(), expiredRequest ), sentDiplomacyRequests.end());
    }
    void                        removeReceivedRequest(DiplomacyRequest * expiredRequest) {
        receivedDiplomacyRequests.erase(remove(receivedDiplomacyRequests.begin(), receivedDiplomacyRequests.end(), expiredRequest ), receivedDiplomacyRequests.end());
    }

// ### CONSTRUCTORS ###
    Country (Region *region1, Region *region2, string name) : countryName(name) {
        regions.push_back(region1);
        regions.push_back(region2);
    }
    Country() {}
} ;
// #####################

class MilitaryAccess {

//  ### ATTRIBUTES ###

    int periodOfValidity;
    Country*    receiver;
    Country*    provider;

public:
//  ### METHODS ###
    void        coutMyself(){
        cout << endl << "A military access right to " << provider -> countryName << " for: " << periodOfValidity << " turns" << endl;
    }
    void        runMaintenance() {
        periodOfValidity--;
        if (periodOfValidity == 0) {
            receiver -> sendArmiesHomeFrom(provider);
        }
    }

// ### CONSTRUCTORS ###
    MilitaryAccess(Country *receiver, Country *provider, int periodOfValidity) : receiver(receiver), provider(provider),
                                                                                 periodOfValidity(periodOfValidity) {}
    virtual ~MilitaryAccess() {
    }
};
// #####################

#endif //EUROPE_AT_WAR_FRACTION_H