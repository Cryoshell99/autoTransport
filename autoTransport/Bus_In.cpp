#include <fstream>
#include "Bus.h"

using namespace std;

Bus* InBus(ifstream& ifst)
{
	Bus* b;
	b = new Bus;
	b->mKey = type::BUS;
	ifst >> b->mPower;
	ifst >> b->mData;
	return b;
}
