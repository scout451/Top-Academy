#include <string>
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include "Menu.h"
#include <conio.h>

using namespace std;
using namespace std::filesystem;

void main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int selectedOption = 0;
	int totalOptions = 10;

	while (true)
	{
		try
		{
			PrintMenu(selectedOption);
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				if (key == 72)
				{
					if (selectedOption > 0)
						--selectedOption;
				}
				else if (key == 80)
				{
					if (selectedOption < totalOptions - 1)
						++selectedOption;
				}
				system("cls");
			}
			else if (key == 13)
			{
				if (selectedOption == 9)
				{
					return;
				}
				RunMenu(selectedOption);
			}
		}
		catch (const string& error)
		{
			cout << "Error: " << error << endl;
		}
		catch(...)
		{
			cout << "Unknown error" << endl;
		}
	}
	system("pause");
}
