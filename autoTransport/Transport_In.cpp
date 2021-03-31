//#pragma once
#include <fstream>
#include "Transport.h"

using namespace std;

Truck* inTruck(ifstream& ifst);
Bus* inBus(ifstream& ifst);
Car* inCar(ifstream& ifst);

Transport* In(int key, ifstream& ifst)
{
	int inh;
	switch (key)
	{
	case 1:
		return (Transport*)inBus(ifst);
	case 2:
		return (Transport*)inTruck(ifst);
	case 3:
		return (Transport*)inCar(ifst);
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

	if (ifst.fail())
	{
		//Восстановили поток
		ifst.clear();
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		return NULL;
	}

	tr = In(k, ifst);
	return tr;
};
