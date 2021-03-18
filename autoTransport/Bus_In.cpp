#include <fstream>
#include "Bus.h"

using namespace std;

Bus* InBus(ifstream& ifst)
{
	Bus* b;
	b = new Bus;
	b->mKey = type::BUS;
	ifst >> b->tPower;
	ifst >> b->mData;
	ifst >> b->fuelConsumption;
	return b;
}
