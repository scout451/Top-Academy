#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace std::filesystem;

class FileSystemObject
{
protected:
	path myPath;
public:
	path GetPath() { return myPath; }
	FileSystemObject(const path& p) : myPath(p) {}

	virtual long long GetSize() = 0;
};

class File : public FileSystemObject
{
public:
	File(const path& p) : FileSystemObject(p) {}

	long long GetSize() override
	{
		return file_size(GetPath());
	}
};

class Folder : public FileSystemObject
{
public:
	Folder(const path& p) : FileSystemObject(p) {}

	long long GetSize() override
	{
		long long totalSize = 0;
		for(const auto dirEntry : recursive_directory_iterator(GetPath()))
			if(is_regular_file(dirEntry))
				totalSize += file_size(dirEntry);

		return totalSize;
	}
};

class FileManager
{
public:
	static void ContentsOfTheDisks(const path& p = current_path())
	{
		try
		{
			if (exists(p) && is_directory(p))
				for (const auto& dir_entry : recursive_directory_iterator(p))
					cout << (is_directory(dir_entry) ? "[DIR] " : "[FILE] ") <<
					dir_entry.path().filename().string() << endl;
			else
				cout << "The path does not exist" << endl;
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed reading contents: " << error.what() << endl;
 		}
	}

	static void CreatingFolder(const string& folder)
	{
		try
		{
			path FullPath = current_path() / folder;
			create_directories(FullPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed creating folder: {}", folder);
		}
	}

	static void CreatingFile(const string& file)
	{
		try
		{
			path FullPath = current_path() / file;
			ofstream file(FullPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed creating folder: {}", file);
		}
	}

	static void Remove(const string& obj)
	{
		try
		{
			path FullPath = current_path() / obj;
			if (remove_all(FullPath)!= 1);
			{
				throw format("File not found: ", obj);
			}
		}
		catch(const string& error)
		{
			throw format("Failed removing: {}", obj);
		}
	}

	static void Rename(const string& oldPath, const path& newPath)
	{
		try
		{
			path FullOldPath = current_path() / oldPath;
			rename(FullOldPath, newPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed renaming object: {}", oldPath);
		}
	}

	static void Copy(const string& source, const path& dest)
	{
		try
		{
			path FullSourcePath = current_path() / source;
			if (is_directory(FullSourcePath))
				copy(FullSourcePath, dest / source, copy_options::recursive);
			else
				copy(FullSourcePath, dest);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed copying: {}", source);
		}
	}

	static void Move(const string& oldPath, const path& newPath)
	{
		try
		{
			path FullOldPath = current_path() / oldPath;
			rename(FullOldPath, newPath / oldPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed moving: {}", oldPath);
		}
	}

	static long long GetSize(const string& obj)
	{
		try
		{
			path FullOldPath = current_path() / obj;
			if (is_directory(FullOldPath))
			{
				Folder folder(FullOldPath);
				return folder.GetSize();
			}
			else
			{
				File file(FullOldPath);
				return file.GetSize();
			}
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed getting size: {}", obj);
		}
	}

	static vector<path> Search(const string& mask, const string& p = ".")
	{
		vector<path> matches;
		try
		{
			path FullOldPath = current_path() / p;
			for(const auto& dirEntry : recursive_directory_iterator(FullOldPath))
				try
				{
				if (dirEntry.path().filename().string().find(mask) != string::npos)
					matches.push_back(dirEntry);
				}
				catch (const filesystem_error& error)
				{
					throw format("Access denied to: ", p);
				}

		}
		catch (const filesystem_error& error)
		{
			throw format ("Error searching: ", mask);
		}
		return matches;
	}
};


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
//}

void PrintMenu()
{
	cout << "Программа File Manager" << endl;
	cout << "Выберите действие и нажмите цифру:" << endl;
	cout << "\nТекущая директория: " << current_path() << endl << endl;
	cout << "1. Показывать содержимое дисков " << endl;
	cout << "2. Создавать папки / файлы " << endl;
	cout << "3. Удалять папки / файлы" << endl;
	cout << "4. Переименовывать папки / файлы" << endl;
	cout << "5. Копировать / переносить папки / файлы" << endl;
	cout << "6. Вычислять размер папки / файла" << endl;
	cout << "7. Производить поиск по маске(с поиском по подпапкам)" << endl;
	cout << "8. Очистить консоль" << endl;
	cout << "9. Переместиться в директорию выше." << endl;
	cout << "0. Выход" << endl;
}

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
		switch (action)
		{
		case 1:
			{
			path sourcePath;
			cout << "\n\nВведите путь: " << endl;
			cin >> sourcePath;
			FileManager::ContentsOfTheDisks(sourcePath);
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
				if(createAction==1)
				{
					cout << "\n\nВведите название файла: " << endl;
					cin >> sourcePath;
					FileManager::CreatingFile(sourcePath);
				}
				else
				{
					cout << "\n\nВведите название папки: " << endl;
					cin >> sourcePath;
					FileManager::CreatingFolder(sourcePath);
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
			FileManager::Remove(sourcePath.string());
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
			FileManager::Rename(sourcePath.string(), newFullPath);
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
				FileManager::Copy(sourcePath.string(), destPath);
				cout << "Объект скопирован\n\n" << endl;
				break;
				}
			case 2:
			{
				cout << "\n\nВведите путь до объекта перемещения: " << endl;
				cin >> sourcePath;
				cout << "\n\nВведите путь куда переместить объект (в конце введите название файла с расширением): " << endl;
				cin >> destPath;
				FileManager::Move(sourcePath.string(), destPath);
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
			cout << "Размер объекта = " << FileManager::GetSize(sourcePath.string()) << " байт\n\n"  << endl;
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
			for (auto pathses : FileManager::Search(name, sourcePath.string()))
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
		case 0:
			return;
		}
	}
	system("pause");
}
