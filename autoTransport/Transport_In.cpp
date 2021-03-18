//#pragma once
#include <fstream>
#include "Transport.h"

using namespace std;

Truck* InTruck(ifstream& ifst);
Bus* InBus(ifstream& ifst);
Car* InCar(ifstream& ifst);

Transport* In(int key, ifstream& ifst)
{
	int inh;
	switch (key)
	{
	case 1:
		return (Transport*)InBus(ifst);
	case 2:
		return (Transport*)InTruck(ifst);
	case 3:
		return (Transport*)InCar(ifst);
	default:
		char ch;
		ifst >> ch;
		//
		while (!ifst.eof() && ifst.peek() != '\n')
		{
			ifst >> ch;
		}
		return NULL;
	}
};

Transport* In(ifstream& ifst) 
{
	Transport* tr;
	int k;
	ifst >> k;
	tr = In(k, ifst);
	return tr;
};
