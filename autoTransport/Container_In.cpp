#include "Container.h"
#include <fstream>

using namespace std;

Transport* In(ifstream& ifst);

void In(Container& cnt, ifstream& ifst)
{
	// Пока не достигнут конец входного потока
	while (!ifst.eof())
	{
		// Создаем временный контейнер
		Container* temp = new Container;
		// Заполняем его
		if ((&cnt == cnt.Next) && (!ifst.tellg()))
		{
			cnt.L = In(ifst);
		}
		else
		{
			// Идем на последний элемент
			Container* counter = cnt.Next;
			while (counter->Next != &cnt)
			{
				counter = counter->Next;
			}

			counter->Next = temp;
			temp->L = In(ifst);
			temp->Next = &cnt;
		}
	}
};