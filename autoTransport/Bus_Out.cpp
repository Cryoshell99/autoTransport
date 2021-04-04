//#pragma once
#include <fstream>
#include "Bus.h"

using namespace std;

void Out(Bus* b, ofstream& ofst) 
{
	ofst << "It is Bus, passenger capacity = " << b->mData << ", Engine power = " << b->mPower << endl;
};