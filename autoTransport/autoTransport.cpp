#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"

using namespace std;

void Init(Container& cnt);
void Clear(Container*& cnt);
void In(Container& cnt, ifstream& ifst);
void Out(Container& cnt, ofstream& ofst);
void OutBus(Container& cnt, ofstream& ofst);
void Sort(Container*& cnt);

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	// Ввод из input.txt
	ifstream ifst(argv[1]);
	// Вывод в output.txt
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	// Создаем экземпляр контейнера
	Container* cnt = new Container;
	// Инициализируем его
	Init(*cnt);
	// Заполняем контейнер
	In(*cnt, ifst);
	ofst << "Filled container. " << endl;
	// Выводим содержимое
	Out(*cnt, ofst);
	// Сортированный вывод
	ofst << endl << endl << "Sorted Container!!!" << endl;
	Sort(cnt);
	Out(*cnt, ofst);

	// Фильтрованный вывод
	OutBus(*cnt, ofst);
	// Чистим его
	Clear(cnt);
	// Демностируем содержимое контейнера
	Out(*cnt, ofst);
	cout << "Stop" << endl;
	system("pause");

	return 0;
}