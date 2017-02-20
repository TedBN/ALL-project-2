// MilitaryClass.cpp :
// Defines the class for military units, along with it's functions and children.

#include "stdafx.h"
#include <string>
#include <iostream>
#include "MilitaryClass.h"

void MilitaryUnit::set_stats(int a, int h, int s) 
{
	attack = a;
	health = h;
	speed = s;
}

void MilitaryUnit::set_range(int r) 
{
	range = r;
}

void MilitaryUnit::set_resourceCost(int ec, int mc, int oc, int tc) 
{
	energyCost = ec;
	metalCost = mc;
	oilCost = oc;
	manpowerCost = tc;
}

void MilitaryUnit::set_buildCost(int bc)
{
	buildCost = bc;
}

LandUnit::LandUnit()
{
	attack = 0;
	health = 0;
	speed = 0;
	range = 0;
	energyCost = 0;
	metalCost = 0;
	oilCost = 0;
	manpowerCost = 0;
	buildCost = 0;
}

LandUnit::LandUnit(int a, int h, int s, int r, int ec, int mc, int oc, int tc, int bc)
{
	attack = a;
	health = h;
	speed = s;
	range = r;
	energyCost = ec;
	metalCost = mc;
	oilCost = oc;
	manpowerCost = tc;
	buildCost = bc;
}

AirUnit::AirUnit()
{
	attack = 0;
	health = 0;
	speed = 0;
	range = 0;
	energyCost = 0;
	metalCost = 0;
	oilCost = 0;
	manpowerCost = 0;
	buildCost = 0;
}

AirUnit::AirUnit(int a, int h, int s, int r, int ec, int mc, int oc, int tc, int bc)
{
	attack = a;
	health = h;
	speed = s;
	range = r;
	energyCost = ec;
	metalCost = mc;
	oilCost = oc;
	manpowerCost = tc;
	buildCost = bc;
}

NavalUnit::NavalUnit()
{
	attack = 0;
	health = 0;
	speed = 0;
	range = 0;
	energyCost = 0;
	metalCost = 0;
	oilCost = 0;
	manpowerCost = 0;
	buildCost = 0;
}

NavalUnit::NavalUnit(int a, int h, int s, int r, int ec, int mc, int oc, int tc, int bc)
{
	attack = a;
	health = h;
	speed = s;
	range = r;
	energyCost = ec;
	metalCost = mc;
	oilCost = oc;
	manpowerCost = tc;
	buildCost = bc;
}
