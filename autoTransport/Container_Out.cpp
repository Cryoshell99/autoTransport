#include "Container.h"
#include <fstream>

using namespace std;

void Out(Transport* tr, ofstream& ofst);
//void OutBus(Transport* tr, ofstream& ofst);
float WPRatio(Transport* tr);
bool Compare(Transport* first, Transport* second);

void Sort(Container*& cnt)
{
	//if container contains 1 element, do nothing
	if (cnt == cnt->Next)
	{
		return;
	}
	Container* current = cnt;
	bool flag = false;
	Transport* temp;
	//buble sort
	do
	{
		current = cnt;
		//if we didnt swap elements container is sorted
		flag = false;
		do
		{
			if (Compare(current->L, current->Next->L))
			{
				temp = current->L;
				current->L = current->Next->L;
				current->Next->L = temp;
				flag = true;
			}
			current = current->Next;

		} while (current->Next != cnt);
	} while (flag);
};


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

void OutBus(Container& cnt, ofstream& ofst)
{
	ofst << endl << "Only Bus transports:" << endl;
	// Если контейнер не пуст
	if (&cnt != nullptr)
	{
		ofst << "Container contains that elements:" << endl;
		Container* temp;
		temp = &cnt;
		int i = 0;
		do
		{
			ofst << i << ": ";
			if (temp->L->mKey == type::BUS)
			{
				Out(temp->L, ofst);
			}
			else
			{
				ofst << endl;
			}
			temp = temp->Next;
			i++;
		} while (temp != &cnt);
	}
	else
	{
		ofst << "Container is empty!" << endl;
	}
};