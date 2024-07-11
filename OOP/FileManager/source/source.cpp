#include <string>
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include "Menu.h"

using namespace std;
using namespace std::filesystem;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int action;

	while (true)
	{
		PrintMenu();
		cin >> action;
		try
		{
			if (RunMenu(action)) return;
		}
		catch (const string& error)
		{
			cout << "Error: " << error << endl;
		}
		catch (...)
		{
			cout << "Unknown error" << endl;
		}
	}
	system("pause");
}
