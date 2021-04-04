//#pragma once
#include <fstream>
#include "Car.h"

using namespace std;

void Out(Car* c, ofstream& ofst) 
{
	ofst << "It is Car, maximum speed = " << c->mData << ", Engine power = " << c->mPower << endl;
};