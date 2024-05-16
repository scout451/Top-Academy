#include <iostream>
#include <algorithm>
#include <string>
#include <span>

using namespace std;

class Array
{
	int* arr;
	int size;

public:
	Array() 
	{
		size = 0;
		arr = nullptr;
	}

	Array(int size) : Array(size, 0)
	{
	}

	Array(int size, int value) 
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = value;
	}

	Array(int* arr, int size) 
	{
		this->size = size;
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
	}

	int Size() 
	{
		return size;
	}

	int& At(int index)
	{
		return arr[index];
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void Resize(int size)
	{
		int* newArr = new int[size];
		int minSize = min(this->size, size);
		for (int i = 0; i < minSize; i++)
			newArr[i] = arr[i];
		for (int i = minSize; i < size; i++)
			newArr[i] = 0;

		if (arr != nullptr)
			delete[] arr;

		this->size = size;
		arr = newArr;
	}

	void Randomize(int startRange, int endRange)
	{
		if (IsEmpty())
			return;
		
		for(int i = 0; i < size; i++)
			arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	//asc - возрастание
	//desc - убывание
	void Sort(bool desc = false) 
	{
		if (IsEmpty())
			return;

		if (desc)
			sort(arr, arr + size, [](int& a, int& b) { return a > b; });
		else
			sort(arr, arr + size, [](int& a, int& b) { return a < b; });
	}

	int GetAverage() 
	{
		if (IsEmpty())
			return 0;

		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += arr[i];

		return (double)sum / size;
	}

	int GetMin() 
	{
		if (IsEmpty())
			return 0;

		int min = arr[0];
		for (int i = 0; i < size; i++)
			if (arr[i] < min)
				min = arr[i];

		return min;
	}

	int GetMax()
	{
		if (IsEmpty())
			return 0;

		int max = arr[0];
		for (int i = 0; i < size; i++)
			if (arr[i] > max)
				max = arr[i];

		return max;
	}

	string ToString() 
	{
		return ToString(", ");
	}

	string ToString(string separator) 
	{
		if (IsEmpty())
			return "";

		string str = to_string(arr[0]);
		for (int x : span(arr + 1, arr + size))
			str += separator + to_string(x);

		return str;
	}
};

void main()
{
	int temp[] = { 1,2,3,4 };

	Array arr1;
	Array arr2(3);
	Array arr3(3, 999);
	Array arr4(temp, size(temp));
	Array arr5 = arr4;

	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;
	cout << "arr5 = [" << arr5.ToString() << "] with size = " << arr5.Size() << endl;

	cout << endl << "Set value test" << endl;

	arr2.At(1) = 123;
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;

	cout << endl << "Is empty test" << endl;

	cout << "arr1 is empty = " << arr1.IsEmpty() << endl;
	cout << "arr2 is empty = " << arr2.IsEmpty() << endl;
	cout << "arr3 is empty = " << arr3.IsEmpty() << endl;

	cout << endl << "Resize test" << endl;

	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
	arr2.Resize(2);
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
	arr2.Resize(4);
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;

	cout << endl << "Randomize test" << endl;

	arr2.Randomize(0, 9);
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;

	cout << endl << "Sort test" << endl;

	arr2.Sort();
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
	arr2.Sort(true);
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;

	cout << endl << "Other tests" << endl;

	cout << "arr2 = [" << arr2.ToString() << "] GetAverage = " << arr2.GetAverage() << endl;
	cout << "arr2 = [" << arr2.ToString() << "] GetMin = " << arr2.GetMin() << endl;
	cout << "arr2 = [" << arr2.ToString() << "] GetMax = " << arr2.GetMax() << endl;

	cout << "arr2 with other separator = " << arr2.ToString(" # ") << endl;

	system("pause");
}