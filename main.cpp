#include <iostream>

#include "vector"
#include "Region.h"

#include <string>

#include <string>

using namespace std;


int main() {
    vector < Region> regions;
    Region latvia;
    Region lithuania;


    int x = 5;


    regions.push_back(latvia);
    regions.insert(regions.begin()+1, lithuania);

    x = latvia.oil;

    string x_str = to_string(x);


    cout << regions.at(0).asda;


//    for (int i = 0; i < regions.size(); ++i) {
//        cout << latvia.;
//
//        return EXIT_SUCCESS;


}