//
// Created by Oskars Pozdnakovs on 30/01/2017.
//

#ifndef ALL_PROJECT_2_MANAGER_H
#define ALL_PROJECT_2_MANAGER_H


#include "Country.h"

class Manager {

public:

//  ##################
//  ### ATTRIBUTES ###

    vector <DiplomacyRequest*> allDiplomacyRequests;
    vector <MilitaryAccess*>   all_MAccess_Treaties;
    int                     turn = 1;               // Keeps track of the current turn;
    int                     countriesInGame =0;        // Quantity of currently active countries
    array   <Region, 8>     all_Regions; // to-do store on the heap
    array   <Country *, 4>  countries = {NULL, NULL, NULL, NULL};

//  ### INITIALISATION ###

    void                    initRegions() {
        /** Initialisation of class Region objects which have pre-determined member values.
         */

        for (int i = 0; i < all_Regions.size(); i++) {

            // to-do would there be a benefit from dynamic initialisation?

            switch (i) {
                case 0: {
                    Army *army = new Army;
                    Region region0("Western Germany", army);
                    all_Regions[i] = region0;
                    break;}
                case 1: {
                    Army *army = new Army;
                    Region region1("Eastern Germany", army);
                    all_Regions[i] = region1;
                    break;}
                case 2: {
                    Army *army = new Army;
                    Region region2("Western Spain", army);
                    all_Regions[i] = region2;
                    break;}
                case 3: {
                    Army *army = new Army;
                    Region region3("Eastern Spain", army);
                    all_Regions[i] = region3;
                    break;}
                case 4: {
                    Army *army = new Army;
                    Region region4("Western France", army);
                    all_Regions[i] = region4;
                    break;}
                case 5: {
                    Army *army = new Army;
                    Region region5("Eastern France", army);
                    all_Regions[i] = region5;
                    break;}
                case 6: {
                    Army *army = new Army;
                    Region region6("Western Poland", army);
                    all_Regions[i] = region6;
                    break;}
                case 7: {
                    Army *army = new Army;
                    Region region7("Eastern Poland", army);
                    all_Regions[i] = region7;
                    break;}
            }
        }
    }      //   init_Regions()
    void                    init_Countries() {
        /** A method to initialise a country after a user has chosen a country by the name.
         * Input is the string that is passed to the function after the user selected his country.
         * The country is initialised with pre-determined regions based on the user's choice of the country.
         * Once the Country object has been initialised, it is appended to the vector activeCountries;
         */

        string userInput;
        int userInputCounter = 0; // Counts how many times a user has entered valid value
        bool isInputValid;
        array <string, 5> validInputs = {"Spain", "France", "Germany", "Poland", "Continue"};

        cout << "Select a country: " ;

        do { // USER INPUT LOOP

            // Max 4 iterations of a valid input, userInputCounter keeps track of that

            for (int i = 0; i < validInputs.size(); i++) {
                if (validInputs[i] != "") {
                    // Condition to check which countries haven't been selected yet
                    // and output them.
                    if (validInputs[i] == "Continue") {
                        cout << endl << "   " << validInputs[i];
                    } else {
                        cout << endl << " > " << validInputs[i];
                    }
                }
            }

            cout << " >" << endl;
            cout << "-> ";
            cin >> userInput;

            // Checking weather or not the user input is in the list of valid input
            isInputValid = find(begin(validInputs), end(validInputs), userInput) != end(validInputs);

            if (!isInputValid) {
                cout << "Invalid input, try again"<< endl << endl;
                continue;}

            //  REMOVING THE VALIDATED NAME FROM THE VALID INPUT LIST
            for (int i = 0; i < validInputs.size() - 1; i++) {
                // Replacing the matching value in the input list with ""
                if (validInputs[i] == userInput) {validInputs[i] = "";}
            }

            if(userInput == "Germany" ) {
                init_Germany();

            } else if( userInput == "Poland") {
                init_Poland();

            } else if( userInput == "France") {
                init_France();

            } else  if (userInput == "South"){
                init_Spain();

            } else if (userInput == "Continue") {
                if (userInputCounter < 2) {
                    cout << "At least 2 countries required. You have: " << userInputCounter << endl << endl;
                    continue;}
                else { break;}
            }

            ++userInputCounter;

        } while (userInputCounter < 4) ;

    }   //   init_Countries()
    void                    init_Germany()  {
        /** This function dynamically initialises a new object of the "Country" class and the pointer to it
         * is stored in the array "countries". The counter of active "Country" objects is also incremented.
         *
         * The initialised object has unique properties of associated "regions" and name.
         * Name: Germany
         * Regions: Western Germany
         * Regions: Eastern Germany
         *
         */
        countries[2] = new Country(&all_Regions[0], &all_Regions[1], "Germany");
        countriesInGame ++;
    }
    void                    init_Spain()  {
        /** This function dynamically initialises a new object of the "Country" class and the pointer to it
         * is stored in the array "countries". The counter of active "Country" objects is also incremented.
         *
         * The initialised object has unique properties of associated "regions" and name.
         * Name: Spain
         * Regions: Western Spain
         * Regions: Eastern Spain
         *
         */
        countries[0] = new Country(&all_Regions[2], &all_Regions[3], "Spain");
        countriesInGame++;
        //cout<<"test:"<<countriesInGame;
    }
    void                    init_France()  {
        /** This function dynamically initialises a new object of the "Country" class and the pointer to it
         * is stored in the array "countries". The counter of active "Country" objects is also incremented.
         *
         * The initialised object has unique properties of associated "regions" and name.
         * Name: France
         * Regions: Western France
         * Regions: Eastern France
         *
         */
        countries[1] = new Country(&all_Regions[4], &all_Regions[5], "France");
        countriesInGame ++;
    }
    void                    init_Poland()  {
        /** This function dynamically initialises a new object of the "Country" class and the pointer to it
         * is stored in the array "countries". The counter of active "Country" objects is also incremented.
         *
         * The initialised object has unique properties of associated "regions" and name.
         * Name: Poland
         * Regions: Western Poland
         * Regions: Eastern Poland
         *
         */
        countries[3] = new Country(&all_Regions[6], &all_Regions[7], "Poland");
        countriesInGame ++;
    }

    void                    makeCountriesNeutral() {
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
    }     //   makeCountriesNeutral()
    void                    mainLoop() {
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

            if (i == countries.size()) {

                i = 0;
                Manager::turn++;
                run_Diplomacy_Maintenance();
                run_MAccess_Maintenance();
                continue;
            } else if (countries[i] == NULL) {
                i++;
                continue;
            }

            cout << "i is " << i << endl;
            C_ControlInterf(countries.at(i));

            i++;

        }
    };        //   MAINLOOP

//  ###    DIPLOMACY   ###

    void                    run_Diplomacy_Maintenance () {
        /** This function runs DiplomacyRequest::runMaintenance() which will return the address
         *  of an object if its period of validity expired at call time
         *  , else it will return NULL;
         *
         *  If the result isn't NULL it will be erased from the heap and the pointer removed from the
         *  vector of all the ongoing diplomacy requests "allDiplomacyRequests"
         *
         */
        DiplomacyRequest* expiredRequest;

        for (DiplomacyRequest * dr : allDiplomacyRequests ) {

            if (dr->runMaintenance() != NULL) {
                // OBJECT EXPIRED
                expiredRequest = dr->runMaintenance();
                // OBJECT REMOVED FROM THE VECTOR OF ONGOING REQUESTS and sent/received vecotrs of bouth countries
                allDiplomacyRequests.erase(remove(allDiplomacyRequests.begin(), allDiplomacyRequests.end(),expiredRequest ), allDiplomacyRequests.end());
                expiredRequest->issuerCountry->removeSentRequest(expiredRequest);
                expiredRequest->recipientCountry->removeReceivedRequest(expiredRequest);
                // OBJECT DELETED
                delete expiredRequest;
                expiredRequest = NULL;
            }
        }
    }
    void                    run_MAccess_Maintenance () {
        /** This function runs MilitaryAccess::runMaintenance() which will return the address
         *  of an object if its period of validity expired at call time
         *  , else it will return NULL;
         *
         *  If the result isn't NULL it will be erased from the heap and the pointer removed from the
         *  vector of all the ongoing military access treaties in "all_MAccess_Treaties" vector
         *
         */
        MilitaryAccess * expiredRequest;

        for (MilitaryAccess * ma : all_MAccess_Treaties ) {

            if (ma->runMaintenance() != NULL) {
                // OBJECT EXPIRED
                expiredRequest = ma->runMaintenance();
                // OBJECT REMOVED FROM THE VECTOR OF ONGOING REQUESTS and sent/received vecotrs of bouth countries
                all_MAccess_Treaties.erase(remove(all_MAccess_Treaties.begin(), all_MAccess_Treaties.end(),expiredRequest ), all_MAccess_Treaties.end());
                expiredRequest->getProvider()->remove_MAccessTreaty(expiredRequest);
                expiredRequest->getReceiver()->remove_MAccessTreaty(expiredRequest);
                // OBJECT DELETED
                delete expiredRequest;
                expiredRequest = NULL;
            }
        }
    }

    void                    newMAccessTreaty (Country * provider, Country * receiver, int periodOfValidity){

                            MilitaryAccess * ma = new MilitaryAccess(receiver, provider, periodOfValidity);
                            all_MAccess_Treaties.push_back(ma);
                            ma->getReceiver()->territoryAccessRights.push_back(ma);
                            ma->getProvider()->territoryAccessRights.push_back(ma);

    }
    void                    newAlliance (Country * c1, Country * c2) {
        c1->allies.push_back(c2);
        c2->allies.push_back(c1);
        c1->neutral.erase(remove(c1->neutral.begin(), c1->neutral.end(), c2 ), c1->neutral.end());
        c2->neutral.erase(remove(c2->neutral.begin(), c2->neutral.end(), c1 ), c2->neutral.end());



        // to-do remove from mil acc if true

    }
    void                    breakAlliance (Country * country1, Country * country2) {
        country1->allies.erase(remove(country1->allies.begin(), country1->allies.end(),country2 ), country1->allies.end());
        country2->allies.erase(remove(country2->allies.begin(), country2->allies.end(),country1 ), country2->allies.end());
    }
    void                    warDeclaration (Country * c1, Country * c2) {
        c1->enemies.push_back(c2);
        c2->enemies.push_back(c1);
        c1->neutral.erase(remove(c1->neutral.begin(), c1->neutral.end(), c2 ), c1->neutral.end());
        c2->neutral.erase(remove(c2->neutral.begin(), c2->neutral.end(), c1 ), c2->neutral.end());
    }
    void                    ceasefire (Country * country1, Country * country2) {
        country1->enemies.erase(remove(country1->enemies.begin(), country1->enemies.end(),country2 ), country1->enemies.end());
        country2->enemies.erase(remove(country2->enemies.begin(), country2->enemies.end(),country1 ), country2->enemies.end());
        country1->neutral.push_back(country2);
        country2->neutral.push_back(country1);
    }

    bool                    confirm_D_Request ( DiplomacyRequest * dr) {
        /** The function to process confirmation of a diplomacy request.
         * It returns true if the country accepting the offer is capable of satisfying the resources demanded,
         * false if the navigation back is selected.
         *
         */

        // to-do if request is turned down, restore sender's resources
        int energyD = 0, metalD = 0, oilD = 0; // variables for demanded resources
        int energyO = 0, metalO = 0, oilO = 0; // variables for offered resources
        Region * donorRegion = NULL;
        Region * recipientRegion = NULL;


        if (dr->oil != 0 || dr->energy != 0 || dr->metal != 0) {

            if (dr->oil < 0) {
                oilD = -dr->oil; // converting the value to positive
            } else {
                oilO = dr->oil;
            }

            if (dr->metal < 0) {
                metalD = -dr->metal;// converting the value to positive
            } else {
                metalO = dr->metal;
            }

            if (dr->energy < 0) {
                energyD = -dr->energy;// converting the value to positive
            } else {
                energyO = dr->energy;
            }
        }


        if (energyD > 0 || metalD > 0 || oilD > 0) {

            do {
                cout << "Send demanded resources from:" << endl;
                donorRegion = Country::inputRegion(dr->recipientCountry, NULL);

                if (donorRegion != NULL) {
                    if (!donorRegion->checkResourceAvailability(metalD, oilD, energyD)) {
                        cout << "Insufficient resources in stock" << endl << endl;
                    } else if (dr->recipientCountry == NULL) { // Checking whether or not player selected a region
                        return false;
                    }

                } else {
                    return false;
                }

            } while (!donorRegion->checkResourceAvailability(metalD, oilD, energyD));


        }

        if (energyO > 0 || metalO > 0 || oilO > 0) {

            cout << "Send offered resources to:" << endl;
            recipientRegion = Country::inputRegion(dr->recipientCountry, NULL);
            if (recipientRegion == NULL) { // Checking whether or not player selected a region
                return false;
            }

            if (dr->recipientCountry == NULL) {
                return false;
            }
        }


        // Processing resources addition to recipient "country"
        if (recipientRegion != NULL) {
            recipientRegion->addResources(metalO, oilO, energyO);
        }
        // Processing resources deduction from recipient "country" and addition to issuer's country
        if (donorRegion != NULL) {
            donorRegion->deductResources(metalD, oilD, energyD);
            cout << dr->resourceRecipientRegion->name << endl;
            dr->resourceRecipientRegion->addToMetalStock(metalD);
            dr->resourceRecipientRegion->addToOilStock(oilD);
            dr->resourceRecipientRegion->addToEnergyStock(energyD);
        }

        if ( dr->aPassRight > 0) {
            newMAccessTreaty(dr->issuerCountry, dr->recipientCountry, dr->aPassRight);
        }
        if (dr->formAlliance) {
            newAlliance(dr->issuerCountry, dr->recipientCountry);
        }
        if (dr->ceasefire) {
            ceasefire(dr->issuerCountry, dr->recipientCountry);
        }



        // OBJECT REMOVED FROM THE VECTOR OF ONGOING REQUESTS and sent/received vectors of both countries
        allDiplomacyRequests.erase(remove(allDiplomacyRequests.begin(), allDiplomacyRequests.end(),dr ), allDiplomacyRequests.end());
        dr->issuerCountry->removeSentRequest(dr);
        dr->recipientCountry->removeReceivedRequest(dr);



        delete dr;
        return true;

    }

    void                    new_DRequest     (Country *issuer) {
// to-do exceptions management for input validation cin >> energy
        Region * resourceDonorRegion = NULL;
        Region * resourceRecipientRegion = NULL;
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

            diplomacy_main_menu: ; // how else to break out of nested switch

            cout << endl << "| New Diplomacy Request|" << endl;
            cout << " 1: Offer to " << recipient->countryName << endl;
            cout << " 2: Demand from " << recipient->countryName << endl;
            cout << " 3: Add message" << endl;
            cout << " 4: Summary" << endl;
            cout << " 5: Confirm and send" << endl;
            cout << " 6: < Back <" << endl;
            if (!areAtWar(issuer,recipient)) {
                cout << " 7: Declare war to " << recipient->countryName << endl;
            }
            cout << "-> ";

            cin >> userInput;

                switch (userInput) {
                    case ('1') : {                                                                              // OFFER
                        int userSubInput;
                        string userOption = "";
                        map <int, string> offerOptions;
                        bool resourceOption; // whether or not the player's command was resource related

                        while (true) {
                            offerOptions = getOfferOptions(issuer, recipient, userOption);
                            outputOfferOptions(offerOptions);

                            cin >> userSubInput;
                            resourceOption = offerOptions[userSubInput] == "energyO" || offerOptions[userSubInput] == "metalO" || offerOptions[userSubInput] == "oilO";

                            // Condition to require user input of a "region" where to take the resources from
                            if (resourceOption && resourceDonorRegion == NULL) {
                                cout << "Send from:" << endl;
                                resourceDonorRegion = Country::inputRegion(issuer, NULL);
                                if (resourceDonorRegion == NULL) {
                                    continue;
                                }
                            };

                            // Processing the player's command

                            if (offerOptions[userSubInput] == "alliance") {                 // ALLIANCE
                                formAlliance = true;
                                cout << "Alliance added to the request" << endl;
                                userOption = "alliance";
                                continue;
                            } else if (offerOptions[userSubInput] == "ceasefire") {         // CEASEFIRE
                                ceasefire = true;
                                cout << "Ceasefire added to the request" << endl;
                                userOption = "ceasefire";
                                continue;
                            } else if (offerOptions[userSubInput] == "energyO") {           // ENERGY
                                cout << "Amount of energy: ";
                                cin >> energy;
                                if ( !resourceDonorRegion->checkResourceAvailability(0,0, energy) ) {
                                    cout << "Insufficient energy stock in " << resourceDonorRegion->name << endl;
                                    energy = 0;
                                }
                                continue;
                            } else if (offerOptions[userSubInput] == "metalO") {            // METAL
                                cout << "Amount of metal: ";
                                cin >> metal;
                                if ( !resourceDonorRegion->checkResourceAvailability(metal, 0, 0) ) {
                                    cout << "Insufficient metal stock in " << resourceDonorRegion->name << endl;
                                    metal = 0;
                                }
                                continue;
                            } else if (offerOptions[userSubInput] == "oilO") {              // OIL
                                cout << "Amount of oil: ";
                                cin >> oil;
                                if ( !resourceDonorRegion->checkResourceAvailability(0,oil, 0) ) {
                                    cout << "Insufficient oil stock in " << resourceDonorRegion->name << endl;
                                    oil = 0;
                                }
                                continue;
                            } else if (offerOptions[userSubInput] == "reset") {             // RESET
                                formAlliance = false;
                                ceasefire = false;
                                aPassRight = 0;
                                resourceDonorRegion = NULL;

                                if (metal > 0) {
                                    metal = 0;
                                }
                                if (oil > 0) {
                                    oil = 0;
                                }
                                if (energy > 0) {
                                    energy = 0;
                                }
                                continue;
                            } else if (offerOptions[userSubInput] == "back") {              // BACK
                                break;
                            } else {                                                        // ILLEGAL INPUT
                                cout << endl << "Wrong Input" << endl;
                                continue;
                            }
                        }
                        break;
                    }

                    case ('2'): {                                                                            // DEMANDED

                        int userSubInput;
                        string userOption = "";
                        map <int, string> demandOptions;
                        bool resourceOption; // whether or not the player's command was resource related

                        while (true) {

                            demandOptions = getDemandOptions(issuer, recipient, userOption);
                            outputDemandOptions(demandOptions);

                            cin >> userSubInput;

                            resourceOption = demandOptions[userSubInput] == "energyD" || demandOptions[userSubInput] == "metalD" || demandOptions[userSubInput] == "oilD";

                            // Condition to require user input of a "region" where to take the resources from
                            if (resourceOption && resourceRecipientRegion == NULL) {
                                cout << "Demand resources for:" << endl;
                                resourceRecipientRegion = Country::inputRegion(issuer, NULL);
                                if (resourceDonorRegion == NULL) {
                                    continue;
                                }
                            }


                            if (demandOptions[userSubInput] == "MAccess") {
                                cout << "Amount of turns: ";
                                cin >> aPassRight;
                                if (aPassRight < 0) {
                                    aPassRight = 0;
                                }
                                userOption = "MAccess";
                                continue;
                            } else if (demandOptions[userSubInput] == "energyD"){
                                cout << "Amount of energy: ";
                                cin >> energy;
                                energy = -energy;
                                continue;
                            } else if (demandOptions[userSubInput] == "metalD") {
                                cout << "Amount of metal: ";
                                cin >> metal;
                                metal = -metal;
                                continue;
                            } else if (demandOptions[userSubInput] == "oilD") {
                                cout << "Amount of oil: ";
                                cin >> oil;
                                oil = -oil;
                                continue;
                            } else if (demandOptions[userSubInput] == "reset") {
                                resourceRecipientRegion = NULL;

                                aPassRight = 0;

                                if (metal < 0) {
                                    metal = 0;
                                }
                                if (oil < 0) {
                                    metal = 0;
                                }
                                if (energy < 0) {
                                    energy = 0;
                                }
                                continue;
                            } else if (demandOptions[userSubInput] == "back") {
                                break;
                            } else {
                                cout << endl << "Wrong Input" << endl;
                                continue;
                            }
                        }
                        break;
                    }
// to-do prevent text input crash (i.e. clear buffer)
                    case ('3'): {

                        cout << endl << "| Message |" << endl;
                        cout << "Your message to " << recipient->countryName << ": " << endl;

                        cin.ignore();
                        std::getline(std::cin,userMessage);
                        break;
                    }

                    case ('4'): { // SUMMARY

                        cout << endl << "| Summary | " << endl;


                        cout << endl << "> Offered" << endl;
                        if (formAlliance) {cout << " Form alliance " << endl;}
                        if (ceasefire) {cout << "> Cease of hostility" << endl;}
                        if (metal > 0) { cout << " Metal: " << metal << endl;}
                        if (energy > 0) { cout << " Energy: " << energy << endl;}
                        if (oil > 0) { cout << " Oil: " << oil << endl;}

                        cout << endl << "> Demanded" << endl;
                        if (aPassRight > 0 ) { cout << " Military access for " << aPassRight << " turn(s)" << endl;}
                        if (metal < 0) { cout << " Metal: " << -metal << endl;}
                        if (energy < 0) { cout << " Energy: " << -energy << endl;}
                        if (oil < 0) { cout << " Oil: " << -oil << endl;}

                        cout << endl << "> Message" << endl;
                        cout << endl << userMessage << endl;
                        cout << "----------------" << endl;
                        break;
                    }

                    case ('5'): {
                        char userSubInput;

                        cout << endl << "Do you want to send this request?" << endl;
                        cout << endl << "1: Confirm" << endl;
                        cout << "2: Back" << endl;
                        cout << "-> ";

                        cin >> userSubInput;

                        switch (userSubInput) {

                            case ('1'): {

                                cout << "Enter period of validity: ";
                                cin >> periodOfValidity;

                                if (periodOfValidity < 1) {
                                    cout << "Period of validity set to 1" << endl;
                                    periodOfValidity = 1;}

                                if (resourceDonorRegion != NULL) {
                                    // Reserving the offered resources until the request is resolved
                                    if (metal > 0) {
                                        resourceDonorRegion->deductResources(metal,0,0);
                                    }
                                    if (energy > 0) {
                                        resourceDonorRegion->deductResources(0,0, energy);
                                    }
                                    if (oil > 0) {
                                        resourceDonorRegion->deductResources(0,oil, 0);
                                    }
                                }
                                DiplomacyRequest * dr = new DiplomacyRequest(issuer,recipient, resourceRecipientRegion,
                                                            resourceDonorRegion, userMessage,formAlliance,
                                                            ceasefire,aPassRight, metal, oil, energy, periodOfValidity);

                                issuer -> sentDiplomacyRequests.push_back(dr);
                                recipient -> receivedDiplomacyRequests.push_back(dr);
                                allDiplomacyRequests.push_back(dr);

                                cout << "Request sent successfully" << endl;
                                // Send notification to recipient;
                                string notificationText;
                                notificationText = issuer->countryName + " sent you a diplomacy request.";
                                recipient->addNotification(notificationText);
                                break;
                            }

                            case ('2'): {
                                continue; }

                            default: {
                                cout << endl << "Wrong Input" << endl;
                                continue;
                            }
                        }
                    }
                    case ('6'): {
                        return;}

                    case ('7'): {
                        if (!areAtWar(issuer,recipient) && !areAllied(issuer,recipient)) {
                            char userSubInput;

                            cout << endl << "Confirm war declaration to " << recipient->countryName << "?" << endl;
                            cout << endl << "1: Confirm" << endl;
                            cout << "2: Back" << endl;
                            cout << "-> ";
                            cin >> userSubInput;

                            if (userSubInput == '1') {
                                warDeclaration(issuer, recipient);
                                cout << " War has been declared" << endl;

                                // Send notification to recipient;
                                string notificationText;
                                notificationText = issuer->countryName + " declared war to you! TO ARMS!";
                                recipient->addNotification(notificationText);
                                return;
                            } else {
                                continue;
                            }

                        }
                        break;
                    }

                    default: {
                        cout << endl << "Wrong Input" << endl;
                        continue;
                    }
                }
            }

        }
    void                    D_ControlInterf  (Country *countryInControl) {
        /** The function will provide a country object with information on received, sent, accepted diplomacy request
         * and let compose a new request.
         */

        do {
            cout << endl << "| DIPLOMACY |" << endl;
            cout << " 1: Treaty Report" << endl;
            cout << " 2: Sent Requests [" << countryInControl->sentDiplomacyRequests.size() << "]" << endl;
            cout << " 3: Received Requests [" << countryInControl->receivedDiplomacyRequests.size() << "]" << endl;
            cout << " 4: Compose new request" << endl;
            cout << " 5: Main Menu" << endl << "-> ";

            char userSelection;

            cin >> userSelection;

            switch (userSelection) {
                case ('1'): {

                    bool treatiesExist = !(countryInControl->territoryAccessRights.empty()
                                          && countryInControl->enemies.empty()
                                          && countryInControl->allies.empty());

                    if ( treatiesExist ) {

                        // MILITARY ACCESS TREATIES
                        for (MilitaryAccess *ma : countryInControl->territoryAccessRights) {
                            ma->coutMyself();
                        }
                        cout << endl;
                        // WAR TREATIES
                        for (Country *c : countryInControl->enemies) {
                            cout << "At war with: " << c->countryName << endl;
                        }
                        // ALLIED COUNTRIES
                        for (Country *c : countryInControl->allies) {
                            cout << "Alliance treaty with: " << c->countryName << endl;
                        }
                    } else {
                        cout << endl << "Nothing to display" << endl;
                    }
                    continue;
                }

                case ('2'): {
                    if (countryInControl->sentDiplomacyRequests.empty() ) {
                        cout << endl << "Nothing to display" << endl;

                    } else {

                        for (DiplomacyRequest *dr : countryInControl->sentDiplomacyRequests) {
                            cout << endl << "| Sent to: " << dr->recipientCountry->countryName<< " |" << endl;;
                            dr->coutReportOfConditions();

                        }
                    }
                    continue;
                }

                case ('3'): {

                    if (countryInControl->receivedDiplomacyRequests.empty()) {
                        cout << endl << "Nothing to display" << endl;

                    } else {
                        char confirmationInput;
                        for (DiplomacyRequest *dr : countryInControl->receivedDiplomacyRequests) {
                            cout << endl << "| Received from " << dr->issuerCountry->countryName << " |" << endl;
                            dr->coutReportOfConditions();

                            while (true) {
                                cout << endl << " 1. Confirm" << endl;
                                cout << " 2. Decline\n" << endl;
                                cout << " 3. > Next >\n";
                                cout << "-> ";

                                cin >> confirmationInput;
                                if (confirmationInput == '1') {
                                    bool requestConditionsSatisfied = false;
                                    requestConditionsSatisfied = confirm_D_Request(dr);

                                    if (!requestConditionsSatisfied) {
                                        continue;
                                    } else {

                                        string notificationText;
                                        notificationText = dr->recipientCountry->countryName + " confirmed your diplomacy request";
                                        dr->issuerCountry->addNotification(notificationText);
                                        break;}

                                } else if (confirmationInput == '2') {

                                    // First, return the offered resources to the issuer's stock
                                    if (dr->resourceRecipientRegion != NULL) {
                                        if (dr->energy > 0) {
                                            dr->resourceRecipientRegion->addToEnergyStock(dr->energy);
                                        }
                                        if (dr->metal > 0) {
                                            dr->resourceRecipientRegion->addToMetalStock(dr->metal);
                                        }
                                        if (dr->oil > 0) {
                                            dr->resourceRecipientRegion->addToOilStock(dr->oil);
                                        }
                                        string notificationText;
                                        notificationText = dr->recipientCountry->countryName + " declined your diplomacy request";
                                        dr->issuerCountry->addNotification(notificationText);
                                    }

                                    // OBJECT REMOVED FROM THE VECTOR OF ONGOING REQUESTS and sent/received vectors of both countries
                                    allDiplomacyRequests.erase(remove(allDiplomacyRequests.begin(), allDiplomacyRequests.end(),dr ), allDiplomacyRequests.end());
                                    dr->issuerCountry->removeSentRequest(dr);
                                    dr->recipientCountry->removeReceivedRequest(dr);

                                    delete dr;

                                    break;
                                } else {
                                    break;
                                }

                            }
                        }
                        continue;
                    }
                }

                case ('4'): {
                    new_DRequest(countryInControl);
                    continue;
                }


                case ('5'): {
                    return;
                }

                default: {
                    cout << endl << "Wrong Input" << endl;
                    continue;
                }


            }

        } while (true);
    }

    bool                    areAllied(Country *c1, Country *c2) {
        /** Checking whether or not c2 and c1 are allied to each other*/
        bool returnValue;
        returnValue = std::find(c1->allies.begin(), c1->allies.end(), c2) != c1->allies.end();
        return returnValue;
    }
    bool                    areAtWar(Country *c1, Country *c2) {
        /** Checking whether or not c1 is at war with c2 */
        bool returnValue;
        returnValue = std::find(c1->enemies.begin(), c1->enemies.end(), c2) != c1->enemies.end();
        return returnValue;
    }
    bool                    haveMAccess(Country *c1, Country *c2) {
        /** Checking whether or not c2 has provided military access rights to c1 */
        for (MilitaryAccess *ma : c1->territoryAccessRights) {
            if (ma->getProvider() == c2) {
                return true;
            }

        }
        return false;
    }
    bool                    isNeutral(Country *c1, Country *c2) {
        for (Country* c : c1->neutral) {
            if (c == c2) {
                return true;
            } else {
                return false;
            }
        }
    }

    map <int, string>       getOfferOptions (Country *issuer, Country *recipient, string userSelectedOption) {

        map <int, string> outMap;
        int i = 1;

        if (isNeutral(issuer, recipient) && userSelectedOption != "alliance") {
            outMap[i] = "alliance";
        } else if (areAllied(issuer, recipient)) {
            i--;
        } else if (areAtWar(issuer, recipient) && userSelectedOption != "ceasefire"){
            outMap[i] = "ceasefire";
        } else {
            i = 0;
        }

        outMap[i+1] = "energyO";
        outMap[i+2] = "metalO";
        outMap[i+3] = "oilO";
        outMap[i+4] = "reset";
        outMap[i+5] = "back";

        return outMap;
    }
    void                    outputOfferOptions (map <int, string> options) {

        cout << endl << "| Offer |" << endl;
        for (auto& option : options) {
            if (option.second == "alliance") {
                cout << option.first << ": Propose an alliance" << endl;
            } else if (option.second == "ceasefire") {
                cout << option.first << ": Propose a ceasefire" << endl;
            } else if (option.second == "energyO") {
                cout << option.first << ": Energy" << endl;
            } else if (option.second == "metalO") {
                cout << option.first << ": Metal" << endl;
            } else if (option.second == "oilO") {
                cout << option.first << ": Oil" << endl;
            } else if (option.second == "reset") {
                cout << option.first << ": Reset" << endl;
            } else if (option.second == "back") {
                cout << option.first << ": < Back <" << endl;
            }
        }
        cout << "-> ";
    }

    map <int, string>       getDemandOptions (Country *issuer, Country *recipient, string userSelectedOption) {

        map <int, string> outMap;
        int i = 1;

        if ( !haveMAccess(issuer, recipient) && (userSelectedOption != "MAccess") && (isNeutral(issuer, recipient))) {
            outMap[i] = "MAccess";
        } else {
            i = 0;
        }

        outMap[i+1] = "energyD";
        outMap[i+2] = "metalD";
        outMap[i+3] = "oilD";
        outMap[i+4] = "reset";
        outMap[i+5] = "back";

        return outMap;
    }
    void                    outputDemandOptions (map <int, string> options) {

        cout << endl << "| DEMAND |" << endl;
        for (auto& option : options) {
            if (option.second == "MAccess") {
                cout << option.first << ": Military access right" << endl;
            } else if (option.second == "energyD") {
                cout << option.first << ": Energy" << endl;
            } else if (option.second == "metalD") {
                cout << option.first << ": Metal" << endl;
            } else if (option.second == "oilD") {
                cout << option.first << ": Oil" << endl;
            } else if (option.second == "reset") {
                cout << option.first << ": Reset" << endl;
            } else if (option.second == "back") {
                cout << option.first << ": < Back <" << endl;
            }
        }
        cout << "-> ";
    }
//  ### COUNTRY CONTROL ###

    map <string, Country*>  countries_to_map (Country *inCountry) {
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
    Country*                input_Country    (Country *inCountry) {
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

        cout << endl << "Select a country" << endl;



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

    void                    C_ControlInterf  (Country *countryInControl) {
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

        char command;

        while (true) {  // MAINLOOP
            cout << endl << "[ Turn " << Manager::turn << " ] >>> " << countryInControl->countryName << " <<<" << endl ;

            cout << endl << " 1: Diplomacy" << endl;
            cout << " 2: Regions" << endl;
            cout << " 3: Notifications [" << countryInControl->notifications.size() << "]" << endl;
            cout << " 4: End turn" << endl;
            cout <<  "->  ";

            cin >> command;

            switch (command) {

                case ('1'):{
                    D_ControlInterf(countryInControl);
                    break;
                }

                case ('2'): {
                    Region *selectedRegion;
                    string functionOutcome;

                    do {
                        selectedRegion = countryInControl->inputRegion(countryInControl, NULL);
                        if (selectedRegion == NULL) { break; }
                        functionOutcome = countryInControl->regionControlInterface(selectedRegion);
                    } while (functionOutcome == "back to region selection");
                    break;
                }

                case ('3'): {
                    countryInControl->printNotifications();

                    break;
                }

                case ('4'): {
                    return;
                }

                default: {
                    cout << endl << "Wrong Input" << endl;
                    continue;
                }

            }
        }
    };

//  #############################
    void                    saveGame();
    void                    loadGame();


    Manager()
    {
        initRegions();

    }

    virtual ~Manager() {
    }

};


#endif //ALL_PROJECT_2_MANAGER_H