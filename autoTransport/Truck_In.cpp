#include <fstream>
#include "Truck.h"
#include <vector>

using namespace std;

Truck* InTruck(ifstream& ifst)
{
	Truck* t;
	t = new Truck;
	t->mKey = type::TRUCK;

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
		if (tail[0] > 0.0 || tail[0] < 450.0)
		{
			t->tPower = inh;
			t->mData = tail[1];
			t->fuelConsumption = tail[2];
			return t;
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

	//ifst >> t->tPower;
	//ifst >> t->mData;
	//ifst >> t->fuelConsumption;
	//return t;
}
