//#pragma once
#include <fstream>
#include "Truck.h"

using namespace std;

void Out(Truck* t, ofstream& ofst)
{
	ofst << "It is Truck, carrying capacity = " << t->mData << ", Engine power = " << t->tPower << ", Fuel consumption per 100 km = " << t->fuelConsumption << endl;
};

float WPRatio(Truck* t)
{
	return (float)t->mData/(float)t->tPower;
};