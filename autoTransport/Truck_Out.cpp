//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Truck.h"

using namespace std;

void Out(Truck* t, ofstream& ofst)
{
	ofst << "It is Truck, carrying capacity = " << t->mData << ", Engine power = " << t->mPower << ", Fuel consumption per 100 km = " << t->mFuelConsumption << endl;
};

float weightToPowerRatio(Truck* t)
{
	return (float)t->mData/(float)t->mPower;
};