#pragma once

#include "List.h"

template <class TValue>
class ArrayList : public List<TValue>
{
	int size;
	TValue* values;

public:
	ArrayList()
	{
		size = 0;
		values = nullptr;
	}

	ArrayList(const ArrayList<TValue>& other)
	{
		size = other.size;
		if (size == 0)
		{
			values = nullptr;
			return;
		}

		values = new TValue[size];
		for (int i = 0; i < size; i++)
			values[i] = other.values[i];
	}

	ArrayList(ArrayList<TValue>&& other)
	{
		size = other.size;
		values = other.values;
		other.size = 0;
		other.values = nullptr;
	}

	~ArrayList() override
	{
		if (values != nullptr)
			delete[] values;

		values = nullptr;
	}

	int GetSize() const override
	{
		return size;
	}

	bool IsEmpty() const override
	{
		return size == 0;
	}

	TValue GetFront() const override
	{
		if (IsEmpty())
			return 0;

		return values[0];
	}

	TValue GetBack() const override
	{
		if (IsEmpty())
			return 0;

		return values[size - 1];
	}

	void Add(const int index, const TValue& value) override
	{
		if (IsEmpty())
		{
			values = new TValue[++size]{ value };
			return;
		}

		TValue* newValues = new TValue[++size];
		for (int i = 0; i < index; i++)
			newValues[i] = values[i];
		newValues[index] = value;
		for (int i = index + 1; i < size; i++)
			newValues[i] = values[i - 1];

		delete[] values;
		values = newValues;
	}

	void AddToFront(const TValue& value) override
	{
		Add(0, value);
	}

	void AddToBack(const TValue& value) override
	{
		Add(size, value);
	}

	void Remove(const int index) override
	{
		if (size <= 1)
		{
			Clear();
			return;
		}

		TValue* newValues = new TValue[--size];
		for (int i = 0; i < index; i++)
			newValues[i] = values[i];
		for (int i = index; i < size; i++)
			newValues[i] = values[i + 1];

		delete[] values;
		values = newValues;
	}

	void RemoveFromFront() override
	{
		Remove(0);
	}

	void RemoveFromBack() override
	{
		Remove(size - 1);
	}

	void Clear() override
	{
		size = 0;
		if (values != nullptr)
			delete[] values;

		values = nullptr;
	}

	ArrayList& operator=(const ArrayList<TValue>& other)
	{
		if (this == &other)
			return *this;

		if (values != nullptr)
			delete[] values;

		size = other.size;
		if (size == 0)
		{
			values = nullptr;
			return *this;
		}

		values = new TValue[size];
		for (int i = 0; i < size; i++)
			values[i] = other.values[i];

		return *this;
	}

	ArrayList& operator=(ArrayList<TValue>&& other)
	{
		if (this == &other)
			return *this;

		if (values != nullptr)
			delete values;

		size = other.size;
		values = other.values;
		other.size = 0;
		other.values = nullptr;

		return *this;
	}

	TValue operator[](const int index) const override
	{
		return values[index];
	}

	TValue& operator[](const int index) override
	{
		return values[index];
	}
};
