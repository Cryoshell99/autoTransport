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
		while (first->Next != &c)
		{
			// Выводим фразу
			second = first->Next;
			while (second != &c) 
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
					default:
						ofst << "Unknown type." << endl;
						break;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
					break;
				}
				// Выводим данные, попадающие под неё
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