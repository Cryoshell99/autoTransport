#include <fstream>
#include "Car.h"

using namespace std;

Car* InCar(ifstream& ifst)
{
	Car* c;
	c = new Car;
	c->mKey = type::CAR;
	ifst >> c->tPower;
	ifst >> c->mData;
	ifst >> c->fuelConsumption;
	return c;
}
