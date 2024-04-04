#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

void main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 10;
	int arr[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 10;

	while(true)
	{
		system("cls");

		cout << "1. Вывести массив" << endl;
		cout << "2. Отсортировать по возрастанию" << endl;
		cout << "3. Отсортировать по убыванию" << endl;
		cout << "0. Выход" << endl;

		int input;
		cin >> input;

		if (input == 0)
			break;

		switch (input)
		{
		case 1:
			for (int i = 0; i < size; i++)
				cout << arr[i] << " ";
			cout << endl;
			system("pause");
			break;
		case 2:
			sort(arr, arr + size);
			break;
		case 3:
			sort(arr, arr + size, [](int a, int b) {return a > b; });
			break;
		default:
			break;
		}
	}

	system("pause");
}