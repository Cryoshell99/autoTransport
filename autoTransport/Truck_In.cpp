#include <fstream>
#include "Truck.h"
#include <vector>

using namespace std;

Truck* inTruck(ifstream& ifst)
{
	Truck* t;
	t = new Truck;
	t->mKey = type::TRUCK;

	float inh;
	bool flag = true;
	vector<float> tail;
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
		if (tail[0] > 0 || tail[0] < 450)
		{
			t->mData = tail[0];
			t->mPower = tail[1];
			t->mFuelConsumption = tail[2];
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
}
