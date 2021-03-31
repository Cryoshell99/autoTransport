#include <fstream>
#include "Car.h"
#include <vector>

using namespace std;

Car* InCar(ifstream& ifst)
{
	Car* c;
	c = new Car;
	c->mKey = type::CAR;

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
		if (tail[0] > 0 || tail[0] < 490)
		{
			c->tPower = inh;
			c->mData = tail[1];
			c->fuelConsumption = tail[2];
			return c;
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

	//ifst >> c->tPower;
	//ifst >> c->mData;
	//ifst >> c->fuelConsumption;
	//return c;
}
