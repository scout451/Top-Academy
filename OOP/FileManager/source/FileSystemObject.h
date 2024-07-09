#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include <functional>
#include <map>

using namespace std;
using namespace std::filesystem;

class FileSystemObject
{
protected:
	path myPath;

public:
	path GetPath() { return myPath; }

	FileSystemObject(const path& p) : myPath(p)
	{
	}

	virtual long long GetSize() = 0;
	virtual void UpdateFromDisk() = 0;
};

class File : public FileSystemObject
{
public:
	File(const path& p) : FileSystemObject(p)
	{
	}

	long long GetSize() override
	{
		return file_size(GetPath());
	}

	void UpdateFromDisk() override
	{
	}
};

class Folder : public FileSystemObject
{
	vector<FileSystemObject*> contents;

public:
	Folder(const path& p) : FileSystemObject(p)
	{
	}

	long long GetSize() override
	{
		long long totalSize = 0;
		for (const auto dirEntry : recursive_directory_iterator(GetPath()))
			if (is_regular_file(dirEntry))
				totalSize += file_size(dirEntry);

		return totalSize;
	}


	void UpdateFromDisk() override
	{
		for (auto obj : contents)
			delete obj;
		contents.clear();

		for (const auto& entry : directory_iterator(GetPath()))
		{
			if (is_regular_file(entry))
				contents.push_back(new File(entry.path()));
			else if (is_directory(entry))
				contents.push_back(new Folder(entry.path()));
		}
	}

	const vector<FileSystemObject*>& GetContents() const
	{
		return contents;
	}
};