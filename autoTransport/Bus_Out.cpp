//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Bus.h"

using namespace std;

void Out(Bus* b, ofstream& ofst) 
{
	ofst << "It is Bus, passenger capacity = " << b->mData << ", Engine power = " << b->mPower << ", Fuel consumption per 100 km = " << b->mFuelConsumption << endl;
};

float weightToPowerRatio(Bus* b)
{
	return (float)(75* b->mData)/(float)b->mPower;
};