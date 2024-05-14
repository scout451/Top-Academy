#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Array
{
	int* arr;
	int size;

public:
	Array() 
	{
		arr = nullptr;
	}

	Array(int size) 
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}

	Array(int size, int value) 
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = value;
	}

	Array(int* arr, int size) 
	{
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
			this->arr[i] = arr[i];
	}

	Array(const Array& other) 
	{
		size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

	~Array() 
	{
		if (arr != nullptr)
			delete[] arr;
		arr = nullptr;
	}

	int Size() 
	{
		arr = new int[size];
	}

	int& At(int index)
	{
		return arr[index];
	}

	void Resize(int size)
	{
		arr = new int[size];
		if (this->size < size)
			for (int i = this->size; i < size; i++)
				arr[i] = 0;
	}

	void Randomize(int startRange, int endRange)
	{
		for(int i = 0; i < size; i++)
			arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	//asc - возрастание
	//desc - убывание
	void Sort(bool desc = false) 
	{
		if(desc = false)
			sort(arr[0], arr[size]);
		if(desc = true)
			sort(arr[size], arr[0]);
	}

	int GetAverage() 
	{
		double sum = 0.0;
		for (int i = 0; i < size; i++)
			sum += arr[i];
		return sum / size;
	}

	int GetMin() 
	{
		int min = arr[0];
		for (int i = 0; i < size; i++)
			if (min < arr[i])
				min = arr[i];
		return min;
	}

	int GetMax()
	{
		int max = arr[0];
		for (int i = 0; i < size; i++)
			if (arr[i] > max)
				max = arr[i];
		return max;
	}

	string ToString() 
	{
		string arr[10];
		for (int i = 0; i < size; i++)
		{
			char j = this->arr[i];
			strcat_s(arr, sizeof(arr), j);
		}

	}

	string ToString(string separator) {}

};