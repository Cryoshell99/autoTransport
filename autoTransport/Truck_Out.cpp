//#pragma once
#include <fstream>
#include "Truck.h"

using namespace std;

void Out(Truck* t, ofstream& ofst)
{
	ofst << "It is Truck, carrying capacity = " << t->mData << ", Engine power = " << t->mPower << endl;
};