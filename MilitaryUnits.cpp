/*MilitaryUnits.cpp:
This file contains the military units of the game
and the function to initialize them.*/

#include "stdafx.h"
#include <iostream>
#include "MilitaryClass.h"

void init_LandUnits()
{
	/*This function initializes all the military units in the game.*/

	//Land units
	LandUnit infantry(100, 20, 2, 0, 150, 75, 50, 100, 6);
	LandUnit engineer(75, 15, 2, 0, 250, 150, 100, 75, 9);
	LandUnit tank(50, 40, 5, 0, 400, 300, 250, 30, 12);
	LandUnit helicopter(40, 20, 8, 0, 250, 125, 75, 20, 9);
	LandUnit artillery(40, 20, 2, 2, 200, 150, 50, 30, 8);
}