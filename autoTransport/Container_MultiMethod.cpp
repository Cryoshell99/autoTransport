#include "Container.h"
#include <fstream>

using namespace std;

void Out(Transport* tr, ofstream& ofst);

void MultiMethod(Container& c, ofstream& ofst)
{
	if (&c != nullptr)
	{
		ofst << endl << "Multimethod:" << endl;
		Container* first;
		Container* second;
		first = &c;
		//second = c.Next;
		while (first->Next != &c) //from 0 to n-1
		{
			second = first->Next;
			while (second != &c) //from first to n
			{
				if (first->L == NULL || second->L == NULL)
				{
					ofst << "Unknown type." << endl;
				}
				else
				{
					switch (first->L->mKey)
					{
					case type::BUS:
						switch (second->L->mKey)
						{
						case type::BUS:
							ofst << "Bus and Bus." << endl;
							break;
						case type::TRUCK:
							ofst << "Bus and Truck." << endl;
							break;
						case type::CAR:
							ofst << "Bus and Car" << endl;
							break;
						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;
					case type::TRUCK:
						switch (second->L->mKey)
						{
						case type::BUS:
							ofst << "Truck and Bus." << endl;
							break;
						case type::TRUCK:
							ofst << "Truck and Truck." << endl;
							break;
						case type::CAR:
							ofst << "Truck and Car" << endl;
							break;
						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;
					case type::CAR:
						switch (second->L->mKey)
						{
						case type::BUS:
							ofst << "Car and Bus." << endl;
							break;
						case type::TRUCK:
							ofst << "Car and Truck." << endl;
							break;
						case type::CAR:
							ofst << "Car and Car" << endl;
							break;
						default:
							ofst << "Unknown type." << endl;
							break;
						}
						break;
					default:
						ofst << "Unknown type." << endl;
						break;
					}
				}
				Out(first->L, ofst);
				Out(second->L, ofst);
				ofst << endl;
				second = second->Next;
			}
			first = first->Next;
		}
	}
	else
	{
		ofst << "Container is empty!" << endl;
	}
}