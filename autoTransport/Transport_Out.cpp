#include <fstream>
#include "Transport.h"

using namespace std;

void Out(Bus* b, ofstream& ofst);
void Out(Truck* t, ofstream& ofst);
void Out(Car* c, ofstream& ofst);
float WPRatio(Bus* b);
float WPRatio(Truck* t);
float WPRatio(Car* c);

float WPRatio(Transport* tr)
{
	if (tr != NULL)
	{
		switch (tr->mKey) {
		case type::BUS:
			return WPRatio((Bus*)(tr));
			break;
		case type::TRUCK:
			return WPRatio((Truck*)tr);
			break;
		case type::CAR:
			return WPRatio((Car*)tr);
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
		ofst << "Incorrect type of Transport!" << endl;
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
		ofst << WPRatio(tr) << " Weight to power ratio" << endl << endl;
	}
};

