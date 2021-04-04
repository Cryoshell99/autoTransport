#include <fstream>
#include "Truck.h"

using namespace std;

Truck* InTruck(ifstream& ifst)
{
	Truck* t;
	t = new Truck;
	t->mKey = type::TRUCK;
	ifst >> t->mPower;
	ifst >> t->mData;
	return t;
}
