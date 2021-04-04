#include <fstream>
#include "Transport.h"

using namespace std;

void Out(Bus* b, ofstream& ofst);
void Out(Truck* t, ofstream& ofst);

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
		}
	}
};