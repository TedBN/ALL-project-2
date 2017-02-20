/*Controller.h:
This file contains the controller class definition
and declares its functions.*/

#ifndef CONTROLLER_H

#include "stdafx.h"
#include "MilitaryClass.h"
#include "RegionClass.h"

class Controller
{
	/*This class contains all functions that run the game.*/

	//Functions
	int buyUnits(MilitaryUnit uType, int num, Regions buyer);
};

#define CONTROLLER_H

#endif
