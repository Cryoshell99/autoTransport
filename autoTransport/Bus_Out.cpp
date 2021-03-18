//#pragma once
#include <fstream>
#include "Bus.h"

using namespace std;

void Out(Bus* b, ofstream& ofst) 
{
	ofst << "It is Bus, passenger capacity = " << b->mData << ", Engine power = " << b->tPower << ", Fuel consumption per 100 km = " << b->fuelConsumption << endl;
};

float WPRatio(Bus* b)
{
	return (float)(75* b->mData)/(float)b->tPower;
};