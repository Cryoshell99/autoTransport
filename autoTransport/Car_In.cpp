#include <fstream>
#include "Car.h"
#include <vector>

using namespace std;

Car* inCar(ifstream& ifst)
{
	Car* c;
	c = new Car;
	c->mKey = type::CAR;

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
		if (tail[0] > 0 || tail[0] < 490)
		{
			c->mData = tail[0];
			c->mPower = tail[1];
			c->mFuelConsumption = tail[2];
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
}
