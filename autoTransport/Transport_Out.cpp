#include <fstream>
#include "Transport.h"

using namespace std;

void Out(Bus* b, ofstream& ofst);
void Out(Truck* t, ofstream& ofst);
void Out(Car* c, ofstream& ofst);
float weightToPowerRatio(Bus* b);
float weightToPowerRatio(Truck* t);
float weightToPowerRatio(Car* c);

float weightToPowerRatio(Transport* tr)
{
	if (tr != NULL)
	{
		switch (tr->mKey) {
		case type::BUS:
			return weightToPowerRatio((Bus*)(tr));
			break;
		case type::TRUCK:
			return weightToPowerRatio((Truck*)tr);
			break;
		case type::CAR:
			return weightToPowerRatio((Car*)tr);
			break;
		}
	}
	else
	{
		return NULL;
	}
};

void Out(Transport* tr, ofstream& ofst)
{
	if (tr == NULL)
	{
		ofst << "Incorrect type of Transport!" << endl << endl;
	}
	else
	{
		switch (tr->mKey) {
		case type::BUS:
			Out((Bus*)(tr), ofst);
			break;
		case type::TRUCK:
			Out((Truck*)tr, ofst);
			break;
		case type::CAR:
			Out((Car*)tr, ofst);
			break;
		}
		ofst << weightToPowerRatio(tr) << " Weight to Power ratio" << endl << endl;
	}
};

