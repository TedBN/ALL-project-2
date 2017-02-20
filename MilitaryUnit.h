// MilitaryUnits.cpp : Defines the class for military units, along with it's functions and children.

#include <iostream>
using namespace std;

class MilitaryUnit {
	public:
		int attack, health, speed, range, energyCost, metalCost, oilCost, manpowerCost, buildCost;
		void set_stats(int, int, int);
		void set_range(int);
		void set_resourceCost(int,int,int,int);
		void set_buildCost(int);
};

void MilitaryUnit::set_stats(int a, int h, int s) {
	attack = a;
	health = h;
	speed = s;
};

void MilitaryUnit::set_range(int r) {
	range = r;
};

void MilitaryUnit::set_resourceCost(int e, int m, int o, int t) {
	energyCost = e;
	metalCost = m;
	oilCost = o;
	manpowerCost = t;
};

void MilitaryUnit::set_buildCost(int c) {
	buildCost = c;
};


class LandUnit : public MilitaryUnit {

    int quantity;

    int moneyCost;
    int energyCost;


}infantry, engineers, tanks, helicopters, artillery, antiair, antitank;

class AirUnit : public MilitaryUnit {
}fighter, bomber;

class NavalUnit : public MilitaryUnit {
}submarine, destroyer, cruiser, heavyCruiser, battleship, aircraftCarrier;

//int main()
//{
//	cout << "Function test:\n";
//	LandUnit infantry;
//	infantry.set_stats(75,750,2);
//	infantry.set_range(0);
//	infantry.set_resourceCost(50,150,0,8);
//	infantry.set_buildCost(800);
//	cout << "Combat stats: " << infantry.attack << " attack, " << infantry.health << " HP, " << infantry.speed << " speed\n";
//	cout << "Resource cost: " << infantry.energyCost << " energy, " << infantry.metalCost << " metal, " << infantry.oilCost << " oil, " << infantry.manpowerCost << " manpower, " << infantry.buildCost << " production to build\n";
//    return 0;
//};
