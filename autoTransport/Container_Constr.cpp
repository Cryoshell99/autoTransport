#include "Container.h"
#include "iostream"

void Clear(Container*& cnt)
{
	// Создаем временный контейнер
	Container* temp;
	temp = cnt->Next;
	// Чистим контейнер забирая содержимое
	while (temp != cnt)
	{
		cnt->Next = temp->Next;
		delete temp;
		temp = cnt->Next;
	}
	delete cnt;
	cnt = nullptr;
};

void Init(Container& cnt)
{
	// Инициализируем
	cnt.Next = &cnt;
	cnt.L = NULL;
};
