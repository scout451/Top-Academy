#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <functional>
#include <iostream>
#include <map>
#include "FileSystemObject.h"

using namespace std;
using namespace std::filesystem;

class FileManager
{
<<<<<<< HEAD
	FileManager* obj;
=======
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	static map<string, Folder*> cache;

public:
	static Folder* GetFolder(const path& p)
	{
		string pathStr = p.string();
		if (!cache.contains(pathStr))
		{
			cache[pathStr] = new Folder(p);
			cache[pathStr]->UpdateFromDisk();
		}
		return cache[pathStr];
	}

<<<<<<< HEAD
	void ContentsOfTheDisks(const path& p)
=======
	static void ContentsOfTheDisks(const path& p)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			if (p == ".")
				Folder* folder = GetFolder(current_path());
			else
				Folder* folder = GetFolder(p);

			for (const auto& dir_entry : directory_iterator(p))
				cout << (is_directory(dir_entry) ? "[DIR] " : "[FILE] ") <<
					dir_entry.path().filename().string() << endl;
		}
		catch (const filesystem_error& error)
		{
			cout << "Failed reading contents: " << error.what() << endl;
		}
	}

<<<<<<< HEAD
	void InCache(path FullPath)
=======
	static void InCache(path FullPath)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		if (cache.contains(FullPath.parent_path().string()))
			cache[FullPath.parent_path().string()]->UpdateFromDisk();
	}

<<<<<<< HEAD
	void CreatingFolder(const string& folder)
=======
	static void CreatingFolder(const string& folder)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullPath = current_path() / folder;
			create_directories(FullPath);
			InCache(FullPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed creating folder: {}", folder);
		}
	}

<<<<<<< HEAD
	void CreatingFile(const string& file)
=======
	static void CreatingFile(const string& file)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullPath = current_path() / file;
			ofstream file(FullPath);
			InCache(FullPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed creating folder: {}", file);
		}
	}

<<<<<<< HEAD
	void Remove(const string& obj)
=======
	static void Remove(const string& obj)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullPath = current_path() / obj;
			if (remove_all(FullPath) != 1);
			InCache(FullPath);
		}
		catch (const string& error)
		{
			throw format("Failed removing: {}", obj);
		}
	}

<<<<<<< HEAD
	void Rename(const string& oldPath, const path& newPath)
=======
	static void Rename(const string& oldPath, const path& newPath)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullOldPath = current_path() / oldPath;
			rename(FullOldPath, newPath);
			InCache(FullOldPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed renaming object: {}", oldPath);
		}
	}

<<<<<<< HEAD
	void Copy(const string& source, const path& dest)
=======
	static void Copy(const string& source, const path& dest)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullSourcePath = current_path() / source;
			if (is_directory(FullSourcePath))
				copy(FullSourcePath, dest / source, copy_options::recursive);
			else
				copy(FullSourcePath, dest);
			InCache(dest);
			InCache(FullSourcePath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed copying: {}", source);
		}
	}

<<<<<<< HEAD
	void Move(const string& oldPath, const path& newPath)
=======
	static void Move(const string& oldPath, const path& newPath)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullOldPath = current_path() / oldPath;
			rename(FullOldPath, newPath / oldPath);
			InCache(FullOldPath);
			InCache(newPath);
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed moving: {}", oldPath);
		}
	}

<<<<<<< HEAD
	long long GetSize(const string& obj)
=======
	static long long GetSize(const string& obj)
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		try
		{
			path FullOldPath = current_path() / obj;
			if (is_directory(FullOldPath))
			{
				Folder folder(FullOldPath);
				return folder.GetSize();
			}
			File file(FullOldPath);
			return file.GetSize();
		}
		catch (const filesystem_error& error)
		{
			throw format("Failed getting size: {}", obj);
		}
	}

<<<<<<< HEAD
	vector<path> Search(const string& mask, const string& p = ".")
=======
	static vector<path> Search(const string& mask, const string& p = ".")
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		vector<path> matches;
		try
		{
			path FullOldPath = current_path() / p;
			for (const auto& dirEntry : recursive_directory_iterator(FullOldPath))
				try
				{
					if (dirEntry.path().filename().string().find(mask) != string::npos)
						matches.push_back(dirEntry);
				}
				catch (const filesystem_error& error)
				{
					throw format("Access denied to: {}", p);
				}
		}
		catch (const filesystem_error& error)
		{
			throw format("Error searching: {}", mask);
		}
		return matches;
	}

<<<<<<< HEAD
	void ClearCache()
=======
	static void ClearCache()
>>>>>>> bc2db5c30b916523681c0acf39342e9f6e472b48
	{
		for (auto& entry : cache)
			delete entry.second;
		cache.clear();
	}
};
map<string, Folder*> FileManager::cache;