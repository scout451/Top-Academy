#pragma once
#include <filesystem>
#include "Menu.h"
#include "FileManager.h"

using namespace std;
using namespace std::filesystem;

bool RunMenu(int action)
{
<<<<<<< HEAD
	FileManager obj;
=======
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
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
<<<<<<< HEAD
		obj.ContentsOfTheDisks(sourcePath);
=======
		FileManager::ContentsOfTheDisks(sourcePath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		system("pause");
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
<<<<<<< HEAD
			obj.CreatingFile(sourcePath);
=======
			FileManager::CreatingFile(sourcePath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		}
		else
		{
			cout << "\n\nВведите название папки: " << endl;
			cin >> sourcePath;
<<<<<<< HEAD
			obj.CreatingFolder(sourcePath);
=======
			FileManager::CreatingFolder(sourcePath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		}
		cout << "Объект создан.\n\n" << endl;
		system("pause");
		break;
	}
	case 3:
	{
		path sourcePath;
		cout << "\n\nВведите путь до объекта удаления: " << endl;
		cin >> sourcePath;
<<<<<<< HEAD
		obj.Remove(sourcePath.string());
=======
		FileManager::Remove(sourcePath.string());
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		cout << "Объект удален.\n\n" << endl;
		system("pause");
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
<<<<<<< HEAD
		obj.Rename(sourcePath.string(), newFullPath);
=======
		FileManager::Rename(sourcePath.string(), newFullPath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		cout << "Объект переименован.\n\n" << endl;
		system("pause");
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
<<<<<<< HEAD
			obj.Copy(sourcePath.string(), destPath);
=======
			FileManager::Copy(sourcePath.string(), destPath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
			cout << "Объект скопирован\n\n" << endl;
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
<<<<<<< HEAD
			obj.Move(sourcePath.string(), destPath);
=======
			FileManager::Move(sourcePath.string(), destPath);
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
			cout << "Объект перемещен\n\n" << endl;
			break;
		default:
			cout << "Неверный выбор действия" << endl;
		}
		}
		system("pause");
		break;
	}
	case 6:
	{
		path sourcePath;
		cout << "\n\nВведите путь до объекта: " << endl;
		cin >> sourcePath;
<<<<<<< HEAD
		cout << "Размер объекта = " << obj.GetSize(sourcePath.string()) << " байт\n\n" << endl;
=======
		cout << "Размер объекта = " << FileManager::GetSize(sourcePath.string()) << " байт\n\n" << endl;
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
		system("pause");
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
<<<<<<< HEAD
		for (auto pathses : obj.Search(name, sourcePath.string()))
=======
		for (auto pathses : FileManager::Search(name, sourcePath.string()))
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
			cout << "Путь до файла: " << pathses << endl;
		system("pause");
		break;
	}
	case 8:
	{
		system("cls");
		break;
	}
	case 9:
	{
		path cur_path = current_path();
		path par_path = cur_path.parent_path();
		current_path(par_path);
		break;
	}
	}
	return false;
}

void PrintMenu()
{
	cout << "Программа File Manager" << endl;
	cout << "Выберите действие и нажмите цифру:" << endl;
	cout << "\nТекущая директория: " << current_path() << endl << endl;
	cout << "0. Перейти в другую директорию" << endl;
	cout << "1. Показывать содержимое дисков " << endl;
	cout << "2. Создавать папки / файлы " << endl;
	cout << "3. Удалять папки / файлы" << endl;
	cout << "4. Переименовывать папки / файлы" << endl;
	cout << "5. Копировать / переносить папки / файлы" << endl;
	cout << "6. Вычислять размер папки / файла" << endl;
	cout << "7. Производить поиск по маске(с поиском по подпапкам)" << endl;
	cout << "8. Очистить консоль" << endl;
	cout << "9. Переместиться в директорию выше." << endl;
}