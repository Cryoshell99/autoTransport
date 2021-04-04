#include "Container.h"
#include <fstream>

using namespace std;

void Out(Transport* tr, ofstream& ofst);

void Out(Container& cnt, ofstream& ofst)
{
	// Если контейнер не пуст
	if (&cnt != nullptr)
	{
		ofst << "Container contains that elements:" << endl;
		Container *temp;
		temp = &cnt;
		int i = 0;
		do
		{
			ofst << i << ": ";
			Out(temp->L, ofst);
			temp = temp->Next;
			i++;
		} while (temp != &cnt);
	}
	else
	{
		ofst << "Container is empty!" << endl;
	}
};