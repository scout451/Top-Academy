#pragma once

#include "List.h"
#include <vector>

using namespace std;

template <class TValue>
class VectorList : public List<TValue>
{
	vector<TValue>* values;

public:
	VectorList()
	{
		values = new vector<TValue>();
	}

	VectorList(const VectorList<TValue>& other)
	{
		values = new vector<TValue>(*other.values);
	}

	VectorList(VectorList<TValue>&& other)
	{
		values = other.values;
		other.values = nullptr;
	}

	~VectorList() override
	{
		if (values != nullptr)
			delete values;

		values = nullptr;
	}

	int GetSize() const override
	{
		return (int)values->size();
	}

	bool IsEmpty() const override
	{
		return values->empty();
	}

	TValue GetFront() const override
	{
		if (IsEmpty())
			return 0;

		return values->front();
	}

	TValue GetBack() const override
	{
		if (IsEmpty())
			return 0;

		return values->back();
	}

	void Add(const int index, const TValue& value) override
	{
		values->insert(values->begin() + index, value);
	}

	void AddToFront(const TValue& value) override
	{
		values->insert(values->begin(), value);
	}

	void AddToBack(const TValue& value) override
	{
		values->push_back(value);
	}

	void Remove(const int index) override
	{
		values->erase(values->begin() + index);
	}

	void RemoveFromFront() override
	{
		values->erase(values->begin());
	}

	void RemoveFromBack() override
	{
		values->pop_back();
	}

	void Clear() override
	{
		values->clear();
	}

	VectorList& operator=(const VectorList<TValue>& other)
	{
		if (this == &other)
			return *this;

		if (values != nullptr)
			delete values;

		values = new vector<TValue>(*other.values);

		return *this;
	}

	VectorList& operator=(VectorList<TValue>&& other)
	{
		if (this == &other)
			return *this;

		if (values != nullptr)
			delete values;

		values = other.values;
		other.values = nullptr;

		return *this;
	}

	TValue operator[](const int index) const override
	{
		return (*values)[index];
	}

	TValue& operator[](const int index) override
	{
		return (*values)[index];
	}
};