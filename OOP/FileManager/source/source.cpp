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

	static void CreatingFolder(const string& folder)
	{
		try
		{
			path FullPath = current_path() / folder;
			create_directories(FullPath);
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed creating folder: " << error.what() << endl;
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
			cout << "Failed creating file: " << error.what() << endl;
		}
	}

	static void Remove(const string& obj)
	{
		try
		{
			path FullPath = current_path() / obj;
			if (remove_all(FullPath)!= 1);
			{
				throw string("File not found");
			}
		}
		catch(const string& error)
		{
			cout << "Error removing: " << error << endl;
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
			cout << "Error renaming: " << error.what() << endl;
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
			cout << "Error copying: " << error.what() << endl;
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
			cout << "Error moving: " << error.what() << endl;
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
			cout << "Error getting size: " << error.what() << endl;
			return 0;
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
	cout << "��������� File Manager" << endl;
	cout << "�������� �������� � ������� �����:" << endl;
	cout << "\n������� ����������: " << current_path() << endl << endl;
	cout << "1. ���������� ���������� ������ " << endl;
	cout << "2. ��������� ����� / ����� " << endl;
	cout << "3. ������� ����� / �����" << endl;
	cout << "4. ��������������� ����� / �����" << endl;
	cout << "5. ���������� / ���������� ����� / �����" << endl;
	cout << "6. ��������� ������ ����� / �����" << endl;
	cout << "7. ����������� ����� �� �����(� ������� �� ���������)" << endl;
	cout << "8. �������� �������" << endl;
	cout << "9. ������������� � ���������� ����." << endl;
	cout << "0. �����" << endl;
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
			string sourcePath;
			cin >> createAction;
				if(createAction==1)
				{
					cout << "\n\n������� �������� �����: " << endl;
					cin >> sourcePath;
					FileManager::CreatingFile(sourcePath);
				}
				else
				{
					cout << "\n\n������� �������� �����: " << endl;
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
			cin >> sourcePath;
			FileManager::Remove(sourcePath.string());
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
			FileManager::Rename(sourcePath.string(), newFullPath);
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
				FileManager::Copy(sourcePath.string(), destPath);
				cout << "������ ����������\n\n" << endl;
				break;
				}
			case 2:
			{
				cout << "\n\n������� ���� �� ������� �����������: " << endl;
				cin >> sourcePath;
				cout << "\n\n������� ���� ���� ����������� ������ (� ����� ������� �������� ����� � �����������): " << endl;
				cin >> destPath;
				FileManager::Move(sourcePath.string(), destPath);
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
			cout << "������ ������� = " << FileManager::GetSize(sourcePath.string()) << " ����\n\n"  << endl;
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
			cin >> sourcePath;
			for (auto pathses : FileManager::Search(name, sourcePath.string()))
				cout << "���� �� �����: " << pathses << endl;
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
