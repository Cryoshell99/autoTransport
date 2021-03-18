//#pragma once
#include <fstream>
#include "Car.h"

using namespace std;

void Out(Car* c, ofstream& ofst) 
{
	ofst << "It is Car, maximum speed = " << c->mData << ", Engine power = " << c->tPower << ", Fuel consumption per 100 km = " << c->fuelConsumption << endl;
};

float WPRatio(Car* c)
{
	return (float)(75 * 4) / (float)c->tPower;
};