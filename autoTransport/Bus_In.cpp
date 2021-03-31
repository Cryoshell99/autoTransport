#include <fstream>
#include "Bus.h"
#include <vector>

using namespace std;

Bus* inBus(ifstream& ifst)
{
	Bus* b;
	b = new Bus;
	b->mKey = type::BUS;

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
		if (tail[0] > 0 || tail[0] < 103)
		{
			b->mData = tail[0];
			b->mPower = tail[1];
			b->mFuelConsumption = tail[2];
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
}
