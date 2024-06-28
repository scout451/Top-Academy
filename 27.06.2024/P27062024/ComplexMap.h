#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

template<typename TValue>
class ComplexMap
{
	class ValueType
	{
	public:
		virtual ~ValueType() = 0;
	};

	class SingleValueType : public ValueType
	{
	public:
		TValue value;

		SingleValueType() : SingleValueType(0) {}
		SingleValueType(TValue v) : value(v) {}
		~SingleValueType() {}
	};

	class ArrayValueType : public ValueType
	{
	public:
		TValue* array;
		int size;
		ArrayValueType() : ArrayValueType(nullptr) {}
		ArrayValueType(TValue* sourceArr, int size)
		{
			this->size = size;
			array = new TValue[size];
			for (int i = 0; i < size; i++)
				array[i] = sourceArr[i];
		}
		~ArrayValueType() { delete[] array; }
	};

	class StringValueType : public ValueType
	{
	public:
		char* str;

		StringValueType() : StringValueType(nullptr) {}
		StringValueType(const char* string)
		{
			int size = strlen(string) + 1;
			str = new char[size];
			for (int i = 0; i < size; i++)
				str[i] = string[i];
		}
		~StringValueType() { delete[] str; }
	};

	map<int, ValueType*> valuesMap;

public:
	ComplexMap() : ComplexMap(0, nullptr) {}
	ComplexMap(int key, ValueType* value)
	{
		/*auto err = valuesMap.insert(make_pair(key, value));
		if (err.second == false)*/
		/*if (valuesMap.find(key) != valuesMap.end())
			throw "\nError: Failed inserting.\n";

		valuesMap.insert(make_pair(key, value));*/
	}
	~ComplexMap() {}
	int GetSize() const
	{
		return valuesMap.size();
	}

	void AddValue(int key, TValue value)
	{
		ValueType* newValue = new SingleValueType(value);
		auto findResult = valuesMap.find(key);
		if (findResult != valuesMap.end())
			throw "\nError: Failed inserting.\n";

		valuesMap.insert(make_pair(key, newValue));
	}

	void AddArray(int key, TValue* values, int size)
	{
		auto newArr = new ArrayValueType(values, size);

		if (valuesMap.find(key) != valuesMap.end())
		{
			delete[] newArr;
			throw "\nError: Failed inserting.\n";
		}

		valuesMap.insert(make_pair(key, newArr));
	}

	void AddString(int key, const char* line)
	{
		StringValueType* newLine = new StringValueType(line);
		auto findResult = valuesMap.find(key);
		if (findResult != valuesMap.end())
		{
			delete[] newLine;
			throw "\nError: Failed inserting.\n";
		}

		valuesMap.insert(make_pair(key, newLine));
	}

	void AddValueOrReplace(int key, TValue value)
	{
		SingleValueType* newValue = new SingleValueType (value);
		auto findResult = valuesMap.find(key);
		if (findResult != valuesMap.end())
		{
			valuesMap.erase(findResult);
			valuesMap[key] = newValue;
		}
		else
			valuesMap[key] = newValue;
	}

	void AddArrayOrReplace(int key, TValue* values, int size)
	{
		auto newArr = new ArrayValueType(values, size);
		auto findResult = valuesMap.find(key);
		if (findResult != valuesMap.end())
		{
			valuesMap.erase(findResult);
			valuesMap[key] = newArr;
		}
		else
			valuesMap[key] = newArr;
	}

	void AddStringOrReplace(int key, const char* line)
	{
		StringValueType* newLine = new StringValueType(line);
		auto findResult = valuesMap.find(key);
		if (findResult != valuesMap.end())
		{
			valuesMap.erase(findResult);
			valuesMap[key] = newLine;
		}
		else
			valuesMap[key] = newLine;
	}

	TValue GetValue(int key)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			throw "\nError: Empty value.\n";

		SingleValueType* svt = dynamic_cast<SingleValueType*>(findResult->second);
		if (svt == nullptr)
			throw "\nError: Invalid value.\n";

		return svt->value;
	}

	TValue* GetArray(int key, int* size)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			throw "\nError: Empty value.\n";

		ArrayValueType* avt = dynamic_cast<ArrayValueType*>(findResult->second);
		if (avt == nullptr)
			throw "\nError: Invalid value.\n";
		*size = avt->size;
		return avt->array;
	}

	char* GetString(int key)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			throw "\nError: Empty value.\n";

		StringValueType* svt = dynamic_cast<StringValueType*>(findResult->second);
		if (svt == nullptr)
			throw "\nError: Invalid value.\n";

		return svt->str;
	}

	bool TryGetValue(int key, TValue* value)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			return false;

		SingleValueType* svt = dynamic_cast<SingleValueType*>(findResult->second);
		if (svt == nullptr)
			return false;

		*value = svt->value;
		return true;
	}

	bool TryGetArray(int key, TValue** values, int* size)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			return false;

		ArrayValueType* avt = dynamic_cast<ArrayValueType*>(findResult->second);
		if (avt == nullptr)
			return false;

		*size = avt->size;
		*values = avt->array;
		return true;
	}

	bool TryGetString(int key, char** line)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			return false;

		StringValueType* svt = dynamic_cast<StringValueType*>(findResult->second);
		if (svt == nullptr)
			return false;

		*line = svt->str;
		return true;
	}

	void Remove(int key)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			throw "\nError: Value not empty\n";
		delete findResult->second;
		valuesMap.erase(key);
	}

	bool TryRemove(int key)
	{
		auto findResult = valuesMap.find(key);
		if (findResult == valuesMap.end())
			return false;

		delete findResult->second;
		valuesMap.erase(key);
		return true;
	}

	void RemoveAll()
	{
		for_each(valuesMap.begin(), valuesMap.end(), [](pair<int, ValueType*> value) { delete value.second; });
		valuesMap.clear();
	}
};

template<typename TValue>
ComplexMap<TValue>::ValueType::~ValueType() {}