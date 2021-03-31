//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Car.h"

using namespace std;

void Out(Car* c, ofstream& ofst) 
{
	ofst << "It is Car, maximum speed = " << c->mData << ", Engine power = " << c->mPower << ", Fuel consumption per 100 km = " << c->mFuelConsumption << endl;
};

float weightToPowerRatio(Car* c)
{
	return (float)(75 * 4) / (float)c->mPower;
};