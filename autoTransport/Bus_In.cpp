#include <fstream>
#include "Bus.h"
#include <vector>

using namespace std;

Bus* InBus(ifstream& ifst)
{
	Bus* b;
	b = new Bus;
	b->mKey = type::BUS;

	double inh;
	bool flag = true;
	vector<double> tail;
	do
	{
		ifst >> inh;
		if (ifst.fail())
		{
			//Восстановили поток
			ifst.clear();
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
			break;
		}
		if (inh >= 0)
		{
			tail.push_back(inh);
		}
	} while (!ifst.eof() && ifst.peek() != '\n');

	if (tail.size() == 3 && flag)
	{
		if (tail[0] > 0 || tail[0] < 103)
		{
			b->tPower = inh;
			b->mData = tail[1];
			b->fuelConsumption = tail[2];
		return b;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}

	//ifst >> b->tPower;
	//ifst >> b->mData;
	//ifst >> b->fuelConsumption;
	//return b;
}
