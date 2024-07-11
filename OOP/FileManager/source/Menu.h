#pragma once
#include <filesystem>
#include "Menu.h"
#include "FileManager.h"

using namespace std;
using namespace std::filesystem;

bool RunMenu(int action)
{
	FileManager obj;
	switch (action)
	{
	case 0:
	{
		try
		{
			path newPath;
			cout << "\n\nВведите новый путь до директории: " << endl;
			cin >> newPath;
			current_path(newPath);
		}
		catch (const string& error)
		{
			throw format("Unsuccessful movement through the directory");
		}
		break;
	}
	case 1:
	{
		path sourcePath;
		cout << "\n\nВведите путь: " << endl;
		cin >> sourcePath;
		obj.ContentsOfTheDisks(sourcePath);
		system("pause");
		cout << endl << endl;
		break;
	}
	case 2:
	{
		cout << "\n\nВыберите действие: " << endl;
		cout << "1. Создать файл." << endl;
		cout << "2. Создать папку.\n" << endl;
		int createAction;
		string sourcePath;
		cin >> createAction;
		if (createAction == 1)
		{
			cout << "\n\nВведите название файла: " << endl;
			cin >> sourcePath;
			obj.CreatingFile(sourcePath);
		}
		else
		{
			cout << "\n\nВведите название папки: " << endl;
			cin >> sourcePath;
			obj.CreatingFolder(sourcePath);
		}
		cout << "Объект создан.\n\n" << endl;
		system("pause");
		cout << endl << endl;
		break;
	}
	case 3:
	{
		path sourcePath;
		cout << "\n\nВведите путь до объекта удаления: " << endl;
		cin >> sourcePath;
		obj.Remove(sourcePath.string());
		cout << "Объект удален.\n\n" << endl;
		system("pause");
		cout << endl << endl;
		break;
	}
	case 4:
	{
		path sourcePath;
		path newName;
		cout << "\n\nВведите путь до объекта переименования: " << endl;
		cin >> sourcePath;
		cout << "\n\nВведите новое имя: " << endl;
		cin >> newName;
		path newFullPath = sourcePath.parent_path() / newName;
		obj.Rename(sourcePath.string(), newFullPath);
		cout << "Объект переименован.\n\n" << endl;
		system("pause");
		cout << endl << endl;
		break;
	}
	case 5:
	{
		cout << "\n\nВыберите действие: " << endl;
		cout << "1. Копирование. " << endl;
		cout << "2. Перемещение. " << endl;
		int moveAction;
		path sourcePath, destPath;
		cin >> moveAction;
		switch (moveAction)
		{
		case 1:
		{
			cout << "\n\nВведите путь до объекта копирования: " << endl;
			cin >> sourcePath;
			cout << "\n\nВведите путь куда скопировать объект: " << endl;
			cin >> destPath;
			obj.Copy(sourcePath.string(), destPath);
			cout << "Объект скопирован\n\n" << endl;
			system("pause");
			cout << endl << endl;
			break;
		}
		case 2:
		{
			cout << "\n\nВведите путь до объекта перемещения: " << endl;
			cin >> sourcePath;
			cout <<
				"\n\nВведите путь куда переместить объект (в конце введите название файла с расширением): "
				<< endl;
			cin >> destPath;
			obj.Move(sourcePath.string(), destPath);
			cout << "Объект перемещен\n\n" << endl;
			system("pause");
			cout << endl << endl;
			break;
		default:
			cout << "Неверный выбор действия" << endl;
		}
		}
		system("pause");
		cout << endl << endl;
		break;
	}
	case 6:
	{
		path sourcePath;
		cout << "\n\nВведите путь до объекта: " << endl;
		cin >> sourcePath;
		cout << "Размер объекта = " << obj.GetSize(sourcePath.string()) << " байт\n\n" << endl;
		system("pause");
		cout << endl << endl;
		break;
	}
	case 7:
	{
		path sourcePath;
		string name;
		cout << "\n\nВведите название объекта: " << endl;
		cin >> name;
		cout << "Введите директорию, где производить поиск: " << endl;
		cin >> sourcePath;
		for (auto pathses : obj.Search(name, sourcePath.string()))
			cout << "Путь до файла: " << pathses << endl;
		system("pause");
		cout << endl << endl;
		break;
	}
	case 8:
	{
		path cur_path = current_path();
		path par_path = cur_path.parent_path();
		current_path(par_path);
		break;
	}
	}
	return false;
}

void PrintMenu(int selectedOption)
{
	cout << "Программа File Manager" << endl;
	cout << "Выберите действие и нажмите ENTER:" << endl;
	cout << "\nТекущая директория: " << current_path() << endl << endl;

	vector<string> options = {
		"Перейти в другую директорию",
		"Показывать содержимое дисков",
		"Создавать папки / файлы",
		"Удалять папки / файлы",
		"Переименовывать папки / файлы",
		"Копировать / переносить папки / файлы",
		"Вычислять размер папки / файла",
		"Производить поиск по маске(с поиском по подпапкам)",
		"Переместиться в директорию выше.",
		"Выход." };

	for (int i = 0; i < options.size(); ++i)
	{
		if (i == selectedOption)
			cout << "> " << options[i] << " <" << endl;
		else
			cout << options[i] << endl;
	}
}
