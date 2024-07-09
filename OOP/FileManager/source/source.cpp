#include <string>
#include <filesystem>
#include <functional>
#include <iostream>
#include <Windows.h>
#include "Menu.h"

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
	static void ContentsOfTheDisks(const path& p = ".")
	{
		/*vector<path> contents;
		for (const auto& dir_entry : recursive_directory_iterator(p)) //������ � ������
			contents.push_back(dir_entry.path());*/

		try
		{
			for (const auto& dir_entry : recursive_directory_iterator(p)) //����� � �������
				cout << dir_entry << endl;
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed reading contents: " << error.what() << endl;
 		}
	}

	static void CreatingFolder(const path& p = ".")
	{
		try
		{
			create_directories(p);
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed creating folder: " << error.what() << endl;
		}
	}

	static void CreatingFile(const path& p)
	{
		try
		{
			ofstream file(p);
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed creating file: " << error.what() << endl;
		}
	}

	static void Remove(const path& p)
	{
		try
		{
			if (remove_all(p) != 1);
				throw string("File not found");
		}
		catch(const string& error)
		{
			cout << "Error removing: " << error << endl;
		}
	}

	static void Rename(const path& oldPath, const path& newPath)
	{
		try
		{
			rename(oldPath, newPath);
		}
		catch (const filesystem_error& error)
		{
			cout << "Error renaming: " << error.what() << endl;
		}
	}

	static void Copy(const path& source, const path& dest)
	{
		try
		{
			if (is_directory(source))
				copy(source, dest, copy_options::recursive);
			else
				copy(source, dest);
		}
		catch (const filesystem_error& error)
		{
			cout << "Error copying: " << error.what() << endl;
		}
	}

	static void Move(const path& oldPath, const path& newPath)
	{
		try
		{
			rename(oldPath, newPath);
		}
		catch (const filesystem_error& error)
		{
			cout << "Error moving: " << error.what() << endl;
		}
	}

	static long long GetSize(const path& p)
	{
		try
		{
			if (is_directory(p))
			{
				Folder folder(p);
				return folder.GetSize();
			}
			else
			{
				File file(p);
				return file.GetSize();
			}
		}
		catch (const filesystem_error& error)
		{
			cout << "Error getting size: " << error.what() << endl;
			return 0;
		}
	}

	static vector<path> Search(const string& mask, const path& p = ".")
	{
		vector<path> matches;
		try
		{
			for(const auto& dirEntry : recursive_directory_iterator(p))
				try
				{
				if (dirEntry.path().filename().string().find(mask) != string::npos)
					matches.push_back(dirEntry);
				}
				catch (const filesystem_error& error)
				{
					cout << "Access denied to: "<< dirEntry << error.what() << endl;
				}

		}
		catch (const filesystem_error& error)
		{
			cout << "Error searching: " << error.what() << endl;
		}
		return matches;
	}
};


void TestFileManager()
{
	FileManager A;
	
	path newFolder = "C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\newFolder";
	path newPath = "C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\oldFolder";
	path newFile = newFolder / "newFile.txt";
	path newNameFile = newPath / "File.txt";
	//A.ContentsOfTheDisks();
	A.CreatingFolder(newFolder);
	A.CreatingFile(newFile);
	//A.RemoveFile(newFile);
	//A.Rename(newFolder, newPath);
	//A.Rename(newPath / "newFile.txt", newNameFile);
	A.Copy(newFolder, ".\\copyingFolder");
	cout << A.GetSize("C:\\Reps\\Top-Academy\\OOP\\FileManager\\source\\source.cpp")<<endl;
	for (auto pathses : A.Search("qwerty.txt", "C:\\"))
		cout << pathses << endl;
	A.Remove(newFolder);
	A.Remove(".\\copyingFolder");
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//TestFileManager();
	int action;

	while (true)
	{
		cout << "��������� File Manager" << endl;
		cout << "�������� �������� � ������� �����:" << endl;
		cout << "1. ���������� ���������� ������ " << endl;
		cout << "2. ��������� ����� / ����� " << endl;
		cout << "3. ������� ����� / �����" << endl;
		cout << "4. ��������������� ����� / �����" << endl;
		cout << "5. ���������� / ���������� ����� / �����" << endl;
		cout << "6. ��������� ������ ����� / �����" << endl;
		cout << "7. ����������� ����� �� �����(� ������� �� ���������)" << endl;
		cout << "8. �������� �������" << endl;
		cout << "0. �����" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			{
			path sourcePath;
			cout << "\n\n������� ����: " << endl;
			cin >> sourcePath;
			FileManager::ContentsOfTheDisks(sourcePath);
			cout << "���������� ����� ���������� �������� � �������.\n\n" << endl;
			system("pause");
			break;
			}
		case 2:
			{
			cout << "\n\n�������� ��������: " << endl;
			cout << "1. ������� ����." << endl;
			cout << "2. ������� �����.\n" << endl;
			int createAction;
			path sourcePath;
			cin >> createAction;
				if(createAction==1)
				{
					cout << "\n\n������� ���� �������� �����, � ����� ���� �������� �������� �����: " << endl;
					cout << "�� ��������� �� ���������� � ���������� ����� ���������." << endl;
					cin >> sourcePath;
					FileManager::CreatingFile(sourcePath);
				}
				else
				{
					cout << "\n\n������� ���� �������� �����, � ����� ���� �������� �������� �����: " << endl;
					cout << "�� ��������� �� ���������� � ���������� ����� ���������." << endl;
					cin >> sourcePath;
					FileManager::CreatingFolder(sourcePath);
				}
				cout << "������ ������.\n\n" << endl;
			system("pause");
			break;
			}
		case 3:
		{
			path sourcePath;
			cout << "\n\n������� ���� �� ������� ��������: " << endl;
			cout << "�� ��������� �� ���������� � ���������� ����� ���������." << endl;
			cin >> sourcePath;
			FileManager::Remove(sourcePath);
			cout << "������ ������.\n\n" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			path sourcePath;
			path newName;
			cout << "\n\n������� ���� �� ������� ��������������: " << endl;
			cin >> sourcePath;
			cout << "\n\n������� ����� ���: " << endl;
			cin >> newName;
			path newFullPath = sourcePath.parent_path() / newName;
			FileManager::Rename(sourcePath, newFullPath);
			cout << "������ ������������.\n\n" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			cout << "\n\n�������� ��������: " << endl;
			cout << "1. �����������. " << endl;
			cout << "2. �����������. " << endl;
			int moveAction;
			path sourcePath, destPath;
			cin >> moveAction;
			switch (moveAction)
			{
			case 1:
				{
				cout << "\n\n������� ���� �� ������� �����������: " << endl;
				cin >> sourcePath;
				cout << "\n\n������� ���� ���� ����������� ������: " << endl;
				cin >> destPath;
				FileManager::Copy(sourcePath, destPath);
				cout << "������ ����������\n\n" << endl;
				break;
				}
			case 2:
			{
				cout << "\n\n������� ���� �� ������� �����������: " << endl;
				cin >> sourcePath;
				cout << "\n\n������� ���� ���� ����������� ������ (� ����� ������� �������� ����� � �����������): " << endl;
				cin >> destPath;
				FileManager::Move(sourcePath, destPath);
				cout << "������ ���������\n\n" << endl;
				break;
			default:
				cout << "�������� ����� ��������" << endl;
			}
			}
			system("pause");
			break;
		}
		case 6:
			{
			path sourcePath;
			cout << "\n\n������� ���� �� �������: " << endl;
			cin >> sourcePath;
			cout << "������ ������� = " << FileManager::GetSize(sourcePath) << " ����\n\n"  << endl;
			system("pause");
			break;
			}
		case 7:
		{
			path sourcePath;
			string name;
			cout << "\n\n������� �������� �������: " << endl;
			cin >> name;
			cout << "������� ����������, ��� ����������� �����: " << endl;
			cout << "�� ��������� �� ���������� � ���������� ����� ���������." << endl;
			cin >> sourcePath;
			for (auto pathses : FileManager::Search(name, sourcePath))
				cout << "���� �� �����: " << pathses << endl;
			system("pause");
			break;
		}
		case 8:
			system("cls");
			break;
		case 0:
			return;
		default:
			cout << "������� �������� ��������" << endl;
		}
		
	}
	system("pause");
}
