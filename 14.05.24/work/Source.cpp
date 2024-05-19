#include <iostream>
#include <algorithm>
#include <string>
#include <span>

using namespace std;
/*
class Array
{
	int size;
	int* arr;

	static void FixSize(int& size)
	{
		if (size < 0)
			size = 0;
	}

	static int GetRandomValue(int startRange, int endRange)
	{
		return rand() % (endRange - startRange + 1) + startRange;
	}

public:
	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int size) : Array(size, 0)
	{
	}

	Array(int size, int value)
	{
		FixSize(size);

		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = value;
	}

	Array(int* arr, int size)
	{
		FixSize(size);

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

	int Size() const
	{
		return size;
	}

	int& At(const int index)
	{
		//size = 5; // no error
		return arr[index];
	}

	int At(const int index) const
	{
		//size = 5; // error
		return arr[index];
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Clear()
	{
		size = 0;

		if (arr != nullptr)
			delete[] arr;

		arr = nullptr;
	}

	void Resize(int size)
	{
		FixSize(size);

		int* newArr = size == 0 ? nullptr : new int[size];
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

		for (int i = 0; i < size; i++)
			arr[i] = GetRandomValue(startRange, endRange);
	}

	void Sort(bool desc = false)
	{
		if (IsEmpty())
			return;

		if (desc)
			sort(arr, arr + size, [](int& a, int& b) { return a > b; });
		else
			sort(arr, arr + size, [](int& a, int& b) { return a < b; });
	}

	void Swap(int firstIndex, int secondIndex)
	{
		swap(arr[firstIndex], arr[secondIndex]);
	}

	void Concatenate(const Array& other)
	{
		if (other.IsEmpty())
			return;

		int newSize = size + other.size;
		int* newArr = new int[newSize];
		for (int i = 0; i < size; i++)
			newArr[i] = arr[i];
		for (int i = 0; i < other.size; i++)
			newArr[size + i] = other.arr[i];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void Insert(int index, int value)
	{
		int newSize = size + 1;
		int* newArr = new int[newSize];
		for (int i = 0; i < index; i++)
			newArr[i] = arr[i];
		newArr[index] = value;
		for (int i = index; i < size; i++)
			newArr[i + 1] = arr[i];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void InsertFront(int value)
	{
		Insert(0, value);
	}

	void InsertBack(int value)
	{
		Insert(size, value);
	}

	void Remove(int index)
	{
		if (size <= 1)
		{
			Clear();
			return;
		}

		int newSize = size - 1;
		int* newArr = new int[newSize];
		for (int i = 0; i < index; i++)
			newArr[i] = arr[i];
		for (int i = index; i < newSize; i++)
			newArr[i] = arr[i + 1];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void RemoveFront()
	{
		Remove(0);
	}

	void RemoveBack()
	{
		Remove(size - 1);
	}

	void Replace(int oldValue, int newValue)
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == oldValue)
				arr[i] = newValue;
	}

	double GetAverage() const
	{
		if (IsEmpty())
			return 0;

		int sum = 0;
		for (int x : span(arr, arr + size))
			sum += x;

		return (double)sum / size;
	}

	int GetSum() const
	{
		int sum = 0;
		for (int x : span(arr, arr + size))
			sum += x;

		return sum;
	}

	int GetMin() const
	{
		if (IsEmpty())
			return 0;

		int min = arr[0];
		for (int x : span(arr, arr + size))
			if (x < min)
				min = x;

		return min;
	}

	int GetMax() const
	{
		if (IsEmpty())
			return 0;

		int max = arr[0];
		for (int x : span(arr, arr + size))
			if (x > max)
				max = x;

		return max;
	}

	int Find(int value) const
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == value)
				return i;

		return -1;
	}

	int FindLast(int value) const
	{
		for (int i = size - 1; i >= 0; i--)
			if (arr[i] == value)
				return i;

		return -1;
	}

	Array operator+(int value)
	{
		Array temp(*this);

		temp.Resize(temp.Size() + value);

		return temp;
	}

	Array operator+(const Array& other)
	{
		Array temp(*this);

		temp.Concatenate(other);

		return temp;
	}

	string ToString() const
	{
		return ToString(", ");
	}

	string ToString(string separator) const
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
	Array arr6(3, 999);


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

	cout << endl << "Is concatinate test" << endl;

	cout << "arr1 + arr2 = ";
	arr2.Concatenate(arr3);
	arr2.ToString();

	cout << endl << "Is clear test" << endl;
	arr6.Clear();
	cout << "arr6 = [" << arr6.ToString() << "] with size = " << arr6.Size() << endl;

	cout << endl << "Is swap test" << endl;
	arr4.Swap(1, 2);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is insert test" << endl;
	arr4.Insert(1, 6);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is insert front test" << endl;
	arr4.InsertFront(9);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is insert back test" << endl;
	arr4.InsertBack(9);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is remove test" << endl;
	arr4.Remove(1);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is remove front test" << endl;
	arr4.RemoveFront();
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is remove back test" << endl;
	arr4.RemoveBack();
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

	cout << endl << "Is replace back test" << endl;
	arr4.Replace(6, 8);
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;

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
	cout << "Is sum arr4 test = " << arr4.GetSum() << endl;

	cout << "arr2 with other separator = " << arr2.ToString(" # ") << endl;

	Array arr7 = arr3 + arr5;
	cout << "arr7 = [" << arr7.ToString() << "] with size = " << arr7.Size() << endl;
	Array arr8 = arr7 + 3;
	cout << "arr8 = [" << arr8.ToString() << "] with size = " << arr8.Size() << endl;



	system("pause");
}
*/

class Point
{
	int x;
	int y;

public:
	
	int GetX() { return x;	}
	void SetX(int value) { x = value; }

	int GetY() { return y; }
	void SetY(int value) { y = value; }

	Point(int a, int b)
	{
		x = a;
		y = b;
	}

	void Print()
	{
		cout << x << " " << y << endl;
	}

	// +
	Point operator+(const Point other) const
	{
		Point temp(*this);

		temp.x = x + other.x;
		temp.y = y + other.y;
		
		return temp;
	}
	Point operator+(const int value) const
	{
		Point temp(*this);

		temp.x = x + value;
		temp.y = y + value;

		return temp;
	}

	// -
	Point operator-(const Point other) const
	{
		Point temp(*this);

		temp.x = other.x - x;
		temp.y = other.y - y;

		return temp;
	}
	Point operator-(const int value) const
	{
		Point temp(*this);

		temp.x = x - value;
		temp.y = y - value;

		return temp;
	}

	// *
	Point operator*(const Point other) const
	{
		Point temp(*this);

		temp.x = other.x * x;
		temp.y = other.y * y;

		return temp;
	}
	Point operator*(const int value) const
	{
		Point temp(*this);

		temp.x = x * value;
		temp.y = y * value;

		return temp;
	}

	// /
	Point operator/(const Point other) const
	{
		//return Point(other.x / x, other.y / y);

		Point temp(*this);

		temp.x = other.x / x;
		temp.y = other.y / y;

		return temp;
	}
	Point operator/(const int value) const
	{
		Point temp(*this);

		temp.x = x / value;
		temp.y = y / value;

		return temp;
	}

	// ++
	Point operator++()
	{
		++x;
		++y;

		return (*this);
	}
	Point operator++(int)
	{
		Point temp(*this);

		x++;
		y++;

		return temp;
	}

	// --
	Point operator--()
	{
		--x;
		--y;

		return (*this);
	}
	Point operator--(int)
	{
		Point temp(*this);

		temp.x--;
		temp.y--;

		return temp;
	}
};

Point operator+(const int value, Point other) 
{
	Point temp(other);

	temp.SetX(other.GetX() + value);
	temp.SetY(other.GetY() + value);

	return temp;
}

Point operator-(const int value, Point other)
{
	Point temp(other);

	temp.SetX(other.GetX() - value);
	temp.SetY(other.GetY() - value);

	return temp;
}

Point operator*(const int value, Point other)
{
	Point temp(other);

	temp.SetX(other.GetX() * value);
	temp.SetY(other.GetY() * value);

	return temp;
}

Point operator/(const int value, Point other)
{
	Point temp(other);

	temp.SetX(other.GetX() / value);
	temp.SetY(other.GetY() / value);

	return temp;
}

void main()
{
	Point a(1, 2);
	Point b(1, 2);
	Point c = a + b;
	c.Print();
	++c;
	c.Print();
	c++;
	c.Print();
	c = c / b;
	c.Print();
	--c;
	c.Print();
	c--;
	c.Print();

	system("pause");
}