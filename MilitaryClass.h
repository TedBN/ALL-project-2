/* MilitaryClass.h :
 Header for the military units class.*/

#ifndef MILITARY_H

#include "stdafx.h"
#include <string>
#include <iostream>

class MilitaryUnit 
{
	/*This class handles all military units. Contains all 
	declarations, definitions are in the .cpp file.*/

	//Class members and functions here.
	int attack, health, speed, range, energyCost, metalCost, oilCost, manpowerCost, buildCost;
	void set_stats(int, int, int);
	void set_range(int);
	void set_resourceCost(int, int, int, int);
	void set_buildCost(int);

	//Friend classes and functions here.
	friend class LandUnit;
	friend class AirUnit;
	friend class NavalUnit;
	friend class Regions;
	friend class Controller;
};

class LandUnit : public MilitaryUnit
{
	//Constructors
	public:
		int type = 1;
		LandUnit();
		LandUnit(int, int, int, int, int, int, int, int, int);
};

class AirUnit : public MilitaryUnit 
{
	//Constructors
	public:
		int type = 2;
		AirUnit();
		AirUnit(int, int, int, int, int, int, int, int, int);
};

class NavalUnit : public MilitaryUnit 
{
	//Constructors
	public:
		int type = 3;
		NavalUnit();
		NavalUnit(int, int, int, int, int, int, int, int, int);
};

#define MILITARY_H

#endif
