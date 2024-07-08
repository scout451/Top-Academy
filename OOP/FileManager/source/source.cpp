#include <string>
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include "Menu.h"

using namespace std;
using namespace std::filesystem;

//void TestFileManager()
//{
//	FileManager A;
//	
//	path newFolder = "C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\newFolder";
//	path newPath = "C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\oldFolder";
//	path newFile = newFolder / "newFile.txt";
//	path newNameFile = newPath / "File.txt";
//	//A.ContentsOfTheDisks();
//	A.CreatingFolder(newFolder);
//	A.CreatingFile(newFile);
//	//A.RemoveFile(newFile);
//	//A.Rename(newFolder, newPath);
//	//A.Rename(newPath / "newFile.txt", newNameFile);
//	A.Copy(newFolder, ".\\copyingFolder");
//	cout << A.GetSize("C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\source.cpp")<<endl;
//	for (auto pathses : A.Search("qwerty.txt", "C:\\"))
//		cout << pathses << endl;
//	A.Remove(newFolder);
//	A.Remove(".\\copyingFolder");

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//TestFileManager();
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
